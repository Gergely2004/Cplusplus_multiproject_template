#include <fstream>
#include <iostream>

using namespace std;

#ifndef LAB_02_HEADER2_H
#define LAB_02_HEADER2_H

int lnkoRec(int a, int b);
int lkktRec(int a, int b, int a1, int b1);
int powerRec(int b, int e);
void readArrayRec(int *a, int n, ifstream &f);
void printArrayRec(int *a, int n);
int sumArrayRec(int *a, int n);
int maxArrayRec(int *a, int n, int max);
int lnkoArrayRec(int *a, int n);
void digitsNumberRec(int n);
int inverseNumber(int n, int fn);

#endif
