/*
	Input is the price and the payment amount, separated by a semicolon and a whitespace. 
	The output is a list of the names of the coins you have to return as change, alphabetically ordered 
	and commma separated (except the last coin). 
	If PP==CH, return ZERO. If CH << PP, return ERROR.

	Example of input (Price; Payment):		15.94; 16.00		 
	Example of output:						

	'PENNY': .01,
	'NICKEL': .05,
	'DIME': .10,
	'QUARTER': .25,
	'HALF DOLLAR': .50,
	'ONE': 1.00,
	'TWO': 2.00,
	'FIVE': 5.00,
	'TEN': 10.00,
	'TWENTY': 20.00,
	'FIFTY': 50.00,
	'ONE HUNDRED': 100.00
*/

// %: Modulus operator. It can only be used with integer values.
// fmod(): Calculates modulus. Can be used with doubles.			std::fmod(x, y);

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>


int main() {

	// Extract the numbers from the input
	std::string Price, Payment;
	std::cin >> Price >> Payment;
	std::size_t pos = Price.find(';');
	Price = Price.substr(0, pos);				// why (pos) is not (pos-1) ?

	// Pass numbers from string to double;
	double price, payment;
	std::stringstream stream;
	stream << Price << " " << Payment;
	stream >> price >> payment;

	// Initial checks (ERROR, ZERO)
	if (payment < price) {
		std::cout << "ERROR" << std::endl;
		system("pause");
		return 1;
	}
	if (price == payment) {
		std::cout << "ZERO" << std::endl;
		system("pause");
		return 0;
	}

	// Determine the coins we have to return.
							// Name of coins alphabetically ordered and their corresponding values
	std::string names[12] = { "DIME", "FIFTY", "FIVE", "HALF DOLLAR", "NICKEL", "ONE", "ONE HUNDRED", "PENNY", "QUARTER", "TEN", "TWENTY", "TWO" };
	double values[12] = { 0.1, 50, 5, 0.5, 0.05, 1, 100, 0.01, 0.25, 10, 20, 2 };

	double remain = payment - price;
	std::vector<bool> marks(12, 0);

	if ((remain / values[6]) >= 1) {				// ONE HUNDRED - 100
		marks[6] = 1;
		remain = std::fmod(remain, values[6]);
	}
	if ((remain / values[1]) >= 1) {				// FIFTY - 50
		marks[1] = 1;
		remain = std::fmod(remain, values[1]);
	}
	if ((remain / values[10]) >= 1) {				// TWENTY - 20
		marks[10] = 1;
		remain = std::fmod(remain, values[10]);
	}
	if ((remain / values[9]) >= 1) {				// TEN - 10
		marks[9] = 1;
		remain = std::fmod(remain, values[9]);
	}
	if ((remain / values[2]) >= 1) {				// FIVE - 5
		marks[2] = 1;
		remain = std::fmod(remain, values[2]);
	}
	if ((remain / values[11]) >= 1) {				// TWO - 2
		marks[11] = 1;
		remain = std::fmod(remain, values[11]);
	}
	if ((remain / values[5]) >= 1) {				// ONE - 1
		marks[5] = 1;
		remain = std::fmod(remain, values[5]);
	}
	if ((remain / values[3]) >= 1) {				// HALF DOLLAR - 0.50
		marks[3] = 1;
		remain = std::fmod(remain, values[3]);
	}
	if ((remain / values[8]) >= 1) {				// QUARTER - 0.25
		marks[8] = 1;
		remain = std::fmod(remain, values[8]);
	}
	if ((remain / values[0]) >= 1) {				// DIME - 0.10
		marks[0] = 1;
		remain = std::fmod(remain, values[0]);
	}
	if ((remain / values[4]) >= 1) {				// NICKEL - 0.05
		marks[4] = 1;
		remain = std::fmod(remain, values[4]);
	}
	if ((remain / values[7]) >= 1) {				// PENNY - 0.01
		marks[7] = 1;
		remain = std::fmod(remain, values[7]);
	}

	// Output the result.
	int count = 0;					// counter used to avoid the last comma
	for (int i = 0; i < marks.size(); i++) {
		if (marks[i] == 1) ++count;
	}

	int count2 = 0;					// counter used to avoid the last comma
	for (int i = 0; i < marks.size(); i++) {
		if (marks[i] == 1) {
			count2++;
			if (count2 == count) std::cout << names[i];
			else std::cout << names[i] << ", ";
		}
	}
	

	std::cout << std::endl;
	system("pause");
	return 0;
}
