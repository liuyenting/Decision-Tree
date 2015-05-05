#ifndef TREE_PRED_FUNC_H
#define TREE_PRED_FUNC_H

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

	private:
		std::vector<entry> _data;
		double confusion;

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
					// Set the l
					new_entry.conclusion = std::stoi(element);
				}
				else
				{
					auto tmp = split(element, ':');
					new_entry.features.insert(std::make_pair(std::stoi(tmp[0]), std::stoi(tmp[1])));
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

		/*
		 * Branching operations and corresponding support functions.
		 */
	public:
		bool can_branch()
		{
			if (_data.size() > 1)
			{
				return true;
			}
		}

		/*
		 * Separate the dataset into two according to the lowest confusion value in designated feature.
		 */
		void separate(int feature_index, dataset& pos, dataset& neg)
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
				}
			}

			if(values.size() == 0)
			{
				throw std::out_of_range("separate(): Feature index out-of-range.");
				std::exit(EXIT_FAILURE);
			}

			std::set<double> thresholds;
			for (auto itr = values.begin(); ;)
			{
				double a = *itr, b;
				if (++itr == values.end())
				{
					break;
				}
				else
				{
					b = *itr;
					thresholds.insert((a + b) / ((double)2));
				}
			}

			std::cout << "print out the thresholds" << std::endl;
			for (auto t : thresholds)
			{
				std::cout << "->" << t << std::endl;
			}
		}

		/*
		 * Operator overloads.
		 */
	public:
		/*
		 * Output stream
		 */
		friend std::ostream& operator<<(std::ostream& stream, dataset& d)
		{
			std::cout << "confusion = " << std::fixed << std::setprecision(6) << d.confusion << std::endl;
			for (auto itr = d._data.begin(); itr != d._data.end(); ++itr)
			{
				stream << itr->conclusion << " [ ";
				for (auto itr2 = itr->features.begin(); itr2 != itr->features.end(); ++itr2)
				{
					stream << itr2->first << '(' << itr2->second << ')' << ' ';
				}
				stream << " ]" << std::endl;
			}
			return stream;
		}

		/*
		 * Epsilon comparator, <=
		 */
		bool operator<=(const double& epsilon)
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

			return *this;
		}
		// dataset to dataset
		dataset& operator=(const dataset& rhs)
		{
			_data = rhs._data;
			confusion = rhs.confusion;

			return *this;
		}
	};
}


#endif
