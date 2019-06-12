/*
	Description:
		You have (x, y) coordinates for 2 points and need to find the distance between them.
	Input:
		Your program should read lines from standard input. Each line contains two space-delimited 
		coordinate pairs. All x and y values are integers between -100 and 100.
	Output:
		Print the distance between the two points. You do not need to round the results you receive.

	Examples of inputs and outputs:

		(25, 4) (1, -6)
		26

		(47, 43) (-25, -11)
		90
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
	for(;;){
		std::cout << "Enter your 2 points coordinates (example: (2, 3) (7, 1)): " << std::endl;

		// Extract the numbers from the input
		std::string x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		
		std::size_t pos = x1.find(',');
		x1 = x1.substr(1, pos-1);

		pos = y1.find(')');
		y1 = y1.substr(0, pos);

		pos = x2.find(',');
		x2 = x2.substr(1, pos-1);

		pos = y2.find(')');
		y2 = y2.substr(0, pos);

		// Pass numbers from string to double;
		double X1, Y1, X2, Y2;
		std::stringstream stream;
		stream << x1 << " " << y1 << " " << x2 << " " << y2;
		stream >> X1 >> Y1 >> X2 >> Y2;

		// Calculate and output distance
		double distance = sqrt((X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2));
		std::cout << distance;

		std::cout << std::endl;
	}

    return 0;
}

