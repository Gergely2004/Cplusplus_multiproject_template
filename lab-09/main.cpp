#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

ifstream fin("szinek.txt");

int main()
{
    int feladatszam;
    cout << "Olvasd be a feladat szamat:" << endl;
    cin >> feladatszam;
    switch (feladatszam) {
        case 1: {
            int n;
            fin >> n;
            char szinek[100][100];
            for (int i = 0; i < n; ++i) {
                fin >> szinek[i];
            }
            int m;
            cout << "Hany szinbol akarsz zaszlot?" << endl;
            cin >> m;
            int stack[100], vane[100] = {0};
            int cnt = 0;
            backTrackingZaszlok(stack, szinek, 0, n, m, vane, cnt);
            cout << cnt;
            break;
        }
        case 2: {
            char word[50];
            cin >> word;
            for (int i = 0; i < strlen(word); ++i) {
                if(!isalpha(word[i])) {
                    strcpy(word + i, word + i + 1);
                    i--;
                } else {
                    word[i] = tolower(word[i]);

                }
            }
            cout << word << endl;
            cout << "Palindrom: " << palindromRK(word, 0, strlen(word) - 1);
            break;
        }
        case 3: {
            int matrix[100][100] = {{1, 1, 1, 1}, {1, 1, 1, 0}, {1, 0, 0, 1}};
            int n = 3, m = 4;
            int count = 0;
            for (int i = 0; i < n; ++i) {
                btEgerUt(i, 0, n, m, count, matrix);
            }
            cout << count;
        }

    }
    return 0;
}
