#include <iostream>
#include "functions.h"

int lnko(int a, int b) {
    int r;
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int lkkt(int a, int b) {
    int lcm;
    lcm = abs(a * b) / lnko(a, b);
}

int power(int b, int e) {
    int pow = 1;
    for(int i = 0; i < e; ++i) {
        pow *= b;
    }
    return pow;
}

void read_array(int *a, int n) {
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void print_array(int *a, int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}

int linearSearch(int *array, int size, int target) {
    for(int i = 0; i < size; ++i) {
        if(array[i] == target)
            return true;
    }
    return false;
}

int binarySearch(const int *array, int size, int target, int left, int right) {
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(target == array[mid]) {
            return true;
        }
        else {
            if(array[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}

void selection_sort(int *a, int n) {
    for(int i = 0 ; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void minimselection_sort(int *a, int n) {
    int min_index;
    for(int i = 0 ; i < n - 1; ++i) {
        min_index = i;
        for(int j = i + 1; j < n; ++j) {
            if(a[j] < a[min_index])
                min_index = j;
        }
        if(min_index != i)
            swap(a[min_index], a[i]);
    }
}

void bubble_sort(int *a, int n) { // -2 -4 -5 7 5
    int ok = 1;
    while(ok == 1) {
        for(int i = 0; i < n - 1 && ok == 1; ++i) {
            if(a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        ok = 0;
    }
    swap(a[0], a[1]);
}

int lnkoRec(int a, int b) {
    if(a % b == 0) return b;
    else return lnkoRec(b, a % b);
}

int lkktRec(int a, int b, int a1, int b1) {
    if(a1 % b1 == 0) return (a * b) / b1;
    else return lkktRec(a, b, b1, a1 % b1);
}

int powerRec(int b, int e) {
    if(e == 0) return 1;
    return b * powerRec(b, e - 1);
}

void readArrayRec(int *a, int n, ifstream &f) {
    if(n > 0) readArrayRec(a, n - 1, f);
    f >> a[n - 1];
}

void printArrayRec(int *a, int n) {
    if(n > 0) printArrayRec(a, n - 1);
    cout << a[n - 1];
}

int sumArrayRec(int *a, int n) {
    if(n == 1) return a[0];
    return a[n - 1] + sumArrayRec(a, n - 1);
}

int maxArrayRec(int *a, int n, int max) {
    int x;
    if(n > 0) {
        max = a[n - 1];
        x = maxArrayRec(a, n - 1, max);
        if(x > max) return x;
        else return max;
    }
    else
        return a[0];
}

int lnkoArrayRec(int *a, int n) {
    if(n > 1)
        return lnkoRec(a[n], lnkoArrayRec(a, n - 1));
    else
        return lnkoRec(a[0], a[1]);
}

int inverseNumber(int n, int fn) {
    if(n < 10) {
        return fn * 10 + n;
    }
    else {
        fn = fn * 10 + n % 10;
        return inverseNumber(n / 10, fn);
    }
}
