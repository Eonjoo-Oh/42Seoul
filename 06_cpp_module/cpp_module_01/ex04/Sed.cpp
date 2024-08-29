#include "Sed.hpp"

bool	Sed::fileProcess()
{
	if (openInputFile() == false)
		return (false);
	setTempFileName();
	if (openTempFile() == false)
		return (false);
	return (true);
}

bool	Sed::rewriteProcess()
{
	while (std::getline(inputFile, readLine))
	{
		rewrite();
		tempFile << readLine << std::endl;
	}
	if (removeInputFile() == false)
		return (false);
	if (renameTempFile() == false)
		return (false);
	return (true);
}

bool	Sed::openInputFile()
{
	inputFile.open(inputFileName.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: input file open" << std::endl;
		return (false);
	}
	return (true);
}

bool	Sed::openTempFile()
{
	tempFile.open(tempFileName.c_str());
	if (!tempFile.is_open())
	{
		std::cerr << "Error: temp file open" << std::endl;
		inputFile.close();
		return (false);
	}
	return (true);
}

void	Sed::setTempFileName()
{
	tempFileName = inputFileName + "_temp.txt";
}

void	Sed::rewrite()
{
	size_t position;
	
	position = readLine.find(oldWord);
	while (position != std::string::npos)
	{
		readLine = readLine.substr(0, position) + newWord + readLine.substr(position + oldWord.length());
		position = readLine.find(oldWord);
	}
}

bool	Sed::removeInputFile()
{
	if (std::remove(inputFileName.c_str()) != 0)
	{
		std::cerr << "Error: remove input file" << std::endl;
		return (false);
	}
	return (true);
}

bool	Sed::renameTempFile()
{
	if (std::rename(tempFileName.c_str(), inputFileName.c_str()) != 0)
	{
		std::cerr << "Error: rename temp file" << std::endl;
		return (false);
	}
	return (true);
}

void	Sed::closeFile()
{
	tempFile.close();
}
