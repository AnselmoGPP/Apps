
#include <vector>

using namespace std;

int solve(vector<int> &A, vector<int> &B) {

    vector<int> a = A;
    vector<int> b = B;
    size_t siz = A.size();

    for(size_t i = 0; i < siz; i++){
        for(size_t j = 0; j < siz; j++){
            if(i == j) continue;

            if( (b[i] >= a[j] && a[i] <= b[j]) ||
                (b[i] <= b[j] && a[i] >= a[j]) ) {      // Check if they overlap
               if(a[j] < a[i]) a[i] = a[j];             // Fusion
               if(b[j] > b[i]) b[i] = b[j];
               a.erase(a.begin()+j);
               b.erase(b.begin()+j);
               --siz; --j;
            }
        }
    }

    siz = a.size();
    return siz;
}
