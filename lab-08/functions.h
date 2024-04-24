//
// Created by gkist on 2024.04.18.
//

#ifndef LAB_08_FUNCTIONS_H
#define LAB_08_FUNCTIONS_H

typedef struct {
    int id;
    int points;
    float time;
}EXAM;

//exercise1
void kiirHalmaz_Szamt1(int *a, int *st, int k);

bool igeretesHalmaz_Szamt1(int *a, int *st, int k, int s, int &sp);

void backHalmaz_Szamt1(int *a, int n, int *st, int k, int s, int &cnt);

//exercise2

void kiirVizsgak(EXAM *a, int *st, int k);

bool igeretesVizsgak(EXAM *a, int *st, int k, float alltime, float &parttime, int minpoints, int &partpoints);

void backVizsgak(EXAM *a, int n, int *st, int k, float alltime, int minpoints, int &cnt);

#endif //LAB_08_FUNCTIONS_H
