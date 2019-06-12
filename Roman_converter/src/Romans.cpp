/*
	I - 1		IV - 4
	V - 5		IX - 9
	X - 10		XL - 40
	L - 50		XC - 90
	C - 100		CD - 400
	D - 500		CM - 900
	M - 1000
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Romans.h"

void Romans::presentation() {
	std::cout << "        >>>> Decimal - Roman numerals translator <<<<" << std::endl;
	std::cout << "              >>>> Covering from 1 to 3999 <<<<" << std::endl << std::endl;
}

void Romans::menu() {
		for (;;) {
			std::cout << std::endl;
			std::cout	<< "	(1) Decimal to Roman" << std::endl
						<< "	(2) Roman to Decimal" << std::endl
						<< "	(3) Display range" << std::endl
						<< "	(4) Exit" << std::endl << std::endl
						<< "Select an option: ";

			int selection;
			std::cin >> selection;

			if (selection == 1) {
				std::cout << "Enter a decimal number/s (1 to 3999) (0 to exit): " << std::endl;
				int input;
				while (std::cin >> input) {				
					if (input == 0) break;
					decimalToRomans(input);
					std::cout << std::endl;
				}
			}
			if (selection == 2) {
				std::cout << "Enter a roman number/s (1 to 3999) (0 to exit): " << std::endl;
				std::string input;
				while (std::cin >> input) {
					if (input == "0") break;
					std::cout << romansToDecimal(input) << std::endl;
				}
			}
			if (selection == 3) {
				std::cout << "Enter initial and final integers of the range (1 to 3999) (0 to exit): ";
				int ini, fin;
				std::cin >> ini >> fin;
				std::cout << std::endl;
				range(ini, fin);
				std::cout << std::endl;
			}
			if (selection == 4) return;
	}
}

void Romans::range(int initial, int final) {
	for (int i = initial; i <= final; i++) {
		std::cout << std::left;
		std::cout << std::setw(6) << i;
		decimalToRomans(i);
		if(i != final) std::cout<< std::endl;
	}
}

int Romans::romansToDecimal(std::string str) {
	
	int count = 0, result = 0;
	std::string::size_type siz = str.size();
	
	for (int i = 0; i < 3; i++) {
		if (str[count] == 'M') {
			result += 1000;
			count++;
			if (count == siz) return result;
		}
	}
	if (str[count] == 'C' && str[count+1] == 'M') {
		result += 900;
		count += 2;
		if (count == siz) return result;
	}
	if (str[count] == 'D') {
		result += 500;
		count++;
		if (count == siz) return result;
	}
	if (str[count] == 'C' && str[count + 1] == 'D') {
		result += 400;
		count += 2;
		if (count == siz) return result;
	}
	for (int i = 0; i < 3; i++) {
		if (str[count] == 'C') {
			result += 100;
			count++;
			if (count == siz) return result;
		}
	}
	if (str[count] == 'X' && str[count + 1] == 'C') {
		result += 90;
		count += 2;
		if (count == siz) return result;
	}
	if (str[count] == 'L') {
		result += 50;
		count++;
		if (count == siz) return result;
	}
	if (str[count] == 'X' && str[count + 1] == 'L') {
		result += 40;
		count += 2;
		if (count == siz) return result;
	}
	for (int i = 0; i < 3; i++) {
		if (str[count] == 'X') {
			result += 10;
			count++;
			if (count == siz) return result;
		}
	}
	if (str[count] == 'I' && str[count + 1] == 'X') {
		result += 9;
		count += 2;
		if (count == siz) return result;
	}
	if (str[count] == 'V') {
		result += 5;
		count++;
		if (count == siz) return result;
	}
	if (str[count] == 'I' && str[count + 1] == 'V') {
		result += 4;
		count += 2;
		if (count == siz) return result;
	}
	for (int i = 0; i < 3; i++) {
		if (str[count] == 'I') {
			result += 1;
			count++;
			if (count == siz) return result;
		}
	}

	std::cout << "invalid input - ";
	return 0;
}

void Romans::decimalToRomans(int num) {
	
		if (num / 1000 > 0) {
			for (int i = 0; i < (num / 1000); i++) std::cout << 'M';
			num = num % 1000;
		}

		if (num / 500 > 0) {
			if (num / 900) {
				std::cout << "CM";
				num = num % 900;
			}
			else for (int i = 0; i < (num / 500); i++) std::cout << 'D';
			num = num % 500;
		}

		if (num / 100 > 0) {
			if (num / 400) {
				std::cout << "CD";
				num = num % 400;
			}
			else for (int i = 0; i < (num / 100); i++) std::cout << 'C';
			num = num % 100;
		}

		if (num / 50 > 0) {
			if (num / 90) {
				std::cout << "XC";
				num = num % 90;
			}
			else for (int i = 0; i < (num / 50); i++) std::cout << 'L';
			num = num % 50;
		}

		if (num / 10 > 0) {
			if (num / 40) {
				std::cout << "XL";
				num = num % 40;
			}
			else for (int i = 0; i < (num / 10); i++) std::cout << 'X';
			num = num % 10;
		}

		if (num / 5 > 0) {
			if (num / 9) {
				std::cout << "IX";
				num = num % 9;
			}
			else for (int i = 0; i < (num / 5); i++) std::cout << 'V';
			num = num % 5;
		}

		if (num > 0) {
			if (num / 4) std::cout << "IV";
			else for (int i = 0; i < num; i++) std::cout << 'I';
		}
}

/*
----- decimalToRomans(int) -----

1)	Evaluate if number is divisible by 1000. If so, the corresponding number of Ms are output.

2)	Take the remainder of the previous division and evaluate if number is divisible by 900.
If so, CM is output. If not, but it is divisible by 500, a D is output.

3)	If the remainder of previous division is divisible by 400, CD is output. If not, but it
is divisible by 100, the corresponding number of Cs are output.

4)	If the remainder of previous division is divisible by 90, XC is output. If not, but it is
divisible by 50, L is output.

5)	If the remainder of previous division is divisible by 40, XL is output. If not, but it is
divisible by 10, the corresponding number of Ls are output.

6)	If the remainder of previous division is divisible by 9, IX is output. If not, but it is
divisible by 5, V is output.

7) If the remainder of previous division is divisible by 4, IV is output. If not, but it is
divisible by 1, the corresponding number of Is are output.

*/
