// Driver program (main()).

#include "chars.h"
#include <iostream>

int main() {
	ch abc;
	int choice;

	abc.intro();

	do {

		do {
			abc.menu();
			std::cout << "Enter an option: ";
			std::cin >> choice;
			std::cout << "\n";
		} while (choice<1 || choice>7);

		switch (choice) {
		case 1:
			abc.all_char();
			break;
		case 2:
			abc.all_unchar();
			break;
		case 3:
			abc.d_int_char();
			break;
		case 4:
			abc.d_int_unchar();
			break;
		case 5:
			abc.d_char_int();
			break;
		case 6:
			abc.d_unchar_int();
			break;
		}

	} while (choice != 7);

	return 0;
}
