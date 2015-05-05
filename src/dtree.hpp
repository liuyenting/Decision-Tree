#ifndef DTREE_H
#define DTREE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <limits>

namespace dtree
{
	class dataset
	{
		/*
		 * ((feature, data), conclusion)
		 */
		struct entry
		{
			std::map<int, int> features;
			int conclusion;

			entry() : conclusion(0)
			{
			}
		};

		struct range
		{
			int min, max;

			range()
			{
				reset();
			}

			void reset()
			{
				min = std::numeric_limits<int>::max();
				max = std::numeric_limits<int>::min();
			}
		};

	private:
		std::vector<entry> _data;
		double confusion;
		range _feature_range;
		/*
		 * Constructors
		 */
	public:
		dataset()
		{
		}

		dataset(std::ifstream& input)
		{
			std::string tmp;
			while (std::getline(input, tmp))
			{
				_data.push_back(libsvm_parser(tmp));
			}
			update_confusion();
		}

		/*
		 * Parser for LIBSVM format, and its helper functions.
		 */
	private:
		entry libsvm_parser(std::string& input)
		{
			entry new_entry;
			for (std::string element : split(input, ' '))
			{
				if (new_entry.conclusion == 0)
				{
					new_entry.conclusion = std::stoi(element);
				}
				else
				{
					auto tmp = split(element, ':');
					int feature_index = std::stoi(tmp[0]);
					new_entry.features.insert(std::make_pair(feature_index, std::stoi(tmp[1])));

					if (feature_index > _feature_range.max)
					{
						_feature_range.max = feature_index;
					}
					else if (feature_index < _feature_range.min)
					{
						_feature_range.min = feature_index;
					}
				}
			}
			return new_entry;
		}

		std::vector<std::string>& split(const std::string &input, char delim, std::vector<std::string>& elements)
		{
			std::stringstream stream(input);
			std::string item;
			while (std::getline(stream, item, delim))
			{
				elements.push_back(item);
			}
			return elements;
		}

		std::vector<std::string> split(const std::string& input, char delim)
		{
			std::vector<std::string> elements;
			split(input, delim, elements);
			return elements;
		}

		/*
		 * Confusion related operations for current dataset.
		 */
	private:
		void update_confusion()
		{
			// Reset the confusion
			confusion = 1;

			int pos_counts = 0, neg_counts = 0;
			for (const auto& entry : _data)
			{
				if (entry.conclusion > 0)
				{
					pos_counts++;
				}
				else if (entry.conclusion < 0)
				{
					neg_counts++;
				}
				else
				{
					throw std::domain_error("update_confusion(): Undefined conclusion found during the refresh.");
					std::exit(EXIT_FAILURE);
				}
			}

			confusion -= std::pow((pos_counts / (double)_data.size()), 2) + std::pow((neg_counts / (double)_data.size()), 2);
		}

		// > threshold
		double positive_confusion(int index, int threshold, int& counter) const
		{
			counter = 0;

			int pos_counts = 0, neg_counts = 0;
			for (const auto& entry : _data)
			{
				try
				{
					if (entry.features.at(index) > threshold)
					{
						counter++;

						if (entry.conclusion > 0)
						{
							pos_counts++;
						}
						else if (entry.conclusion < 0)
						{
							neg_counts++;
						}
						else
						{
							throw std::domain_error("positive_confusion(): Undefined conclusion found during the refresh.");
							std::exit(EXIT_FAILURE);
						}
					}
				}
				catch (std::out_of_range e)
				{
					throw std::out_of_range("positive_confusion(): Invalid feature index.");
					std::exit(EXIT_FAILURE);
				}
			}

			return (1 - std::pow((pos_counts / (double)_data.size()), 2) - std::pow((neg_counts / (double)_data.size()), 2));
		}

		// < threshold
		double negative_confusion(int index, int threshold, int& counter) const
		{
			counter = 0;

			int pos_counts = 0, neg_counts = 0;
			for (const auto& entry : _data)
			{
				try
				{
					if (entry.features.at(index) < threshold)
					{
						counter++;

						if (entry.conclusion > 0)
						{
							pos_counts++;
						}
						else if (entry.conclusion < 0)
						{
							neg_counts++;
						}
						else
						{
							throw std::domain_error("negative_confusion(): Undefined conclusion found during the refresh.");
							std::exit(EXIT_FAILURE);
						}
					}
				}
				catch (std::out_of_range e)
				{
					throw std::out_of_range("negative_confusion(): Invalid feature index.");
					std::exit(EXIT_FAILURE);
				}
			}

			return (1 - std::pow((pos_counts / (double)_data.size()), 2) - std::pow((neg_counts / (double)_data.size()), 2));
		}

		/*
		 * Branching operations and corresponding support functions.
		 */
	public:
		bool can_branch() const
		{
			if (_data.size() > 1)
			{
				// OOR-patch
				int tmp = 0;
				for (const auto& entry : _data)
				{
					if (tmp == 0)
					{
						tmp = entry.conclusion;
					}
					else if (entry.conclusion != tmp)
					{
						return true;
					}
				}
				return false;
			}
			else
			{
				return false;
			}
		}

		double get_confusion() const
		{
			return confusion;
		}

		/*
		 * Separate the dataset into two according to the lowest confusion value in designated feature.
		 */
	public:
		/*
		 * Parameter: target index
		 * Return: separate at which threshold
		 */
		double separate(int feature_index, dataset& pos, dataset& neg)
		{
			double target_threshold;
			find_least_confusion(feature_index, target_threshold);

			separate(feature_index, target_threshold, pos, neg);

			return target_threshold;
		}

		/*
		 * Confusion related operations for current dataset.
		 */
	public:
		range get_feature_range() const
		{
			return _feature_range;
		}

		void update_feature_range()
		{
			_feature_range.reset();

			for (const auto& entry : _data)
			{
				if (entry.features.begin()->first < _feature_range.min)
				{
					_feature_range.min = entry.features.begin()->first;
				}
				else if (entry.features.end()->first > _feature_range.max)
				{
					_feature_range.max = entry.features.end()->first;
				}
			}
		}

	private:
		/*
		 * Parameter: target index, separate at which threshold
		 * Return: None
		 */
		void separate(int feature_index, double threshold, dataset& pos, dataset& neg)
		{
			std::vector<entry> pos_container, neg_container;

			for (const auto& entry : _data)
			{
				try
				{
					if (entry.features.at(feature_index) > threshold)
					{
						pos_container.push_back(entry);
					}
					else
					{
						neg_container.push_back(entry);
					}
				}
				catch (std::out_of_range e)
				{
					throw std::out_of_range("separate(): Invalid feature index.");
					std::exit(EXIT_FAILURE);
				}
			}

			pos = pos_container;
			neg = neg_container;
		}

	public:
		/*
		 * Parameter: target index
		 * Return: lowest confusion, the threshold that creates lowest confusion
		 */
		double find_least_confusion(int feature_index, double& target_threshold) const
		{
			std::set<int> values;
			for (const auto& e : _data)
			{
				try
				{
					values.insert(e.features.at(feature_index));
				}
				catch (std::out_of_range e)
				{
					/*
					throw std::out_of_range("find_least_confusion(): Invalid feature index.");
					std::exit(EXIT_FAILURE);
					*/
					// oor-patch
					std::cerr << "find_least_confusion(): Invalid feature index. Using 0 instead." << std::endl;
					values.insert(0);
				}
			}

			if (values.size() == 0)
			{
				throw std::runtime_error("find_least_confusion(): No values in the set to build the threshold table.");
				std::exit(EXIT_FAILURE);
			}

			std::set<double> thresholds;
			for (auto itr = values.begin(); ;)
			{
				double a = *itr, b;
				if (++itr == values.end())
				{
					// oor-patch
					if (a == 0)
					{
						thresholds.insert(0);
					}
					break;
				}
				else
				{
					b = *itr;
					thresholds.insert((a + b) / ((double)2));
				}
			}

			double least_confusion = 1;
			for (const auto& t : thresholds)
			{
				int positive_count, negative_count;
				double pos = positive_confusion(feature_index, t, positive_count);
				double neg = negative_confusion(feature_index, t, negative_count);

				double tmp = (pos * positive_count + neg * negative_count) / _data.size();

				if (tmp < least_confusion)
				{
					least_confusion = tmp;
					target_threshold = t;
				}
			}

			return least_confusion;
		}

		/*
		 * Operator overloads.
		 */
	public:
		/*
		 * Output stream
		 */
		friend std::ostream& operator<<(std::ostream & stream, dataset & d)
		{
			std::cout << "confusion = " << std::fixed << std::setprecision(6) << d.confusion;
			for (auto itr = d._data.begin(); itr != d._data.end(); ++itr)
			{
				stream << std::endl;
				stream << itr->conclusion << " [ ";
				for (auto itr2 = itr->features.begin(); itr2 != itr->features.end(); ++itr2)
				{
					stream << itr2->first << '(' << itr2->second << ')' << ' ';
				}
				stream << " ]";
			}
			return stream;
		}

		/*
		 * Epsilon comparator, <=
		 */
		bool operator<=(const double & epsilon)
		{
			return confusion <= epsilon;
		}

		/*
		 * Assignmnet operator, =
		 */
		// container(vector) to dataset
		dataset& operator=(const std::vector<entry>& rhs)
		{
			_data = rhs;
			update_confusion();
			update_feature_range();

			return *this;
		}
		// dataset to dataset
		dataset& operator=(const dataset & rhs)
		{
			_data = rhs._data;
			confusion = rhs.confusion;
			_feature_range = rhs._feature_range;

			return *this;
		}

		/*
		 * Index operator, acquiring the conclusion for specified entry
		 */
		int operator[](const int& index) const
		{
			try
			{
				return _data.at(index).conclusion;
			}
			catch (std::exception e)
			{
				throw std::out_of_range("operator[]: Feature index out-of-bound.");
				std::exit(EXIT_FAILURE);
			}
		}
	};

	class if_tree
	{
		struct node
		{
			int feature_index, conclusion;
			double threshold;
			node* positive_child;
			node* negative_child;
		};

		/*
		 * Data related private variables.
		 */
	private:
		dataset _data;
		double _epsilon;

		/*
		 * Tree related private variables.
		 */
	private:
		node* root;

		/*
		 * Constructors and destructors
		 */
	public:
		if_tree(const dataset& data, const double& epsilon)
			: _data(data), _epsilon(epsilon)
		{
		}

		~if_tree()
		{
			destroy_tree();
		}

		/*
		 * Access variable
		 */
	public:
		void set_epsilon(const double& epsilon)
		{
			_epsilon = epsilon;
		}

		void set_dataset(const dataset& data)
		{
			_data = data;
		}

		/*
		 * Prediction function and its helper functions.
		 */
	public:
		void predict()
		{
			root = predict(_data);
		}

	private:
		node* predict(dataset& data)
		{
			node* current = new node;

			if ((data.get_confusion() <= _epsilon) && !data.can_branch())
			{
				current->conclusion = data[0];
				current->positive_child = current->negative_child = NULL;
			}
			else
			{
				auto range = data.get_feature_range();
				double least_confusion = 1, target_threshold = -1;
				int target_index = -1;

				std::cout << "********************" << std::endl;
				std::cout << "range=[" << range.min << ", " << range.max << "]" << std::endl;
				std::cout << std::endl;

				for (int i = range.min; i <= range.max; i++)
				{
					double tmp_threshold;
					double tmp_confusion = data.find_least_confusion(i, tmp_threshold);
					if (tmp_confusion < least_confusion)
					{
						std::cout << "new low!" << std::endl;
						least_confusion = tmp_confusion;

						target_index = i;
						target_threshold = tmp_threshold;
					}
				}

				std::cout << "Separate the dataset using feature \"" << target_index << "\"" << std::endl;

				current->feature_index = target_index;

				dataset pos, neg;
				data.separate(target_index, pos, neg);

				std::cout << "Least confusion=" << least_confusion << " at threshold=" << target_threshold << std::endl;
				std::cout << std::endl;

				current->threshold = target_threshold;

				std::cout << "Review the positive dataset" << std::endl;
				std::cout << pos << std::endl;
				std::cout << "Review the negative dataset" << std::endl;
				std::cout << neg << std::endl;
				std::cout << "********************" << std::endl;

				current->positive_child = predict(pos);
				current->negative_child = predict(neg);
			}

			return current;
		}

		/*
		 * Tree destoryer and its helper function.
		 */
	public:
		void destroy_tree()
		{
			destroy_tree(root);
		}

	private:
		void destroy_tree(node* leaf)
		{
			if (leaf != NULL)
			{
				destroy_tree(leaf->positive_child);
				destroy_tree(leaf->negative_child);
				delete leaf;
			}
		}

		/*
		 * Generate if-else statement.
		 */
	public:
		void generate_file(std::ofstream& stream)
		{
			stream << "int tree_predict(double *attr) {" << std::endl;
			generate_file(stream, root, 1);
			stream << '}' << std::endl;
		}

	private:

#define INDENT "  "
		void generate_file(std::ofstream& stream, node* leaf, int indent)
		{
			if ((leaf->positive_child == NULL) && (leaf->negative_child == NULL))
			{
				for (int i = 0; i < indent; i++)
				{
					stream << INDENT;
				}
				stream << "return " << leaf->conclusion << ';' << std::endl;

				return;
			}
			else
			{
				for (int i = 0; i < indent; i++)
				{
					stream << INDENT;
				}
				stream << "if(attr[" << leaf->feature_index << "] > " << leaf->threshold << ") {" << std::endl;
				if (leaf->positive_child != NULL)
				{
					generate_file(stream, leaf->positive_child, indent + 1);
				}
				for (int i = 0; i < indent; i++)
				{
					stream << INDENT;
				}
				stream << "} else {" << std::endl;
				generate_file(stream, leaf->negative_child, indent + 1);
				for (int i = 0; i < indent; i++)
				{
					stream << INDENT;
				}
				stream << '}' << std::endl;
			}
		}
	};
}


#endif
