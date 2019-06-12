# Sudoku checker

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
