
#include "trees_cutter_sorter.hpp"
#include <iostream>

int main(){
    vector<int> vec1 {3, 2};
    cout << solution(vec1) << endl;         // 2

    vector<int> vec2 = {3, 4, 5, 4};
    cout << solution(vec2) << endl;         // 2

    vector<int> vec3 = {4, 5, 2, 3, 4};
    cout << solution(vec3) << endl;         // 0

    vector<int> vec4 = {1, 2, 3, 3, 5, 6, 7};
    cout << solution(vec4) << endl;         // 7
}
