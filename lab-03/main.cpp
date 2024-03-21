#include <iostream>
#include <climits>
#include "header3.h"

ifstream fin("date.txt");


int main() {
    int n;
    fin >> n;
    int *a = new int[n];
    read_array(a, n, fin);
    //quickSort(a, 0, );
    printArrayRec(a, n);
    cout << endl << endl;
    cout << "A tomb maximuma " << maxArrayRec(a, n, INT_MIN) << endl;
    cout << "A tomb maximumanak indexe: " << maxindex(a, 0, n - 1) << endl << endl;
    cout << "A tombben egymassal tukor kapcsolatban levo szamok: ";
    mirrorNumbersInArray(a, n);
    cout << endl << endl;
    mergesort(a, 0, n - 1);
    cout << endl;

    printArrayRec(a, n);

    return 0;
}
