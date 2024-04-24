#include "feladatok.h"

//Matrix bejarasa foatlo alatt, fentrol az also sorig
void bt1(int i, int j, int mat[][5], int n, int s, int *maximum){
    s += mat[i][j];
    if(i == n - 1){
        cout << s << " ";
        if(s < *maximum){
            *maximum = s;
        }
        return;
    }
    else
    {
        bt1(i + 1, j, mat, n, s, maximum);
        bt1(i + 1, j + 1, mat, n, s, maximum);
    }
}

void dp1(int mat[][5], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j == 0 && i > 0){
                mat[i][j] += mat[i - 1][j];
            }
            else if(i == j)
            {
                mat[i][j] += mat[i - 1][j - 1];
            }
            else
            {
                if(mat[i - 1][j] < mat[i - 1][j - 1]){
                    mat[i][j] += mat[i - 1][j];
                }
                else
                {
                    mat[i][j] += mat[i - 1][j - 1];
                }
            }
        }
    }
}


int main() {
    int feladatszam;
    cout << "Olvasd be a feladat szamat: ";
    cin >> feladatszam;

    int mat[5][5] = {{7, 2, 8, 9, 0}, {9, 5, 0 ,0, 0}, {1, 99, 4, 0, 0},
                     {21, 7, 33, 17, 0}, {2, 15, 8, 3, 1}};
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int maximum = INT_MAX;
    bt1(0, 0, mat, 5, 0, &maximum);
    cout << endl << maximum;

    cout << endl;
    dp1(mat, 5);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    switch (feladatszam) {
        case 1 /*1. feladat*/: {
            vector<string> dishes = {"spenotos gomba", "zoldseg a lerben", "dioval toltott korte",
                                     "vanilias es kozos Panna cotta", "fuges salata", "citromtorta"};

            vector<bool> used(dishes.size(), false);
            vector<string> currentPermutation;
            generatePermutations(dishes, currentPermutation, used);
            break;
        }
        case 2: {
            KAJA kajak[7] = {{"gomba", 200}, {"zoldseg", 250}, {"korte", 300}, {"Panna-cotta", 400}, {"salata", 350}, {"torta", 500}};
            qsort(kajak, 6, sizeof(KAJA), cmp);
            btKaloria(500, kajak, 0);
            break;
        }
        case 3: {
            vector<string> items = {"rovid ujju ing", "picus nyakkendo", "zako", "nadrag", "cipo", "zokni"};
            vector<bool> used(items.size(), false);
            vector<string> currentPermutation;
            int counter = 0;
            generatePermutations2(items, currentPermutation, used, &counter);
            printf("counter: %i", counter);
            break;
        }

    }
    return 0;
}
