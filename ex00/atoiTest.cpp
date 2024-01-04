#include <iostream>
#include <cstdlib>

int main() {
  std::string str1 = "45";
  std::string str2 = "3.14";
//   std::string str3 = "31337 with words";
//   std::string str4 = "words and 2";

  int myint1 = std::atoi(str1.c_str());
  int myint2 = std::atoi(str2.c_str());
  //istrginstream
  // 이 경우 해석할 수 있는 문자 위치 까지 읽어들인다.
//   int myint3 = std::stoi(str3);

  // 아래의 경우 std::invalid_argument 를 던짐
  // int myint4 = std::stoi(str4);

  std::cout << "my int 1 is " << myint1 << '\n';
  std::cout << "my int 2 is " << myint2 << '\n';
}