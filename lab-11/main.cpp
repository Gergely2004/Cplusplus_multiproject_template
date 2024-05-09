#include <iostream>
#include <fstream>
#include "feladat.h"
using namespace std;

ifstream fin("szemelyek.txt");

int cmp(const void *p1, const void *p2);
int binariskereses(int *arr, int l, int r, int keresettElem);

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
    }
    return 0;
}

int cmp(const void *a, const void *b){
    PERSON *p1 = (PERSON *)a;
    PERSON *p2 = (PERSON *)b;
    return p1->level - p2->level;
}


int binariskereses(int *arr, int l, int r, int keresettElem){
    int m = (r - l) / 2 + l;
    if(l > r){
        return -8;
    }
    if(arr[m] == keresettElem){
        return m;
    }
    else
    {
        if(arr[m] < keresettElem){
            return binariskereses(arr, m + 1, r, keresettElem);
        }
        else
        {
            return binariskereses(arr, l, m - 1, keresettElem);
        }
    }
}
