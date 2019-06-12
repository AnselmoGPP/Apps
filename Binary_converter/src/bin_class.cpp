// Definitions of the bin class member functions.

#include "bin_class.h"
#include <iostream>
#include <cstring>
#include <cmath>

// Maximum range of integer values allowed by int type (signed int). Example: If result is 128, then range is [-128,127].
unsigned int bin::range() {
	return pow(2, (siz() - 1));   // Minus 1 because the last bit is the sign
};

void bin::intro() {
	std::cout << "In this system, the signed int (int) type numbers have:\n\n"
		<< "       Bytes width: " << sizeof(int) << "\n"
		<< "       Range: [ -" << range() << " , " << (range() - 1) << " ]."
		<< '\n';
};

void bin::menu() {
	std::cout << "\n"
		<< "(1) Decimal to Binary\n"
		<< "(2) Binary to Decimal\n"
		<< "(3) Quit\n";
};

// Int to binary calculator.
void bin::int_bin() {
	int a;
	do {
		int b = 0, c = 0;
		unsigned int r = range();
		std::cout << "\nEnter a decimal integer [-" << range() << ", " << (range() - 1) << "][0 to quit]: ";
		std::cin >> a;
		for (r; r>0; r = r / 2) {
			if (a & r) std::cout << "1";
			else std::cout << "0";
			b++; c++;
			if (b == 4 && c == 4) { std::cout << " "; b = 0; }
			else if (b == 4 && c == 8) { std::cout << "\n"; b = 0; c = 0; };
		}
	} while (!a == 0);
};

// Returns number of bits of int (signed int).
constexpr int bin::siz() {
	int sizz = sizeof(int) * 8;
	return sizz;
}

// Binary to int calculator.
void bin::bin_int() {
	char bina[siz()];   // expresión no se evaluó como constante ¿?
	int len, val, n;

	do {
		for (n = 0; n<siz(); n++) bina[n] = 0;

		std::cout << "\nEnter a binary signed integer [" << siz() << " elements max.] [q to quit]: ";
		std::cin >> bina;
		if (bina[0] == 'q') return;
		len = strlen(bina);
		std::cout << "Length: " << len << " elements\n";

		n = 1; val = 0;

		if (len == siz() && bina[0] == '0' || len<siz()) {    // Positive binaries
			for (len--; len >= 0; len--) {
				val = val + (conversor(bina[len])*n);
				n = n * 2;
			}
			std::cout << val;
		}

		if (len == siz() && bina[0] == '1') {                 // Negative binaries
			for (len--; len >= 0; len--) {
				if (bina[len] == '1') bina[len] = '0';
				else bina[len] = '1';
			}
			len = strlen(bina);
			for (len--; len >= 0; len--) {
				val = val - (conversor(bina[len])*n);
				n = n * 2;
			}
			std::cout << --val;
		}

	} while (1);
};

// Function used in the calculator binary to int. It transforms the char values of the input into int values (operation needed to operate with them).
int bin::conversor(char a) {
	if (a == '1') return 1;
	else if (a == '0') return 0;
};
