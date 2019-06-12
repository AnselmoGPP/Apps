
/*	Problem: We have the names of some cities and distances from our position. These cities
	are all along a straight line. We want a program that outputs the diference of distance
	between each other, from the nearests to the furthest (the first distance is from us to
	the nearest city, the second distance is from that city to the second nearer city, and
	so on). Examples (input and output):

	Rkbs,5453; Wdqiz,1245; Rwds,3890; Ujma,5589; Tbzmo,1303;
	1245, 58, 2587, 1563, 136

	Vgdfz, 70; Mgknxpi, 3958; Nsptghk, 2626; Wuzp, 2559; Jcdwi, 3761;
	70, 2489, 67, 1135, 197


Principal code used:

std::string:		str.find(...)	(std::size_t)
					str.substr(...)
					str.size()

std::vector<type>	vec.push_back(str)
					std::sort(...)
					vec.begin()		vec.end()
					vec.size()

std::stringstream	>>	<<
					stream.clear()
*/

#include <string>		// std::substr()
#include <vector>
#include <iostream>
#include <algorithm>		// std::sort()
#include <sstream>		// std::stringstream

void sort_stringToInt_subtract_print(std::vector<std::string>);

void dataFromStdInput() {
	std::string input;
	std::vector<std::string> stringNums;

	// Extract the numbers and store them in a vector (stringNums).
	while (std::cin >> input) {								// break system: end-of-line
		if (input == "0") break;							// break system: 0
		std::size_t pos1 = input.find(',');
		std::size_t pos2 = input.find(';');
		std::string str = input.substr(pos1 + 1, pos2 - pos1 - 1);
		stringNums.push_back(str);
	}

	sort_stringToInt_subtract_print(stringNums);
}


void dataFromString() {
	std::string input = "Rkbs,5453; Wdqiz,1245; Rwds,3890; Ujma,5589; Tbzmo,1303;";
	std::vector<std::string> stringNums;

	// Extract the numbers and store them in a vector (stringNums).
	int counter = 1;
	for (std::size_t i = 0; i < input.size(); i++) if (input[i] == ' ') counter++;

	for (int i = 0; i < counter; i++) {					// break system: Automatic (counter)
		std::size_t pos1 = input.find(',');
		std::size_t pos2 = input.find(';');
		std::string str = input.substr(pos1 + 1, pos2 - pos1 - 1);
		stringNums.push_back(str);
		input = input.substr(pos2 + 1, input.size()-pos2-1);
	}

	sort_stringToInt_subtract_print(stringNums);
}


void sort_stringToInt_subtract_print(std::vector<std::string> vec) {
	// Sort the vector elements in ascending order.
	std::sort(vec.begin(), vec.end());

	// Pass data from a vector of strings (stringNums) to vector of ints (list).
	std::stringstream stream;
	std::vector<int> list;
	int temp;
	for (int i = 0; i < vec.size(); i++) {
		stream << vec[i];
		stream >> temp;
		list.push_back(temp);
		stream.clear();
	}

	// Convert data (distances) from list into difference of distances.
	for (std::size_t i = list.size() - 1; i > 0; i--) {
		list[i] = list[i] - list[i - 1];
	}

	// Print data from list.
	for (int i = 0; i < list.size(); i++) {
		if (i == list.size() - 1) std::cout << list[i];
		else std::cout << list[i] << ", ";
	}
}


int main() {
	dataFromString();
	// dataFromStdInput();

	std::cout << std::endl;
        //system("pause");
	return 0;
}
