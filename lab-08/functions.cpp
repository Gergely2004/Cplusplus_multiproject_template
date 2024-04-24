#include "functions.h"
#include <iostream>
using namespace std;

//exercise1
void backHalmaz_Szamt1(int *a, int n, int *st, int k, int s, int &cnt){
    for (int i = 0; i <= n; ++i) {
        st[k] = i;
        int sp = 0;
        if (igeretesHalmaz_Szamt1(a, st, k, s, sp)) {
            if (sp == s) {
                kiirHalmaz_Szamt1(a, st, k);
                cnt++;
            } else {
                if (sp < s) {
                    backHalmaz_Szamt1(a, n, st, k + 1, s, cnt);
                }
            }
        }
    }
}

void kiirHalmaz_Szamt1(int *a, int *st, int k) {
    for (int i = 0; i <= k; ++i) {
        cout << a[st[i]] << " ";
    }
    cout << endl;
}

bool igeretesHalmaz_Szamt1(int *a, int *st, int k, int s, int &sp){
    if(k > 0)
        if(st[k] < st[k - 1])
            return false;
    for (int i = 0; i <= k; ++i) {
        sp += a[st[i]];
    }
    if(sp > s) {
        return false;
    }
    return true;
}

//exercise2
void backVizsgak(EXAM *a, int n, int *st, int k, float alltime, int minpoints, int &cnt){
    for (int i = 0; i < n; ++i) {
        st[k] = i;
        float parttime = 0;
        int partpoints = 0;
        if (igeretesVizsgak(a, st, k, alltime, parttime, minpoints,partpoints)) {
            if (parttime <= alltime) {
                if(partpoints >= minpoints){
                    cnt++;
                    cout << cnt << ". megoldas:" << endl;
                    kiirVizsgak(a, st, k);
                }
                if (parttime < alltime) {
                    backVizsgak(a, n, st, k + 1, alltime, minpoints, cnt);
                }
            }
        }
    }
}

void kiirVizsgak(EXAM *a, int *st, int k) {
    for (int i = 0; i <= k; ++i) {
        cout << st[i] + 1 << " - " << a[st[i]].points << " - "  << a[st[i]].time << endl;
    }
    cout << endl;
}

bool igeretesVizsgak(EXAM *a, int *st, int k, float alltime, float &parttime, int minpoints, int &partpoints) {
    if(k > 0)
    {
        if(st[k] < st[k - 1])
            return false;
        for (int i = 0; i < k; ++i) {
            if(st[k] == st[i])
                return false;
        }
    }
    for (int i = 0; i <= k; ++i) {
        parttime += a[st[i]].time;
        partpoints += a[st[i]].points;
    }
    if(parttime > alltime) {
        return false;
    }
    return true;
}


