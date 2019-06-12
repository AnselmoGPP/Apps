# Binary_converter

A console application that helps to easily translate from binary to decimal and viceversa.

This was created with Microsoft Visual Studio Community 2017, v. 15.3.5, using C++. To be able to edit and compile these files with this IDE, create a Solution with a Project inside, then load the .cpp and .h files on that project. Solutions are usually saved in C:\Users\UserName\source\repos. The .exe file is the executable, obtained in Windows 8.1 as a result of compiling the code.

This program is useful to easily obtain the decimal or binary values when needed. This console application displays two options:
  - Conversor from Binary to Decimal.
  - Conversor from Decimal to Binary.

There is an option to close the application when user desires. 
At the beginning, it is showed the number of bytes a variable of type int has in the system where the program was compiled and the range of values that signed int can take. This data is obtain thanks to the use of sizeof().

Source files included:

  Binarycalc.cpp:   Entry point of the program. Contains function main().
  
  bin_class.h:      Contains the definition of class bin and comments explaining every member.
  
  bin_class.cpp:    Contains the definitions of the members of class bin.
