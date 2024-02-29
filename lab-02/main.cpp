#include <iostream>
#include <fstream>
#include "header2.h"

using namespace std;

ifstream f("be.txt");

int main() {
    int feladatszam;
    cout << "Olvasd be a feladat szamat: ";
    cin >> feladatszam;
    switch (feladatszam) {
        case 1: {
            int x, y;
            cout << "Olvasd be a ket szamot: ";
            cin >> x >> y;
            cout << "A ket szam legnagyobb kozos osztoja: "<< lnkoRec(x, y);
            break;
        }
        case 2: {
            int x, y, lcm;
            cout << "Olvasd be a ket szamot: ";
            cin >> x >> y;
            lcm = lkktRec(x, y, x,y);
            cout << "A ket szam legkisebb kozos tobbszorose: " << lcm;
            break;
        }
        case 3: {
            int x, y, lcm;
            cout << "Olvasd be a ket szamot: ";
            cin >> x >> y;
            lcm = powerRec(x, y);
            cout << "x ^ y = " << lcm;
            break;
        }
        case 4: /* es 5 */ {
            int n;
            cout << "Olvasd be a tomb hosszat: ";
            cin >> n;
            int a[n];
            readArrayRec(a, n, f);
            printArrayRec(a, n);
            break;
        }
        case 6: {
            int n;
            cout << "Olvasd be a tomb hosszat: ";
            cin >> n;
            int a[n];
            readArrayRec(a, n, f);
            int sum = sumArrayRec(a, n);
            cout << "A tomb elemeinek osszege: " << sum;
            break;
        }
        case 7: {
            int n;
            cout << "Olvasd be a tomb hosszat: ";
            cin >> n;
            int a[n];
            readArrayRec(a, n, f);
            int max = maxArrayRec(a, n, a[n - 1]);
            cout << "A tomb elemeinek osszege: " << max;
            break;
        }
        case 8: {
            int n;
            cout << "Olvasd be a tomb hosszat: ";
            cin >> n;
            int a[n];
            readArrayRec(a, n, f);
            cout << "A tomb elemeinek legnagyobb kozos osztoja: " << lnkoArrayRec(a, n);
            break;
        }
        case 9: {
            int x;
            cout << "Olvasd be a szamot: ";
            cin >> x;
            digitsNumberRec(x);
            break;
        }
        case 10: {
            int n, invn = 0;
            cout << "Olvasd be a szamot: ";
            cin >> n;
            invn = inverseNumber(n, invn);
            cout << "A szam forditottja: " << invn;
        }

    }
    return 0;
}
