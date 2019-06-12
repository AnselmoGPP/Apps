/*
        This is a program that, by try and error, finds out which are the values of the guess[] array.
        variables[vars]: Characters that will be used to test. In total, vars posible characters.
        board[max]: Sizes that will be tested will be up to (max - 1). Here, it's max=15.
*/

#include <iostream>

int position;
char guess[] = "Kup-8";                              // The word to find out
char board[16] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0";    // The array where the tries are written

bool is_equal(int chars);


int main(){

    const int vars = 68;
    char variables[vars] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890-_,.";
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;

    for (int size = 1; size < 16 ; size++) {

        std::cout << "In level " << size << std::endl;

        for (a = 0; a < vars-1; a++) {
            board[0] = variables[a];
            if(size == 1){
                if (is_equal(size)) return 0;
                continue;
            }
            for (b = 0; b < vars; b++) {
                board[1] = variables[b];
                if(size == 2){
                    if (is_equal(size)) return 0;
                    continue;
                }
                for (c = 0; c < vars; c++) {
                    board[2] = variables[c];
                    if(size == 3){
                        if (is_equal(size)) return 0;
                        continue;
                    }
                    for (d = 0; d < vars; d++) {
                        board[3] = variables[d];
                        if(size == 4){
                            if (is_equal(size)) return 0;
                            continue;
                        }
                        for (e = 0; e < vars; e++) {
                            board[4] = variables[e];
                            if(size == 5){
                                if (is_equal(size)) return 0;
                                continue;
                            }
                            for (f = 0; f < vars; f++) {
                                board[5] = variables[f];
                                if(size == 6){
                                    if (is_equal(size)) return 0;
                                    continue;
                                }
                                for (g = 0; g < vars; g++) {
                                    board[6] = variables[g];
                                    if(size == 7){
                                        if (is_equal(size)) return 0;
                                        continue;
                                    }
                                    for (h = 0; h < vars; h++) {
                                        board[7] = variables[h];
                                        if(size == 8){
                                            if (is_equal(size)) return 0;
                                            continue;
                                        }
                                        for (i = 0; i < vars; i++) {
                                            board[8] = variables[i];
                                            if(size == 9){
                                                if (is_equal(size)) return 0;
                                                continue;
                                            }
                                            for (j = 0; j < vars; j++) {
                                                board[9] = variables[j];
                                                if(size == 10){
                                                    if (is_equal(size)) return 0;
                                                    continue;
                                                }
                                                for (k = 0; k < vars; k++) {
                                                    board[10] = variables[k];
                                                    if(size == 11){
                                                        if (is_equal(size)) return 0;
                                                        continue;
                                                    }
                                                    for (l = 0; l < vars; l++) {
                                                        board[11] = variables[l];
                                                        if(size == 12){
                                                            if (is_equal(size)) return 0;
                                                            continue;
                                                        }
                                                        for (m = 0; m < vars; m++) {
                                                            board[12] = variables[m];
                                                            if(size == 13){
                                                                if (is_equal(size)) return 0;
                                                                continue;
                                                            }
                                                            for (n = 0; n < vars; n++) {
                                                                board[13] = variables[n];
                                                                if(size == 14){
                                                                    if (is_equal(size)) return 0;
                                                                    continue;
                                                                }
                                                                for (o = 0; o < vars; o++) {
                                                                    board[14] = variables[o];
                                                                    if(size == 15){
                                                                        if (is_equal(size)) return 0;
                                                                        continue;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


bool is_equal(int chars) {

    for (position = 0; position < chars; position++)
        if (board[position] != guess[position]) return 0;

    if(guess[chars] == '\0'){
        std::cout << "Search complete: ";
        for (position = 0; position < chars; position++) std::cout << board[position];
        std::cout << std::endl;
        return 1;
    }

    return 0;
}
