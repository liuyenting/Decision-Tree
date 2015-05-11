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
		dataset _data;
		int _tree_counts;

		/*
		 * Trees
		 */
	private:
		std::vector<dtree::if_tree> _forest;

		/*
		 * Constructors
		 */
	public:
		if_forest(const dataset& data, const int& tree_counts)
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
				tree.destroy_tree();
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

			for(int i = 0; i < _tree_counts; i++)
			{
				dtree::if_tree tmp_itree(matrix, 0);
			}
		}

		/*
		 * Use the forest.
		 */
		void predict()
		{

		}

		/*
		 * Generate if-else statement.
		 */
	public:
		void generate_file(std::ostream& stream)
		{
			stream << "int tree_predict(double *attr) {" << std::endl;
			generate_file(stream, _root, 1);
			stream << '}' << std::endl;
		}

	private:
	};
}

#endif