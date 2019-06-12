// Driver function (main())
//

// corregir rango si el último dígito binario es el signo
// incluir rango al preguntar por input

#include "bin_class.h"
#include <iostream>

int main() {
	bin obj;
	int option;

	obj.intro();

	do {
		do {
			obj.menu();
			std::cout << "Select your option: ";
			std::cin >> option;
		} while (!(option == 1 || 2 || 3));

		switch (option) {
		case 1:
			obj.int_bin();
			break;
		case 2:
			obj.bin_int();
			break;
		}
	} while (option != 3);

	return 0;
}
