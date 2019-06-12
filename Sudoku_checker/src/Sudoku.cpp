/*
Description:
A Sudoku board is a 9 x 9 grid of cells where each cell contains a single digit from 1 to 9,
inclusive. A valid Sudoku board has the following properties:
- Each row contains no duplicate digits
- Each column contains no duplicate digits
- Each 3 x 3 sub-grid contains no duplicate digits (there are 9 sub-grids)
For this challenge, you will be given a 9 x 9 Sudoku board where every cell is populated with a digit
from 1 to 9. For a 9 x 9 board, there are 9 sub-grids, each 3 x 3 in size. Write a program that
determines whether each input board is valid.

Input:
Your program should read lines from standard input. Each line contains a comma delimited list of
digits in row-major order.

Output:
Your program should print "True" if the input grid is a valid Sudoku board or "False" if it is not.

Examples of input and output:

1,2,3,4,5,6,7,8,9,2,3,4,5,6,7,8,9,1,3,4,5,6,7,8,9,1,2,4,5,6,7,8,9,1,2,3,5,6,7,8,9,1,2,3,4,6,7,8,9,1,2,3,4,5,7,8,9,1,2,3,4,5,6,8,9,1,2,3,4,5,6,7,9,1,2,3,4,5,6,7,8
False

1,2,7,5,3,9,8,4,6,4,5,3,8,6,1,7,9,2,8,9,6,4,7,2,1,5,3,2,8,9,3,1,7,4,6,5,3,6,5,2,8,4,9,1,7,7,4,1,9,5,6,3,2,8,9,7,4,6,2,8,5,3,1,5,1,2,7,4,3,6,8,9,6,3,8,1,9,5,2,7,4
True

*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool rows(std::vector<int> vec) {

	std::vector<int> ones(9, 1);		// Used to compare with "index"
	std::vector<int> zeros(9, 0);		// Used to reset "index"
	std::vector<int> index(9, 0);
	int beg = 0, end = 9;

	for (int i = 0; i < 9; i++) {
		for (int j = beg; j < end; j++) {
			index[vec[j] - 1] ++;
		}
		if (index != ones) return 0;
		beg = beg + 9;
		end = end + 9;
		index = zeros;
	}
	return 1;
}

bool columns(std::vector<int> vec) {

	std::vector<int> ones(9, 1);
	std::vector<int> zeros(9, 0);
	std::vector<int> index(9, 0);
	int beg = 0, end = 73;

	for (int i = 0; i < 9; i++) {
		for (int j = beg; j < end; j = j + 9) {
			index[vec[j] - 1]++;
		}
		if (index != ones) return 0;
		beg++;
		end++;
		index = zeros;
	}
	return 1;
}

bool squares(std::vector<int> vec) {

	std::vector<int> ones(9, 1);
	std::vector<int> zeros(9, 0);
	std::vector<int> index(9, 0);
	int d = 0, dend = 3;

	for (int a = 0; a < 3; a++) {							// Iterates through rows of squares.
		for (int b = 0; b < 3; b++) {						// Iterates through squares in a row.
			for (int c = 0; c < 3; c++) {					// Iterates through rows in a square.
				for (d; d < dend; d++) index[vec[d] - 1]++;	// Iterates through elements in a row in a square.
				if (c != 2) {
					d += 6;
					dend += 9;
				}
			}
			if (index != ones) return 0;
			index = zeros;
			if (b != 2) {
				d -= 18;
				dend -= 15;
			}
		}
		if (a != 2) dend += 3;
	}

	return 1;
}

int main()
{
	// std::string board{ "1,2,7,5,3,9,8,4,6,4,5,3,8,6,1,7,9,2,8,9,6,4,7,2,1,5,3,2,8,9,3,1,7,4,6,5,3,6,5,2,8,4,9,1,7,7,4,1,9,5,6,3,2,8,9,7,4,6,2,8,5,3,1,5,1,2,7,4,3,6,8,9,6,3,8,1,9,5,2,7,4" };
	std::string board;
	std::cin >> board;

	// Numbers are extracted from the input string, transformed into int and stored in a vector.
	std::string sub;
	std::stringstream stream;
	int integer;
	std::vector<int> nums;

	for (int i = 0; i < 81; i++) {
		sub = board.substr(0, 1);
		stream << sub;
		stream >> integer;
		stream.clear();
		nums.push_back(integer);
		if (i<80) board = board.substr(2, board.size() - 2);
	}

	// Chech if any row, column or square has a repeated number
	if (rows(nums) && columns(nums) && squares(nums)) {
		std::cout << "True";
		system("pause");
		return 0;
	}
	else {
		std::cout << "False";
		system("pause");
		return 1;
	}
}
