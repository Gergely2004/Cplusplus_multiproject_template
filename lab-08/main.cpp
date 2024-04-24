#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

ifstream fin1("szamok.txt");
///s = 7
///a = 2 3 6 7

void exercise1();

ifstream fin2("exams.txt");

void exercise2();

int main() {
    int nrOfExercise;
    cout << "Which exercise do you want to solve?" << endl;
    cin >> nrOfExercise;
    switch (nrOfExercise) {
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

void exercise1() {
    int n = - 1, nr, s;
    fin1 >> s;
    ///int *a = new int[10], *st = new int[10];
    int a[10], st[10];
    while(fin1 >> nr)
    {
        n++; a[n] = nr;
    }
    int cnt = 0;
    backHalmaz_Szamt1(a, n, st, 0, s, cnt);
    cout << endl;
    cout << cnt;
}



void exercise2() {
    EXAM a[20];
    int st[20];
    int n;
    fin2 >> n;
    for(int i = 0; i < n; i++){
        fin2 >> a[i].points >> a[i].time;
    }
    float alltime, begintime, endtime;
    fin2 >> begintime >> endtime;
    alltime = endtime - begintime;
    int minpoints = 180;
    int cnt = 0;
    backVizsgak(a, n, st, 0, alltime, minpoints, cnt);
    cout << endl;
    cout << cnt;
}
