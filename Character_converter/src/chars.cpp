// Definitions of the member functions of ch class.

#include "chars.h"
#include <iostream>


int ch::range(int num) {
	int a = 1;
	for (int i = 0; i<(num * 8); i++) { a = a * 2; };
	return a;
}

void ch::intro() {
	std::cout << "In this system, the different character types ranges are:\n\n";

	std::cout << "char " << (char)26
		<< "          Size: " << sizeof(char) << " bytes wide\n"
		<< "                Range: [-" << (char_el() / 2)
		<< "," << (char_el() / 2 - 1) << "]\n\n";

	std::cout << "unsigned char " << (char)26
		<< " Size: " << sizeof(unsigned char) << " bytes wide\n"
		<< "                Range: [0," << (unchar_el() - 1) << "]\n\n";
}

void ch::menu() {
	std::cout << "\n"
		<< "(1) Show all char type elements\n"
		<< "(2) Show all unsigned char type elements\n"
		<< "(3) Dictionary int - char\n"
		<< "(4) Dictionary int - unsigned char\n"
		<< "(5) Dictionary char - int\n"
		<< "(6) Dictionary unsigned char - int\n"
		<< "(7) Quit\n\n";
}

void ch::all_char() {
	int i = -char_el() / 2;
	for (; i<char_el() / 2; i++) {
		std::cout << i << " - " << (char)i << "\n";
	}
};

void ch::all_unchar() {
	int i = 0;
	for (; i<unchar_el(); i++) {
		std::cout << i << " - " << (unsigned char)i << "\n";
	}
};

void ch::d_int_char() {
	int a;
	do {
		std::cout << "Enter an integer [-" << (char_el() / 2)
			<< "," << (char_el() / 2 - 1) << "]: ";
		std::cin >> a;
		if (a<-(char_el() / 2) || a >= (char_el() / 2)) std::cout << "- Out of range -\n";
		else std::cout << a << " - " << (char)a << "\n\n";
	} while (a >= -(char_el() / 2) && a<(char_el() / 2));
};

void ch::d_int_unchar() {
	int a;
	do {
		std::cout << "Enter an integer [0,"
			<< (unchar_el() - 1) << "]: ";
		std::cin >> a;
		if (a<0 || a >= (unchar_el())) std::cout << "- Out of range -\n";
		else std::cout << a << " - " << (unsigned char)a << "\n\n";
	} while (a >= 0 && a<unchar_el());
};

void ch::d_char_int() {
	char a;
	do {
		std::cout << "Enter a char type element [\"q\" to quite]: ";
		std::cin >> a;
		std::cout << a << " - " << (int)a << "\n\n";
	} while (a != 'q');
};

void ch::d_unchar_int() {
	unsigned char a;
	do {
		std::cout << "Enter an unsigned char type element [\"q\" to quite]: ";
		std::cin >> a;
		std::cout << a << " - " << (int)a << "\n\n";
	} while (a != 'q');
};
