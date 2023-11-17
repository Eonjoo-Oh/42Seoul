#include <fstream>
#include <iostream>

void	rewrite(std::string& line, std::string oldWord, std::string newWord)
{
	size_t position;
	
	position = line.find(oldWord);
	while (position != std::string::npos)
	{
		line = line.substr(0, position) + newWord + line.substr(position + oldWord.length());
		position = line.find(oldWord);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Check the number of argument" << std::endl;
		return (1);
	}

	std::ifstream	inputFile(argv[1]);
	std::string		inputFileName = argv[1];
	std::string		oldWord = argv[2];
	std::string		newWord = argv[3];
	std::string		line;

	if (!inputFile.is_open())
	{
		std::cerr << "The file does not exist" << std::endl;
		return (1);
	}
	std::string tempFileName = inputFileName + "_temp.txt";
	std::ofstream	tempFile(tempFileName);
	if (!tempFile.is_open())
	{
		std::cerr << "The file does not exist" << std::endl;
		return (1);
	}

	while (std::getline(inputFile, line))
	{
		rewrite(line, oldWord, newWord);
		tempFile << line << std::endl;
	}
	if (std::remove(argv[1]) != 0)
	{
		std::cerr << "remove Error" << std::endl;
		return (1);
	}
	if (std::rename(tempFileName.c_str(), argv[1]) != 0)
	{
		std::cerr << "rename Error" << std::endl;
		return (1);
	}
	return (0);
}