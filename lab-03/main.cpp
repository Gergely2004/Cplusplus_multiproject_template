#include <iostream>
#include "header3.h"

ifstream fin("date.txt");


int main() {
    int n;
    fin >> n;
    int *a = new int[n];
    read_array(a, n, fin);
    printArrayRec(a, n);
    cout << endl << endl;
    mirrorNumbersInArray(a, n);
    cout << endl << endl;
    //mirrorNumbersInArrayRec(a, n);
    mergesort(a, 0, n - 1);
    printArrayRec(a, n);

    return 0;
}
