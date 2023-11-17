#include <iostream>
#include <fstream>
#include <string>

class FileEditor {
private:
    std::ifstream inputFile;
    std::ofstream tempFile;
    std::string inputFileName;
    std::string tempFileName;
    std::string oldWord;
    std::string newWord;

    void rewrite(std::string& line) {
        size_t position = line.find(oldWord);
        while (position != std::string::npos) {
            line = line.substr(0, position) + newWord + line.substr(position + oldWord.length());
            position = line.find(oldWord);
        }
    }

public:
    FileEditor(const std::string& filename, const std::string& oldWord, const std::string& newWord)
        : inputFileName(filename), oldWord(oldWord), newWord(newWord) {}

    bool openFiles() {
        inputFile.open(inputFileName);
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file" << std::endl;
            return false;
        }

        tempFileName = inputFileName + "_temp.txt";
        tempFile.open(tempFileName);
        if (!tempFile.is_open()) {
            std::cerr << "Error opening temporary file" << std::endl;
            return false;
        }

        return true;
    }

    void closeFiles() {
        inputFile.close();
        tempFile.close();
    }

    void processFile() {
        std::string line;
        while (std::getline(inputFile, line)) {
            rewrite(line);
            tempFile << line << std::endl;
        }
    }

    bool replaceAndRename() {
        closeFiles();

        if (std::remove(inputFileName.c_str()) != 0) {
            std::cerr << "Error removing original file" << std::endl;
            return false;
        }

        if (std::rename(tempFileName.c_str(), inputFileName.c_str()) != 0) {
            std::cerr << "Error renaming temporary file" << std::endl;
            return false;
        }

        return true;
    }
};

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Check the number of arguments" << std::endl;
        return 1;
    }

    FileEditor fileEditor(argv[1], argv[2], argv[3]);

    if (!fileEditor.openFiles()) {
        return 1;
    }

    fileEditor.processFile();

    if (!fileEditor.replaceAndRename()) {
        return 1;
    }

    return 0;
}
