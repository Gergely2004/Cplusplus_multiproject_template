#include "functions.h"
#include <iostream>

using namespace std;

#ifndef LAB_08_FUNCTIONS_H
#define LAB_08_FUNCTIONS_H


#endif //LAB_08_FUNCTIONS_H

void backTrackingZaszlok(int *stack, char szinek[100][100], int k, int n, int m, int *vane, int &cnt) {
    if (k == m) {
        cnt++;
        for (int i = 0; i < k; ++i) {
            cout << szinek[stack[i]] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (k == (m / 2) + 1 && strcmp(szinek[stack[k - 1]], "piros") != NULL) {
            continue;
        }
        if (!vane[i]) {
            stack[k] = i;
            vane[i] = 1;
            backTrackingZaszlok(stack, szinek, k + 1, n, m, vane, cnt);
            vane[i] = 0;
        }
    }
}

bool palindromRK(char *word, int i, int j) {
    if (i < j) {
        if (word[i] != word[j]) {
            return false;
        } else {
            return palindromRK(word, i + 1, j - 1);
        }
    }
    return true;
}

void btEgerUt(int i, int j, int n, int m, int &count, int matrix[100][100]) {
    if(j == m - 1) {
        count++;
        //cout << "A";
        return;
    }
    if(i != 0) {
        if(matrix[i + 1][j + 1]) {
            btEgerUt(i + 1, j + 1, n, m, count, matrix);
        }
    }
    if(i != n) {
        if(matrix[i - 1][j + 1]) {
            btEgerUt(i - 1, j + 1, n, m, count, matrix);
        }
    }
    if(matrix[i][j + 1]) {
        btEgerUt(i, j + 1, n, m, count, matrix);
    }
}
