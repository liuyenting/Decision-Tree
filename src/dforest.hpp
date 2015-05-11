#ifndef DFOREST_H
#define DFOREST_H

#include <vector>

#include "dtree.hpp"

namespace dforest
{
	class if_forest
	{
		/*
		 * Data related private variables.
		 */
	private:
		dtree::dataset _data;
		int _tree_counts;

		/*
		 * Trees
		 */
	private:
		std::vector<dtree::if_tree*> _forest;

		/*
		 * Constructors
		 */
	public:
		if_forest(const dtree::dataset& data, const int& tree_counts)
			: _data(data), _tree_counts(tree_counts)
		{
		}

		~if_forest()
		{
			destroy_forest();
		}

	private:
		void destroy_forest()
		{
			for (auto& tree : _forest)
			{
				tree->destroy_tree();
			}
		}

	public:
		/*
		 * Regenerate the forest.
		 */
		void regenerate()
		{
			_forest.clear();
			_forest.reserve(_tree_counts);

			for (int i = 0; i < _tree_counts; i++)
			{
				dtree::if_tree* tmp_itree = new dtree::if_tree(_data.get_partial_data(3), 0);
				_forest.push_back(tmp_itree);
			}
		}

		/*
		 * Use the forest.
		 */
		void predict()
		{
			for (auto& t : _forest)
			{
				t->predict();
			}
		}

		/*
		 * Generate if-else statement.
		 */
	public:
		const std::string indent_character = "  ";
		void generate_file(std::ostream& stream)
		{
			stream << "#include <cstdlib>" << std::endl;
			stream << "#include <ctime>" << std::endl;

			// Generate the trees.
			for (int i = 0; i < _tree_counts; i++)
			{
				_forest[i]->generate_file(stream, (i + 1));
				stream << std::endl;
			}

			// Major forest body.
			stream << "int forest_predict(double *attr) {" << std::endl;
			stream << indent_character << "int votes = 0;" << std::endl;
			for (int i = 0; i < _tree_counts; i++)
			{
				stream << "tree" << (i + 1) << "_predict:" << std::endl;
				stream << indent_character << "votes += " << "tree" << (i + 1) << "_predict(attr);" << std::endl;
			}
			stream << "voting:" << std::endl;
			stream << indent_character << "if (votes > 0)" << std::endl;
			stream << indent_character << indent_character << "return 1;" << std::endl;
			stream << indent_character << "else if (votes < 0)" << std::endl;
			stream << indent_character << indent_character << "return -1;" << std::endl;
			stream << indent_character << "else {" << std::endl;
			stream << indent_character << indent_character << "std::srand(std::time(0));" << std::endl;
			stream << indent_character << indent_character << "return ((std::rand() % 2) ? 1 : -1);" << std::endl;
			stream << indent_character << '}' << std::endl;
			stream << '}' << std::endl;
		}
	};
}

#endif