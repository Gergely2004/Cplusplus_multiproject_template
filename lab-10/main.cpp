#include "header.h"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void exercise1() {
    vector<int> coins = {2, 3, 5}; // Example coins
    int S = 11; // Example sum to pay
    vector<int> coinsUsed = minCoinsUsed(coins, S);
    cout << "Coins used for payment: ";
    for (int coin: coinsUsed) {
        cout << coin << " ";
    }
    cout << endl;
}

void exercise2() {
    int c[100][100];
    int a[] = {19, 2, 4, 16, 3, 15, 4, 14, 17, 1};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; ++i) {
        c[i][i] = 0;
    }
    for (int k = 1; k < n; k += 2) {
        for (int i = 0, j = k; j < n; ++i, ++j) {
            c[i][j] = max(a[i] + min(c[i + 1][j - 1], c[i + 2][j]),
                          a[j] + min(c[i + 1][j - 1], c[i][j - 2]));
        }
    }

    printf("Maximal sum: %i\n", c[0][n - 1]);
}

void exercise3() {
    int e[][5] = {{7, 23, -5, -24, 16},
                  {500, 21, -4, 10, 23},
                  {100, 500, -4, -20, 20}};
    int n = 3, m = 5;

    int c[n + 1][m + 1];
    for (int i = 0; i <= m - n; ++i) {
        c[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        c[i][i] = c[i - 1][i - 1] + e[i - 1][i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= m - n + i; ++j) {
            c[i][j] = max(c[i - 1][j - 1] + e[i - 1][j - 1], c[i][j - 1]);
        }
    }
    printf("Matrix c:\n");
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            printf("%4d ", c[i][j]);
        }
        printf("\n");
    }
    printf("%d", c[n][m]);
}

int main() {
    int feladatszam;
    cout << "Hanyas feladatot szeretned megoldani: ";
    cin >> feladatszam;
    switch (feladatszam) {
        case 1: {
            exercise1();
            break;
        }
        case 2: {
            exercise2();
            break;
        }
        case 3: {
            exercise3();
            break;
        }
    }
    return 0;
}