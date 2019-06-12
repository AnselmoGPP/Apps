# Character_converter

This application allows to easily know the numerical values of the 8-bit ASCII character set.

This console application is useful to know fast the value of characters (type char or unsigned char variables). This programs deals with the 8-bits ASCII character set, which contains 256 characters in total (2^8 = 256). There are many options in the main menu:

-Show a list of all char type elements, including their conrresponding numerical values as char literals.
-Show a list of all char type elements, including their conrresponding numerical values as unsigned char literals.
-Conversor from int to char.
-Conversor from int to unsigned char.
-Conversor from char to int.
-Conversor from unsigned to int.
-It has an option to close the application when user desires.

At the beginning, it is showed the number of bytes a variable of type char and unsigned char has in the system where the program was compiled and the range of values that char and unsigned char can take. This data is obtain thanks to the use of sizeof().

Source files included:

  Characterscalc.cpp: Entry point of the program. Contains function main().
  
  chars.h:            Contains the definintion of class ch and comments explaining every member.
  
  chars.cpp:          Contains the definitions of the members of class ch.
