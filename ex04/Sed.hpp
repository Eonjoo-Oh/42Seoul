#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class	Sed
{
	private:
		std::ifstream inputFile;
		std::ofstream tempFile;
		std::string	inputFileName;
		std::string	tempFileName;
		std::string	oldWord;
		std::string	newWord;
		std::string	readLine;
	public:
		Sed(std::ifstream &inputFile, char *inputFileName, char *oldWord, char *newWord) : inputFile(inputFile), inputFileName(inputFileName), oldWord(oldWord), newWord(newWord) {
			setInputFileName(inputFileName);
			setOldWord(oldWord);
			setNewWord(newWord);
			setTempFileName(this->inputFileName);
		};
		void		setInputFileName(char *name);
		void		setTempFileName(std::string inputFileName);
		void		setOldWord(char *word);
		void		setNewWord(char *word);
		std::string	getInputFileName(void);
		std::string	getTempFileName(void);
		std::string	getOldWord(void);
		std::string	getNewWord(void);
		void		rewriteFile(std::ostream &tempFile);
		void		replaceWord(void);
};

#endif