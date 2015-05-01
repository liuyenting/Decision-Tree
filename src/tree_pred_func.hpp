#ifndef TREE_PRED_FUNC_H
#define TREE_PRED_FUNC_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

namespace dtree
{
	class lookup_matrix
	{

	};

	class raw_entry
	{
	protected:
		int label = 0;
		std::map<int, int> array;

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
					array.insert(std::make_pair(std::stoi(tmp[0]), std::stoi(tmp[1])));
				}
			}
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
			for (auto iterator = r.array.begin(); iterator != r.array.end(); ++iterator)
			{
				stream << iterator->first << '(' << iterator->second << ')' << ' ';
			}
			stream << " ]" << std::endl;
			return stream;
		}
	};

	class if_tree
	{
		struct node
		{
			int key_value;
			node *positive;
			node *negative;
		};

	private:
		node* root;

	public:
		if_tree()
		{
			root = NULL;
		}

		~if_tree()
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
				root-> positive = root->negative = NULL;
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

	class classification
	{
	private:
		if_tree structure;

	public:

	public:
		void generate_file(std::ofstream& stream)
		{

		}
	};
}

#endif