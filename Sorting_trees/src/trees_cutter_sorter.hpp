
#include <vector>
using namespace std;

int solution(vector<int> &A) {

    int counter = 0;
    bool sorted;

    for(size_t i = 0; i < A.size(); i++){           // Trees cutter

        size_t previous = 999;                      // previous tree
        sorted = true;

        for(size_t j = 0; j < A.size(); j++){       // Sorting evaluator

            if(j == i) continue;                    // Avoid cutted trees

            if(previous == 999) {                   // Add first tree
                previous = j;
                continue;
            }

            if(A[j] < A[previous]) {                // Break if not sorted
                sorted = false;
                break;
            }

            previous = j;
        }

        if(sorted) counter++;
    }

    if (counter == 999) counter = 0;
    return counter;
}
