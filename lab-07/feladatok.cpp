//
// Created by gkist on 2024.04.18.
//

#include "feladatok.h"

void btKaloria(int maximumKaloria, KAJA *kajak, int index) {
    if(maximumKaloria - kajak[index].kal >= 0){
        printf("%s ", kajak[index].nev);
        btKaloria(maximumKaloria - kajak[index].kal, kajak, index + 1);
    }
    else if(index == 0){
        printf("Nem ehet semmit");
    }
}

int cmp(const void *p1, const void *p2) {
    KAJA * a = (KAJA *) p1;
    KAJA * b = (KAJA *) p2;
    return a->kal - b->kal;
}

bool igeretesSorrend(const vector<string>& sequence) {
    for (int i = 0; i < sequence.size() - 1; ++i) {
        if (sequence[i] == "spenotos gomba") {
            for (int j = 0; j < i; ++j) {
                if (sequence[j] == "zoldseg a lerben") {
                    return false;
                }
            }
        }
        else if (sequence[i] == "zoldseg a lerben") {
            for (int j = 0; j < i; ++j) {
                if (sequence[j] == "fuges salata") {
                    return false;
                }
            }
        }
        else if (sequence[i] == "citromtorta" || sequence[i] == "dioval toltott korte") {
            for (int j = 0; j < i; ++j) {
                if (sequence[j] == "vanilias es kozos Panna cotta") {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isValid(const vector<string>& currentPermutation) {
    auto gombaPos = find(currentPermutation.begin(), currentPermutation.end(), "spenotos gomba");
    auto zoldsegPos = find(currentPermutation.begin(), currentPermutation.end(), "zoldseg a lerben");
    if (gombaPos != currentPermutation.end() && zoldsegPos != currentPermutation.end() && gombaPos > zoldsegPos)
        return false;

    auto salataPos = find(currentPermutation.begin(), currentPermutation.end(), "fuges salata");
    if (zoldsegPos != currentPermutation.end() && salataPos != currentPermutation.end() && zoldsegPos > salataPos)
        return false;

    auto tortaPos = find(currentPermutation.begin(), currentPermutation.end(), "citromtorta");
    auto kortePos = find(currentPermutation.begin(), currentPermutation.end(), "dioval toltott korte");
    auto pannaPos = find(currentPermutation.begin(), currentPermutation.end(), "vanilias es kozos Panna cotta");
    if ((tortaPos != currentPermutation.end() || kortePos != currentPermutation.end()) &&
        pannaPos != currentPermutation.end() && (tortaPos > pannaPos || kortePos > pannaPos))
        return false;

    return true;
}

void generatePermutations(const vector<string>& dishes, vector<string>& currentPermutation, vector<bool>& used)
{
    if(!isValid(currentPermutation))
    {
        return;
    }
    if (currentPermutation.size() == dishes.size()) {
        for (const string &dish: currentPermutation) {
            cout << dish << ", ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < dishes.size(); ++i) {
        if (!used[i]) {
            currentPermutation.push_back(dishes[i]);
            used[i] = true;
            generatePermutations(dishes, currentPermutation, used);
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
}

bool isValid2(const vector<string>& currentPermutation) {
    auto ingPos = find(currentPermutation.begin(), currentPermutation.end(), "rovid ujju ing");
    auto nyakkendoPos = find(currentPermutation.begin(), currentPermutation.end(), "picus nyakkendo");
    auto zakoPos = find(currentPermutation.begin(), currentPermutation.end(), "zako");
    auto nadragPos = find(currentPermutation.begin(), currentPermutation.end(), "nadrag");
    auto cipoPos = find(currentPermutation.begin(), currentPermutation.end(), "cipo");
    auto zokniPos = find(currentPermutation.begin(), currentPermutation.end(), "zokni");

    if (ingPos != currentPermutation.end() && nyakkendoPos != currentPermutation.end() && ingPos > nyakkendoPos)
        return false;
    if (nyakkendoPos != currentPermutation.end() && zakoPos != currentPermutation.end() && nyakkendoPos > zakoPos)
        return false;
    if ((zokniPos != currentPermutation.end() || nadragPos != currentPermutation.end()) && cipoPos != currentPermutation.end() && (zokniPos > cipoPos || nadragPos > cipoPos))
        return false;

    return true;
}

void generatePermutations2(const vector<string>& dishes, vector<string>& currentPermutation, vector<bool>& used, int *counter)
{
    if(!isValid2(currentPermutation))
    {
        return;
    }
    if (currentPermutation.size() == dishes.size()) {
        if(currentPermutation[0] == "rovid ujju ing" && currentPermutation[1] == "picus nyakkendo"){
            (*counter) ++;
        }
        for (const string &dish: currentPermutation) {
            cout << dish << ", ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < dishes.size(); ++i) {
        if (!used[i]) {
            currentPermutation.push_back(dishes[i]);
            used[i] = true;
            generatePermutations2(dishes, currentPermutation, used, counter);
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
}