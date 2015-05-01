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

	std::vector<dtree::raw_entry> rules;
	std::string input;
	while (std::getline(stream, input))
	{
		rules.push_back(dtree::raw_entry(input));
	}

	std::cout << "Review the rules" << std::endl;
	for(dtree::raw_entry rule : rules)
	{
		std::cout << rule;
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

void showUsage(char *argv[])
{
	std::cout << "Usage: " << argv[0] << " filename" << " epsilon" << std::endl;
	std::exit(EXIT_FAILURE);
}