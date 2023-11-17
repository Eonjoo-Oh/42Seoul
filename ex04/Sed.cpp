#include "Sed.hpp"

void	Sed::setInputFileName(char *name)
{
	inputFileName = name;
}

void	Sed::setTempFileName(std::string inputFileName)
{
	tempFileName = inputFileName + "_temp.txt";
}

void	Sed::setOldWord(char *word)
{
	oldWord = word;
}

void	Sed::setNewWord(char *word)
{
	newWord = word;
}

std::string	Sed::getInputFileName(void)
{
	return (inputFileName);
}

std::string	Sed::getTempFileName(void)
{
	return (tempFileName);
}

std::string Sed::getOldWord(void)
{
	return (oldWord);
}

std::string Sed::getNewWord(void)
{
	return (newWord);
}

void	Sed::rewriteFile(std::ostream &tempFile)
{
	while (std::getline(inputFile, readLine))
	{
		replaceWord();
		tempFile << readLine << std::endl;
	}
}

void	Sed::replaceWord()
{
	size_t	position;

	position = readLine.find(oldWord);
	while (position != std::string::npos)
	{
		readLine = readLine.substr(0, position) + newWord + readLine.substr(position + oldWord.length());
		position = readLine.find(oldWord);
	}
}