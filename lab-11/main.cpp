#include <iostream>
#include <fstream>
#include "feladat.h"

using namespace std;

ifstream fin("szemelyek.txt");
ifstream fin1("beka.txt");
ifstream fin2("kecske.txt");
int dx[8] = {-1, -1, -1, 0, 1, 1, 1,  0}; 
int dy[8] = {-1,  0,  1, 1, 1, 0,-1, -1}; 


int cmp(const void *p1, const void *p2);

int binariskereses(int *arr, int l, int r, int keresettElem);

void mohoBeka(int **a, int i, int j, int &s);

void matrixMinimum(int **a, int n, int m, int &sor, int &osz);
void matrixMaximum(int **a, int n, int m, int &sor, int &osz);

bool igeretesKecske(int **stack, int k, int **a);

void backKecske(int **stack, int k, int **a, int i, int j, int sorMax, int oszMax, int n, int m, int &cnt);

void kiirKecske(int **stack, int k, int **a);

bool validPosition(int i, int j, int n, int m);


void exercise1() {
    int n;
    fin >> n;
    PERSON arr[n];
    for (int i = 0; i < n; ++i) {
        /*char enter[2];
        fin.getline(enter, 2);*/
        fin.ignore();     //kovetkezo sorba ugrik
        fin.getline(arr[i].name, 25);
        fin >> arr[i].year >> arr[i].gender >> arr[i].level;
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i].name << " " << arr[i].year << " " << arr[i].gender << " " << arr[i].level << endl;
    }

    cout << endl << "*******************" << endl;

    qsort(arr, n, sizeof(PERSON), cmp);
    for (int i = 0; i < n; ++i) {
        cout << arr[i].name << " " << arr[i].year << " " << arr[i].gender << " " << arr[i].level << endl;
    }

    cout << endl << "*******************" << endl;

    int osszeg = 0;
    for (int i = 0; i < n - 1; ++i) {
        cout << arr[i].name << endl;
        osszeg += arr[i].level * 2;
    }
    cout << arr[n - 1].name << endl;
    cout << endl << "OSSZEG: " << osszeg << endl;

    for (int i = 0; i < n; ++i) {
        cout << arr[i].name << " " << arr[i].year << " " << arr[i].gender << " " << arr[i].level << endl;
    }
}

void exercise2() {
    int arr[100] = {2, 4, 7, 8, 9, 10, 12};
    int n = 7;
    int l = 0, r = n - 1;
    int keresettElem = 8;
    int result;
    result = binariskereses(arr, l, r, keresettElem);
    cout << result;
}

void exercise3() {
    int n, i, j;
    fin1 >> n;
    i = 0;
    j = n - 1;
    int S = 0;
    int **a = new int*[2];
    for (int i = 0; i < 2; ++i)
        a[i] = new int[n];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            fin1 >> a[i][j];
        }
    }
    mohoBeka(a, i, j, S);
    cout << S << endl;
}

int main() {
    int feladatszam;
    cout << "Hanyas feladatot oldod: ";
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
        case 4: {
            int n, m, sorMin = 0, oszMin = 0, sorMax = INT_MAX, oszMax = INT_MAX;
            int cnt = 0;
            fin2 >> n >> m;
            int **st = new int*[n * m];  //din. helyf. stack-nek, espedig i, j... azaz 2 oszlopos verem
            for (int i = 0; i < n * m; ++i)
                st[i] = new int[2];
            int **a = new int*[n];  //din. helyf. matrixnak
            for (int i = 0; i < n; ++i)
                a[i] = new int[m];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    fin2 >> a[i][j];
                }
            }
            matrixMinimum(a, n, m, sorMin, oszMin);
            matrixMaximum(a, n, m, sorMax, oszMax);
            //void backKecske(int **stack, int k, int **a, int i, int j, int maxSor, int maxOsz) {
            backKecske(st, 0, a, sorMin, oszMin, sorMax, oszMax, n, m, cnt);
            break;
        }
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    PERSON *p1 = (PERSON *) a;
    PERSON *p2 = (PERSON *) b;
    return p1->level - p2->level;
}

int binariskereses(int *arr, int l, int r, int keresettElem) {
    int m = (r - l) / 2 + l;
    if (l > r) {
        return -8;
    }
    if (arr[m] == keresettElem) {
        return m;
    } else {
        if (arr[m] < keresettElem) {
            return binariskereses(arr, m + 1, r, keresettElem);
        } else {
            return binariskereses(arr, l, m - 1, keresettElem);
        }
    }
}

void mohoBeka(int **a, int i, int j, int &s) {
    s += a[i][j];
    if (j > 0) {
        if (a[0][j - 1] < 0 && a[1][j - 1] < 0) {
            if (a[0][j - 2] > a[1][j - 2]) {
                mohoBeka(a, 0, j - 2, s);
            } else {
                mohoBeka(a, 1, j - 2, s);
            }
        } else {
            if (a[0][j - 1] > a[1][j - 1]) {
                mohoBeka(a, 0, j - 1, s);
            } else {
                mohoBeka(a, 1, j - 1, s);
            }
        }
    }
}

void matrixMinimum(int **a, int n, int m, int &sor, int &osz) {
    int min = a[0][0];
    sor = 0, osz = 0;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i][j] < min) {
                min = a[i][j];
                sor = i, osz = j;
            }
        }
    }
}

void matrixMaximum(int **a, int n, int m, int &sor, int &osz) {
    int max = a[0][0];
    sor = 0, osz = 0;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i][j] > max) {
                max = a[i][j];
                sor = i, osz = j;
            }
        }
    }
}

bool igeretesKecske(int **stack, int k, int **a) {
    for (int i = 0; i < k - 1; ++i) {
        if(stack[k][0] == stack[i][0] && stack[k][1] == stack[i][1]) { return false; }
    }
    if(k >= 1) {
        if(a[stack[k][0]][stack[k][1]] < a[stack[k - 1][0]][stack[k - 1][1]]) {
            return false;
        }
    }
    return true;
}

/*void backTrackingKombinaciok(int *a, char **sutik, int n, int m, int k, int &cnt) {
    for (a[k] = 1; a[k] <= n; ++a[k]) {
        if(igeretes2(a, k)) {
            if (k < m - 1) {
                backTrackingKombinaciok(a, sutik, n, m, k + 1, cnt);
            }
            else {
                cnt++;
                kiirSutik(a, m, sutik);
            }
        }
    }
}*/


void backKecske(int **stack, int k, int **a, int i, int j, int sorMax, int oszMax, int n, int m, int &cnt) {
    stack[k][0] = i; stack[k][1] = j;
    if(igeretesKecske(stack, k, a)) {
        if(a[stack[k][0]][stack[k][1]] < a[sorMax][oszMax]) {
            for (int ind = 0; ind < 8; ++ind) {   //vegig megyunk a dx es dy tombokon parhuzamosan
                if(validPosition(i + dx[ind], j + dy[ind], n, m)) {
                    backKecske(stack, k + 1, a, i + dx[ind], j + dy[ind], sorMax, oszMax, n, m, cnt);
                }
            }
        } else {
            cnt++;
            cout << cnt << ". megoldas" << endl;
            kiirKecske(stack, k, a);
        }
    }
}

bool validPosition(int i, int j, int n, int m) {
    if(i < 0 || i > n) { return false; }
    if(j < 0 || j > m) { return false; }
    return true;
}

void kiirKecske(int **stack, int k, int **a) {
    for (int i = 0; i <= k; ++i) {
        cout << stack[i][0] << " " << stack[i][1] << ": " << a[stack[i][0]][stack[i][1]] << endl;
    }
    cout << "*********" << endl;
}