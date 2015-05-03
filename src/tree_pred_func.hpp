#ifndef TREE_PRED_FUNC_H
#define TREE_PRED_FUNC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>

namespace dtree
{
	class raw_entry
	{
	protected:
		int label = 0;
		std::map<int, int> record;

		int min_index = 0, max_index = 0;

	public:
		raw_entry()
		{
		}

		raw_entry(std::string& input)
		{
			for (std::string element : split(input, ' '))
			{
				if (label == 0)
				{
					label = std::stoi(element);
				}
				else
				{
					std::vector<std::string> tmp = split(element, ':');
					int index = std::stoi(tmp[0]);
					record.insert(std::make_pair(index, std::stoi(tmp[1])));

					if (index < min_index)
					{
						min_index = index;
					}
					else if (index > max_index)
					{
						max_index = index;
					}
				}
			}
		}

	public:
		int get_label()
		{
			if (label == 0)
			{
				throw std::domain_error("get_label(): Undefined label found during the retrieval.");
			}
			return label;
		}

		const std::pair<int, int> get_index_range() const
		{
			return std::make_pair(min_index, max_index);
		}

		const int& operator[](int index) const
		{
			return record.at(index);
		}

	private:
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

		friend std::ostream& operator<<(std::ostream &stream, raw_entry& r)     //output
		{
			stream << r.label << " [ ";
			for (auto itr = r.record.begin(); itr != r.record.end(); ++itr)
			{
				stream << itr->first << '(' << itr->second << ')' << ' ';
			}
			stream << " ]" << std::endl;
			return stream;
		}
	};

	class confusion_matrix
	{
	public:
		std::vector<dtree::raw_entry> entries;
		std::map<int, std::vector<int> > thresholds;

		double confusion = 0.0;
		int positive_counts, negative_counts;
		int min_index, max_index;

	public:
		confusion_matrix()
		{
		}

		confusion_matrix(std::ifstream& stream)
		{
			std::string input;
			while (std::getline(stream, input))
			{
				entries.push_back(raw_entry(input));
			}
			update_thresholds();
		}

		confusion_matrix(std::vector<dtree::raw_entry> new_entries)
		{
			entries = new_entries;
			update_thresholds();
		}

	public:
		/*
		 * Get the confusion of currently stored entries.
		 */
		double get_confusion()
		{
			update_confusion();
			return confusion;
		}

		/* 
		 * Returns the index of the threshold value.
		 */
		int find_lowest_confusion(int index)
		{
			double lowest = 0.0;
			for (auto itr = thresholds.at(index).begin();
			        itr != thresholds.at(index).end();
			        ++itr)
			{
				std::vector<dtree::entries> positive_entries;
				std::vector<dtree::entries> negative_entries;
				separate(index, *itr, positive_entries, negative_entries);

				// Calculate the confusion and compare it with the lowest 
			}
		}

		/*
		 * Separate the entries into two parts, according to the lowest confusion upon the desired feature.
		 */
		void separate(int index, int threshold, std::vector<dtree::entries>& pos, std::vector<dtree:entries>& neg)
		{
			std::vector<dtree::raw_entry> tmp;
			for(auto itr = entries.begin(); itr != entries.end(); ++itr)
			{
				if((*itr)[index] >= threshold)
					pos.push_back(*itr);
				else
					neg.push_back(*itr);
			}
		}

	private:
		/*
		 * Update the threshold sequence of each features.
		 */
		void update_thresholds()
		{
			// Find out the range of indices in the matrix
			min_index = max_index = 0;
			for (auto itr = entries.begin(); itr != entries.end(); ++itr)
			{
				auto range = itr->get_index_range();
				if (range.first < min_index)
				{
					min_index = range.first;
				}
				else if (range.second > max_index)
				{
					max_index = range.second;
				}
			}

			// Finding the thresholds upon each index
			thresholds.clear();
			for (int idx = min_index; idx <= max_index; idx++)
			{
				// List all the unduplicate points
				std::set<int> pts;
				for (auto itr = entries.begin(); itr != entries.end(); ++itr)
				{
					pts.insert((*itr)[idx]);
				}

				// Calculate the midpoints
				std::vector<int> mids;
				for (auto itr = pts.begin(); ; ++itr)
				{
					int current = *itr;
					std::advance(itr, 1);
					if (itr == pts.end())
					{
						break;
					}
					else
					{
						mids.push_back((current + *itr) / 2);
					}
				}
			}
		}

		/*
		 * Calculate current confusion according to the labels.
		 */
		void update_confusion()
		{
			double totalentries = entries.size();
			positive_counts = negative_counts = 0;

			for (auto itr = entries.begin(); itr != entries.end(); ++itr)
			{
				if (itr->get_label() == 1)
				{
					positive_counts++;
				}
				else if (itr->get_label() == -1)
				{
					negative_counts++;
				}
			}

			confusion = 1 -
			            (positive_counts / totalentries) * (positive_counts / totalentries) -
			            (negative_counts / totalentries) * (negative_counts / totalentries);
		}

		friend std::ostream& operator<<(std::ostream &stream, confusion_matrix& m)     //output
		{
			for (dtree::raw_entry r : m.entries)
			{
				stream << r;
			}

			return stream;
		}
	};

	class if_tree_template
	{
		struct node
		{
			int key_value;

			//
			// entry[index] > threshold
			// entry[index] < threshold
			// No equal should exist.
			//
			int index, threshold;
			node *positive;
			node *negative;
		};

	private:
		node* root;

	public:
		if_tree_template()
		{
			root = NULL;
		}

		~if_tree_template()
		{
			destroy_tree();
		}

		void insert(int key)
		{
			if (root != NULL)
			{
				insert(key, root);
			}
			else
			{
				root = new node;
				root->key_value = key;
				root->positive = root->negative = NULL;
			}
		}

		node* search(int key)
		{
			return search(key, root);
		}

		void destroy_tree()
		{
			destroy_tree(root);
		}

	private:
		void destroy_tree(node* leaf)
		{
			if (leaf != NULL)
			{
				destroy_tree(leaf->positive);
				destroy_tree(leaf->negative);
				delete leaf;
			}
		}

		void insert(int key, node* leaf)
		{
			if (key < leaf->key_value)
			{
				if (leaf->positive != NULL)
				{
					insert(key, leaf->positive);
				}
				else
				{
					leaf->positive = new node;
					leaf->positive->key_value = key;

					// Set the child nodes to null
					leaf->positive->positive = leaf->positive->negative = NULL;
				}
			}
			else if (key >= leaf->key_value)
			{
				if (leaf->negative != NULL)
				{
					insert(key, leaf->negative);
				}
				else
				{
					leaf->negative = new node;
					leaf->negative->key_value = key;
					leaf->negative->positive = leaf->negative->negative = NULL;
				}
			}
		}

		node* search(int key, node* leaf)
		{
			if (leaf != NULL)
			{
				if (key == leaf->key_value)
				{
					return leaf;
				}
				if (key < leaf->key_value)
				{
					return search(key, leaf->positive);
				}
				else
				{
					return search(key, leaf->negative);
				}
			}
			else
			{
				return NULL;
			}
		}
	};

	class if_tree
	{
		/*
		 * entry[index] >= threshold
		 * When positive and negative are NULL, 'threshold' holds the final decision.
		 */
		struct node
		{
			int index, threshold;
			node *positive;
			node *negative;
		};

	private:
		node* root, current;
		double epsilon = -1;

	protected:
		confusion_matrix matrix;

	public:
		if_tree(confusion_matrix new_matrix)
		{
			matrix = new_matrix;
			root = NULL;

			predict();
		}

		if_tree(std::ifstream& stream)
		{
			matrix = confusion_matrix(stream);
			root = NULL;

			predict();
		}

		~if_tree()
		{
			destroy_tree();
		}

		void set_epsilon(double new_epsilon)
		{
			epsilon = new_epsilon;
		}

	public:
		void predict()
		{
			if (epsilon < 0)
			{
				throw std::underflow_error("predict(): Epsilon should be greater than 0.");
			}
			else if (epsilon > 1)
			{
				throw std::overflow_error("predict(): Epsilon should range between 0 and 1 only.");
			}

			if (matrix.get_confusion() <= epsilon)
			{
				// Build and return a leaf node with the associated final decision
				current = new node;
				current->threshold = ;// Final state
				current->positive = current->negative = NULL;
			}
			else
			{
				// Cycle through the features
				for (int idx = matrix.)
				}
		}

		void generate_file(std::string path)
		{
			std::ofstream stream(path + "tree_pred_func.cpp", std::ios::out);

			stream << "int tree_predict(double *attr) {" << std::endl;
			// TODO: Call generate_file(node* leaf) to recursively generate the if-else statements.
			stream << "}" << std::endl;
		}

		void destroy_tree()
		{
			destroy_tree(root);
		}

	private:
		void destroy_tree(node* leaf)
		{
			if (leaf != NULL)
			{
				destroy_tree(leaf->positive);
				destroy_tree(leaf->negative);
				delete leaf;
			}
		}

		void generate_file(node *leaf)
		{
		}
	};
}

#endif
