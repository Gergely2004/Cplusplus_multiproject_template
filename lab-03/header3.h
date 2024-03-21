#include <iostream>
#include <fstream>
using namespace std;

#ifndef LAB_03_HEADER3_H
#define LAB_03_HEADER3_H

void read_array(int *a, int n,  ifstream  &fin);
void printArrayRec(int *a, int n);
int inverseNumberGenerator(int x);
void mirrorNumbersInArray(int *a, int n);
void mirrorNumbersInArrayRec(int *a, int n);

void mergesort(int *, int i, int j);
void osszefesul(int *, int i, int k, int j);
int maxArrayRec(int *a, int n, int max);
int maxindex(int *a, int i, int j);

void quickSort(int *a, int i, int j, int k);
int partition(int *a, int i, int j);

#endif //LAB_03_HEADER3_H
