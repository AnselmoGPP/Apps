
#include <iostream>
#include <string>

void compare(bool a, bool b) {
	if (a == b) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
}

void compare(std::string a, std::string b) {
	if (a == b) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
}

void compare (int a, int b) {
	if ( a == b ) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
}

void verify(bool a) {
	if (a) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
}
