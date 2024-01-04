#include <iostream>
#include <string>

std::string removeSpacesAndConcatenate(const std::string& input) {
    std::string result;

    for (std::size_t i = 0; i < input.length(); ++i) {
        if (input[i] != ' ') {
            result += input[i];
        }
    }

    return result;
}

int main() {
    std::string original = "This is a sample string";
    std::string modified = removeSpacesAndConcatenate(original);

    std::cout << "Original: " << original << std::endl;
    std::cout << "Modified: " << modified << std::endl;

    return 0;
}