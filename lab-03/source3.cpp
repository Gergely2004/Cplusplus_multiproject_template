#include "header3.h"

void read_array(int *a, int n, ifstream &fin) {
    for(int i = 0; i < n; ++i) {
        fin >> a[i];
    }
}

void printArrayRec(int *a, int n) {
    if(n > 1) printArrayRec(a, n - 1);
    cout << a[n - 1] << " ";
}

int inverseNumberGenerator(int x) {
    int ld, invNr = 0, p = 1;
    while(x) {
        ld = x % 10;
        invNr = invNr * p + ld;
        p *= 10;
        x /= 10;
    }
    return invNr;
}

void mirrorNumbersInArray(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
       if(a[i] == inverseNumberGenerator(a[i + 1]))
           cout << a[i] << " " << a[i + 1] << " ";
    }
}

void mirrorNumbersInArrayRec(int *a, int n) {
    if(n > 1) {
        if(a[n - 1] == inverseNumberGenerator(a[n - 2]))
            mirrorNumbersInArrayRec(a, n - 1);
    }
    cout << a[n - 1] << " " << a[n - 2] << " ";
}

void mergesort(int *a, int i, int j) {
    if(i < j) {
        int k = (i + j) / 2;
        mergesort(a, i, k);
        mergesort(a, k + 1, j);
        osszefesul(a, i, k, j);
    }
}


/*void osszefesul(int *a, int i, int k, int j) {
    int *x, *y;
    x = new int[k + 2];
    y = new int[j + 2];
    for(int l = i; l <= k; ++l)
        x[l] = a[l];
    for(int l = k + 1; l <= j; ++l)
        y[l] = a[l];
    x[k + 1] = INT_MAX;
    y[j + 1] = INT_MAX;
    int indexX = i, indexY = k + 1;
    for(int l = i; l <= j; ++l) {
        if(x[indexX] < y[indexY]) {
            a[l] = x[indexX++];
        }
        else a[l] = y[indexY++];
    }
    delete[] x;
    delete[] y;
}*/

void osszefesul(int *a, int i, int k, int j) {
    int cnt = 0;
    int *x, *y;
    x = new int[k + 2];
    y = new int[j + 2];
    for (int l = i; l <= k; ++l)
        x[l] = a[l];
    for (int l = k + 1; l <= j; ++l)
        y[l] = a[l];
    x[k + 1] = INT_MAX;
    y[j + 1] = INT_MAX;
    int indexX = i, indexY = k + 1;
    for (int l = i; l <= j; ++l) {
        if (x[indexX] <= y[indexY]) {
            a[l] = x[indexX++];
            if (x[indexX - 1] == y[indexY]) {
                indexY++;
            }
        } else {
            a[l] = y[indexY++];
        }
    }
    delete[] x;
    delete[] y;
}

int maxArrayRec(int *a, int n, int max) {
    if(n>=0)
    {
        if(max<a[n])
        {
            max=a[n];
        }
        return maxArrayRec(a,n-1,max);
    }
    return max;
}

int maxindex(int *a, int i, int j) {
    int m1, m2;
    if(i == j) return i;
    else {
        m1 = maxindex(a, i, (i + j) / 2);
        m2 = maxindex(a, (i + j) / 2 + 1, j);
        if(a[m1] > a[m2])
            return m1;
        else
            return m2;
    }
}

int partition(int *a, int i, int j) {
    int l = i;
    int r = j;
    int pivot = a[l];
    while(i < j) {
        do {
            i++;
        }while(a[i] <= pivot);
        do{
            j--;
        } while (a[j] > pivot);
        if(i < j) swap(a[i], a[j]);
    }
    swap(a[j], a[l]);
    return j;
}

void quickSort(int *a, int i, int j) {
    if(i == j) return;
    if(i < j) {
        int k = partition(a, i, j);
        quickSort(a, i, k);
        quickSort(a, k + 1, j);
    }
}

