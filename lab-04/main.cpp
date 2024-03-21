#include <iostream>
using namespace std;

void backTracking(int *a, int n, int k, int &cnt);

void kiir(int *pInt, int n);

int main() {
    int n = 4;
    int *a = new int[n];
    int cnt = 0;
    backTracking(a, n, 0, cnt);
    cout << endl;
    cout << cnt;
    return 0;
}

void backTracking(int *a, int n, int k, int &cnt) {
    for (a[k] = 0; a[k] <= 9; ++a[k]) {
        if (k < n - 1) {
            backTracking(a, n, k + 1, cnt);
        }
        else {
            cnt++;
            kiir(a, n);
        }
    }
}

void kiir(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << " ";
}
