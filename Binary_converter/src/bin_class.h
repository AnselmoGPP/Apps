#pragma once
#ifndef BIN_CLASS_H
#define BIN_CLASS_H

// Definition of the class bin.

class bin {
	// Maximum range of integer values allowed by int type
	unsigned int range();
	// Function used in the calculator binary to int. It transforms the char values of the input into int values (operation needed to operate with them).
	int conversor(char a);
	// Returns number of bits of int (signed int). Must be static because is used as index of array (must be constant value).
	static constexpr int siz();
public:
	void intro();		// Presentation
	void menu();		// Main menu
	void int_bin();		// Int to binary calculator
	void bin_int();		// Binary to int calculator
};

#endif
