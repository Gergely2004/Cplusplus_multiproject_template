#include <iostream>
#include <fstream>
#include "feladat.h"

using namespace std;

ifstream fin("szemelyek.txt");
ifstream fin1("beka.txt");
ifstream fin2("kecske.txt");
ifstream fin3("hegymaszo.txt");

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};


int cmp(const void *p1, const void *p2);

int binariskereses(int *arr, int l, int r, int keresettElem);

void mohoBeka(int **a, int i, int j, int &s);

void matrixMinimum(int **a, int n, int m, int &sor, int &osz);
void matrixMaximum(int **a, int n, int m, int &sor, int &osz);
bool igeretesKecske(int **stack, int k, int **a);
void backKecske(int **stack, int k, int **a, int i, int j, int sorMax, int oszMax, int n, int m, int &cnt);
void kiirKecske(int **stack, int k, int **a);
bool validPosition(int i, int j, int n, int m);

bool igeretesKiralyno(int *stack, int k);
void backKiralyno(int *stack, int k, int n);
void kiirKiralyno(int *stack, int n);

bool igeretesBastya(int *stack, int k);
void backBastya(int *stack, int k, int n);
void kiirBastya(int *stack, int n);

bool mohoHegymaszo(int **a, int n, int m, int i, int j, int sorMax, int oszMax, int k);
int szomszedMax(int **a, int n, int m, int i, int j, int &maxk);

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
    int keresettElem = 122;
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
    int **a = new int *[2];
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
            int **st = new int *[n * m];  //din. helyf. stack-nek, espedig i, j... azaz 2 oszlopos verem
            for (int i = 0; i < n * m; ++i)
                st[i] = new int[2];
            int **a = new int *[n];  //din. helyf. matrixnak
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
        case 5: {
            int n, m, sorMin = 0, oszMin = 0, sorMax = INT_MAX, oszMax = INT_MAX;
            int cnt = 0;
            fin3 >> n >> m;
            int **a = new int *[n];  //din. helyf. matrixnak
            for (int i = 0; i < n; ++i)
                a[i] = new int[m];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    fin3 >> a[i][j];
                }
            }

            matrixMinimum(a, n, m, sorMin, oszMin);
            matrixMaximum(a, n, m, sorMax, oszMax);
            int k = 0;
            if(mohoHegymaszo(a, n, m, sorMin, oszMin, sorMax, oszMax, k)) {
                cout << "A hegymaszo kiert a hegy tetejere." << endl;
            } else {
                cout << "A hegymaszo nem er ki a hegy tetejere." << endl;
            }

            break;
        }
        case 6: {
            int n;
            cout << "Olvasd be az n-t: ";
            cin >> n;
            int **sakk = new int *[n];
            for (int i = 0; i < n; ++i) {
                sakk[i] = new int[n];
            }
            int *st = new int[100];
            backKiralyno(st, 0, n);
            backBastya(st, 0, n);
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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] < min) {
                min = a[i][j];
                sor = i, osz = j;
            }
        }
    }
}

void matrixMaximum(int **a, int n, int m, int &sor, int &osz) {
    int max = a[0][0];
    sor = 0, osz = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > max) {
                max = a[i][j];
                sor = i, osz = j;
            }
        }
    }
}

bool igeretesKecske(int **stack, int k, int **a) {
    for (int i = 0; i < k - 1; ++i) {
        if (stack[k][0] == stack[i][0] && stack[k][1] == stack[i][1]) { return false; }
    }
    if (k >= 1) {
        if (a[stack[k][0]][stack[k][1]] <= a[stack[k - 1][0]][stack[k - 1][1]]) {
            return false;
        }
    }
    return true;
}

void backKecske(int **stack, int k, int **a, int i, int j, int sorMax, int oszMax, int n, int m, int &cnt) {
    stack[k][0] = i;
    stack[k][1] = j;
    if (igeretesKecske(stack, k, a)) {
        if (a[stack[k][0]][stack[k][1]] < a[sorMax][oszMax]) {
            for (int ind = 0; ind < 8; ++ind) {   //vegig megyunk a dx es dy tombokon parhuzamosan
                if (validPosition(i + dx[ind], j + dy[ind], n, m)) {
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
    if (i < 0 || i > n - 1) { return false; }
    if (j < 0 || j > m - 1) { return false; }
    return true;
}

void kiirKecske(int **stack, int k, int **a) {
    for (int i = 0; i <= k; ++i) {
        cout << stack[i][0] << " " << stack[i][1] << ": " << a[stack[i][0]][stack[i][1]] << endl;
    }
    cout << "*********" << endl;
}

bool igeretesKiralyno(int *stack, int k) {
    for (int i = 1; i < k; ++i) {
        if (abs(k - i) == abs(stack[k] - stack[i])) { return false; }
        if (stack[k] == stack[i]) { return false; }
    }
    return true;
}

void backKiralyno(int *stack, int k, int n) {
    for (int i = 1; i <= n; ++i) {
        stack[k] = i;
        if (igeretesKiralyno(stack, k)) {
            if (k == n) {
                kiirKiralyno(stack, n);
            } else {
                backKiralyno(stack, k + 1, n);
            }
        }
    }
}

void kiirKiralyno(int *stack, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(stack[i] == j) {
                cout << "Q ";
            }
            else {
                cout << "– ";
            }
        }
        cout << endl;
    }
    cout << endl << "*********" << endl;
}

bool igeretesBastya(int *stack, int k) {
    for (int i = 1; i < k; ++i) {
        if (stack[k] == stack[i]) { return false; }
    }
    return true;
}

void backBastya(int *stack, int k, int n) {
    for (int i = 1; i <= n; ++i) {
        stack[k] = i;
        if (igeretesBastya(stack, k)) {
            if (k == n) {
                kiirBastya(stack, n);
            } else {
                backBastya(stack, k + 1, n);
            }
        }
    }
}

void kiirBastya(int *stack, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(stack[i] == j) {
                cout << "B ";
            }
            else {
                cout << "– ";
            }
        }
        cout << endl;
    }
    cout << endl << "*********" << endl;
}

bool mohoHegymaszo(int **a, int n, int m, int i, int j, int sorMax, int oszMax, int k) {
    if(a[i][j] == a[sorMax][oszMax]) {
        cout << i << "," << j << ": " << a[i][j] << endl;
        return true;
    }
    if(szomszedMax(a, n, m, i, j, k) > a[i][j]) {
        cout << i << "," << j << ": " << a[i][j] << endl;
        return mohoHegymaszo(a, n, m, i + dx[k], j + dy[k], sorMax, oszMax, k);
    }
    return false;
}

int szomszedMax(int **a, int n, int m, int i, int j, int &maxk) {
    int maxValue = 0;
    for (int k = 0; k < 8; ++k) {
        if(validPosition(i + dx[k], j + dy[k], n, m)) {
            if(a[i + dx[k]][j + dy[k]] > maxValue) {
                maxValue = a[i + dx[k]][j + dy[k]];
                maxk = k;
            }
        }
    }
    return maxValue;
}