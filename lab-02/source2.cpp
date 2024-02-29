#include "header2.h"

using namespace std;

int lnkoRec(int a, int b) {
    if(a % b == 0) return b;
    else return lnkoRec(b, a % b);
}

int lkktRec(int a, int b, int a1, int b1) {
    if(a1 % b1 == 0) return (a * b) / b1;
    else return lkktRec(a, b, b1, a1 % b1);
}

int powerRec(int b, int e) {
    if(e == 0) return 1;
    return b * powerRec(b, e - 1);
}

void readArrayRec(int *a, int n, ifstream &f) {
    if(n > 0) readArrayRec(a, n - 1, f);
    f >> a[n - 1];
}

void printArrayRec(int *a, int n) {
    if(n > 0) printArrayRec(a, n - 1);
    cout << a[n - 1];
}

int sumArrayRec(int *a, int n) {
    if(n == 1) return a[0];
    return a[n - 1] + sumArrayRec(a, n - 1);
}

int maxArrayRec(int *a, int n, int max) {
    int x;
    if(n > 0) {
        max = a[n - 1];
        x = maxArrayRec(a, n - 1, max);
        if(x > max) return x;
        else return max;
    }
    else
        return a[0];
}

int lnkoArrayRec(int *a, int n) {
    if(n > 1)
        return lnkoRec(a[n], lnkoArrayRec(a, n - 1));
    else
        return lnkoRec(a[0], a[1]);
}

void digitsNumberRec(int n) {
    if(n < 10) cout << n % 10 << " ";
    else {
        digitsNumberRec(n / 10);
        cout << n % 10 << " ";
    }

}

int inverseNumber(int n, int fn) {
    if(n < 10) {
        return fn * 10 + n;
    }
    else {
        fn = fn * 10 + n % 10;
        return inverseNumber(n / 10, fn);
    }
}
