#include <iostream>
using namespace std;

void backTrackingKerekparzar(int *a, int n, int k, int &cnt);
void backTrackingDescartes(int *a, char *A, int *B, char C[][10], int n, int k, int &cnt);
void kiir1(int *a, int n);
void kiir2(int *a, char *A, int *B, char C[][10], int n);
void kiir3(int *a, int n);
bool igeretes1(int *a, int k);
bool igeretes2(int *x, int k);
void backTrackingPermutaciok(int *x, int n, int k, int &cnt);
void backTrackingVariaciok(int *a, int n, int m, int k, int &cnt);
void backTrackingKombinaciok(int *a, int n, int m, int k, int &cnt);
void Reszhalmazok(int *a, int n, int k, int &cnt);


int main() {
    int n = 3, m = 2;
    int *a = new int[n];
    char A[3] = {'a', 'b', 'c'};
    int B[3] = {100, 300, 500};
    char C[3][10] = {"Csilla", "Peter", "Attila"};
    int cnt = 0;
    //backTrackingKerekparzar(a, n, 0, cnt);
    //backTrackingDescartes(a, A, B, C, n, 0, cnt);
    //backTrackingPermutaciok(a, n, 0, cnt);
    //backTrackingVariaciok(a, n, m, 0, cnt);
    //backTrackingKombinaciok(a, n, m, 0, cnt);
    Reszhalmazok(a, n, 0, cnt);
    cout << endl;
    cout << cnt;
    return 0;
}

void backTrackingKerekparzar(int *a, int n, int k, int &cnt) {
    for (a[k] = 1; a[k] <= 9; a[k] += 2) {
        if (k < n - 1) {
            backTrackingKerekparzar(a, n, k + 1, cnt);
        }
        else {
            cnt++;
            kiir1(a, n);
        }
    }
}

void backTrackingDescartes(int *a, char *A, int *B, char C[][10], int n, int k, int &cnt) {
    for (a[k] = 1; a[k] <= n; ++a[k]) {
        if (k < n - 1) {
            backTrackingDescartes(a, A, B, C, n, k + 1, cnt);
        }
        else {
            cnt++;
            kiir2(a, A, B, C, n);
        }
    }
}

void backTrackingPermutaciok(int *a, int n, int k, int &cnt) {
    for (a[k] = 1; a[k] <= n; ++a[k]) {
        if(igeretes1(a, k)) {
            if (k < n - 1) {
                backTrackingPermutaciok(a, n, k + 1, cnt);
            }
            else {
                cnt++;
                kiir1(a, n);
            }
        }
    }
}

void backTrackingVariaciok(int *a, int n, int m, int k, int &cnt) {
    for (a[k] = 1; a[k] <= n; ++a[k]) {
        if(igeretes1(a, k)) {
            if (k < m - 1) {
                backTrackingVariaciok(a, n, m, k + 1, cnt);
            }
            else {
                cnt++;
                kiir1(a, m);
            }
        }
    }
}

void backTrackingKombinaciok(int *a, int n, int m, int k, int &cnt) {
    for (a[k] = 1; a[k] <= n; ++a[k]) {
        if(igeretes2(a, k)) {
            if (k < m - 1) {
                backTrackingKombinaciok(a, n, m, k + 1, cnt);
            }
            else {
                cnt++;
                kiir1(a, m);
            }
        }
    }
}

void Reszhalmazok(int *a, int n, int k, int &cnt) {
    for (a[k] = 0; a[k] <= 1; ++a[k]) {
        if (k < n - 1) {
            Reszhalmazok(a, n, k + 1, cnt);
        }
        else {
            cnt++;
            kiir3(a, n);
        }
    }
}

void kiir1(int *a, int n){
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << " ";
}

void kiir2(int *a, char *A, int *B, char C[][10], int n) {
    for(int i = 0; i < n; ++i) {
        if(i == 0) {cout << A[a[i] - 1];}
        if(i == 1) {cout << B[a[i] - 1];}
        if(i == 2) {cout << C[a[i] - 1];}
    }
    cout << " ";
}

void kiir3(int *a, int n){
    for (int i = 0; i < n; ++i) {
        if(a[i] == 1)
            cout << i + 1;
    }
    cout << " ";
}

bool igeretes1(int *x, int k) {
    for(int i = 0; i <= k - 1; ++i) {
        if(x[i] == x[k])
            return false;
    }
    return true;
}

bool igeretes2(int *x, int k) {
    for(int i = 0; i <= k - 1; ++i) {
        if(x[i] >= x[k])
            return false;
    }
    return true;
}