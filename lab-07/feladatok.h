//
// Created by gkist on 2024.04.18.
//

#ifndef LAB_07_FELADATOK_H
#define LAB_07_FELADATOK_H

using namespace std;

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

typedef struct{
    char nev[25];
    int kal;
}KAJA;

void btKaloria(int maximumKaloria, KAJA *kajak, int index);
int cmp(const void*, const void*);
bool igeretesSorrend(const vector<string>& sequence);
bool isValid(const vector<string>& currentPermutation);
void generatePermutations(const vector<string>& dishes, vector<string>& currentPermutation, vector<bool>& used);
bool isValid2(const vector<string>& currentPermutation);
void generatePermutations2(const vector<string>& dishes, vector<string>& currentPermutation, vector<bool>& used, int *counter);

#endif //LAB_07_FELADATOK_H
