#pragma once
#ifndef CHARS_H
#define CHARS_H

// Declaration of class ch and its member functions.

// Don't enter characters in the main menu or it will loop.

class ch {
	int range(int num);
	inline int char_el() { return range(sizeof(char)); };
	inline int unchar_el() { return range(sizeof(unsigned char)); };
public:
	void intro();
	void menu();
	void all_char();
	void all_unchar();
	void d_int_char();
	void d_int_unchar();
	void d_char_int();
	void d_unchar_int();
};

#endif

/*

----- Public members:

void intro():			Initial presentation.

void menu():			Main menu.

void all_char():		Prints a list of all char type elements.

void all_unchar():		Prints a list of all unsigned char type elements.

void d_int_char():		Dictionary int to char.

void d_int_unchar():	Dictionary int to unsigned char.

void d_char_int():		Dictionary char to int.

void d_unchar_int():	Dictionary unsigned char to int.

----- Private members:

int range(int):		Given a number of bytes, outputs the number of possible unique combinations.
					Used in char_el() and unchar_el().

int char_el():		Computes size of char type in bytes and pass that to range(int).

int unchar_el():	Computes size of unsigned char type in bytes and pass that to range(int).

*/
