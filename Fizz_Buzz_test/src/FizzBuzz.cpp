/*
Fizz-Buzz test: Write a program that prints the numbers from 1 to 100.
But for multiples of 3 print "Fizz" instead of the number, and for
multiples of 5 print "Buzz". For numbers which are multiples of both
3 and 5 print "FizzBuzz".
*/

#include <iostream>

int main()
{
	for (int i = 1; i < 101; i++) {
		if (i % 3 == 0 && i % 5 == 0) { std::cout << "FizzBuzz" << std::endl; }
		else if (i % 3 == 0) { std::cout << "Fizz" << std::endl; }
		else if (i % 5 == 0) { std::cout << "Buzz" << std::endl; }
		else std::cout << i << std::endl;
	}

	system("pause");
	return 0;
}
