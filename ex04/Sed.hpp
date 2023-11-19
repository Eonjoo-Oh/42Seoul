#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class	Sed
{
	private:
		std::ifstream	inputFile;
		std::ofstream	tempFile;
		std::string		inputFileName;
		std::string		tempFileName;
		std::string		oldWord;
		std::string		newWord;
		std::string		readLine;
	public:
		Sed(char *inputFileName, char *oldWord, char *newWord) 
			: inputFileName(inputFileName), oldWord(oldWord), newWord(newWord) {};
		bool	fileProcess();
		bool	rewriteProcess();
		bool	openInputFile();
		bool	openTempFile();
		void	setTempFileName();
		void	rewrite();
		bool	removeInputFile();
		bool	renameTempFile();
		void	closeFiles();
};

#endif