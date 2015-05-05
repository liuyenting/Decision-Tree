#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "dtree.hpp"

void showUsage(char *argv[]);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		showUsage(argv);
	}

	std::cout << "Input from: \"" << argv[1] << "\"..." << std::endl;

	std::ifstream input(argv[1]);
	dtree::dataset matrix(input);

	std::cout << "Review the rules" << std::endl;
	std::cout << matrix << std::endl;

	dtree::if_tree itree(matrix, std::stoi(argv[2]));
	itree.predict();

	std::ofstream output("tree_pred_func.cpp");
	itree.generate_file(output);
	output.close();

	return EXIT_SUCCESS;
}

void showUsage(char *argv[])
{
	std::cout << "Usage: " << argv[0] << " filename" << " epsilon" << std::endl;
	std::exit(EXIT_FAILURE);
}