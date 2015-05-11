#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "dforest.hpp"

void showUsage(char *argv[]);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		showUsage(argv);
	}

#ifdef DEBUG
	std::cerr << "Input from: \"" << argv[1] << "\"..." << std::endl;
#endif

	std::ifstream input(argv[1]);
	dtree::dataset matrix(input);

#ifdef DEBUG
	std::cerr << "Review the rules" << std::endl;
	std::cerr << matrix << std::endl;
#endif

	dforest::if_forest iforest(matrix, std::stoi(argv[2]));

	iforest.regenerate();
	iforest.predict();

#ifdef DEBUG
	std::cerr << ">>> Complete forest construction. <<<" << std::endl;
	std::cerr << std::endl;
#endif

#ifdef IMPLICITLY_TO_FILE
	std::ofstream output("forest_pred_func.cpp");
	iforest.generate_file(output);
	output.close();
#else
	iforest.generate_file(std::cout);
#endif

	return EXIT_SUCCESS;
}

void showUsage(char *argv[])
{
	std::cout << "Usage: " << argv[0] << " filename" << " trees" << std::endl;
	std::exit(EXIT_FAILURE);
}