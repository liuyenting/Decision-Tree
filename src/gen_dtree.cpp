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

	std::cerr << "Input from: \"" << argv[1] << "\"..." << std::endl;

	std::ifstream input(argv[1]);
	dtree::dataset matrix(input);

	std::cerr << "Review the rules" << std::endl;
	std::cerr << matrix << std::endl;

	dtree::if_tree itree(matrix, std::stoi(argv[2]));
	itree.predict();

	std::cerr << ">>> Complete tree construction. <<<" << std::endl;
	std::cerr << std::endl;

#ifdef IMPLICITLY_TO_FILE
	std::ofstream output("tree_pred_func.cpp");
	itree.generate_file(output);
	output.close();
#else
	itree.generate_file(std::cout);
#endif

	return EXIT_SUCCESS;
}

void showUsage(char *argv[])
{
	std::cout << "Usage: " << argv[0] << " filename" << " epsilon" << std::endl;
	std::exit(EXIT_FAILURE);
}