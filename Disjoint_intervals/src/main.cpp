
#include "disjoint_intervals.hpp"
#include <iostream>

int main(){
	vector<int> A = {1, 12, 42, 70, 36, -4, 43, 15};
	vector<int> B = {5, 15, 44, 72, 36,  2, 69, 24};
    std::cout << solve(A, B) << std::endl;

    vector<int> C = {1};
    vector<int> D = {5};
    std::cout << solve(C, D) << std::endl;
}
