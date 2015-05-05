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
	dtree::dataset matrix(stream);

	std::cout << "Review the rules" << std::endl;
	std::cout << matrix << std::endl;

	dtree::dataset pos, neg;
	int idx = 4;
	std::cout << "Separate the dataset using feature \"" << idx << "\"" << std::endl;
	matrix.separate(idx, pos, neg);

	return EXIT_SUCCESS;
}

void showUsage(char *argv[])
{
	std::cout << "Usage: " << argv[0] << " filename" << " epsilon" << std::endl;
	std::exit(EXIT_FAILURE);
}