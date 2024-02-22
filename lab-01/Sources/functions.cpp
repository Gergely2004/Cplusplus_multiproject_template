#include <iostream>
#include "functions.h"

int lnko(int a, int b) {
    int r;
    while(a != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

int lkkt(int a, int b) {
    int lcd;
    lcd = abs(a * b) / lnko(a, b);
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
        cout << a[i];
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
    for(int i = 0 ; i < n; ++i) {
        for(int j = i + 1; j < n - 1; ++j) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void minimselection_sort(int *a, int n) {
    int min_i;
    for(int i = 0 ; i < n; ++i) {
        min_i = i;
        for(int j = i + 1; j < n - 1; ++j) {
            if(a[j] < a[min_i])
                min_i = j;
        }
        if(min_i != i)
            swap(a[min_i], a[i]);
    }
}






