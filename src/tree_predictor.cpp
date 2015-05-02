#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "tree_pred_func.hpp"

void showUsage(char *argv[]);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		showUsage(argv);
	}

	std::cout << "Input from: \"" << argv[1] << "\"..." << std::endl;

	std::ifstream stream(argv[1]);
	dtree::confusion_matrix matrix(stream);
	dtree::if_tree prediction(matrix);

	std::cout << "Review the rules" << std::endl;
	std::cout << matrix << std::endl;

	return EXIT_SUCCESS;
}

void showUsage(char *argv[])
{
	std::cout << "Usage: " << argv[0] << " filename" << " epsilon" << std::endl;
	std::exit(EXIT_FAILURE);
}