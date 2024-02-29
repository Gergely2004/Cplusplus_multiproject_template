#include <iostream>
#include "functions.h"

int main() {
    int feladatszam;
    printf("Olvasd be a feladat szamat: ");
    scanf("%i", &feladatszam);
    switch (feladatszam) {
        case 1: {
            int x, y;
            printf("Olvasd be a ket szamot: ");
            scanf("%i%i", &x, &y);
            printf("A ket szam legnagyobb kozos osztoja: %i", lnko(x, y));
            break;
        }
        case 2: {
            int x, y;
            printf("Olvasd be a ket szamot: ");
            scanf("%i%i", &x, &y);
            printf("A ket szam legkisebb kozos tobbszorose: %i", lkkt(x, y));
            break;
        }
        case 3: {
            int x, y;
            printf("Olvasd be a szamot es a hatvanyt: ");
            scanf("%i%i", &x, &y);
            printf("x ^ y = %i", power(x, y));
            break;
        }
        case 4 /* es 5 */: {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            print_array(a, n);
            break;
        }
        case 6: {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            int number;
            printf("Olvasd be a keresett szamot: ");
            scanf("%i", &number);
            if(linearSearch(a, n, number) == 1)
                printf("A keresett szam szerepel a tombben.");
            else
                printf("A keresett szam nem szerepel a tombben");
            break;
        }
        case 8: {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            selection_sort(a, n);
            printf("A tomb rendezes utan: \n");
            print_array(a, n);
            break;
        }
        case 9: {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            minimselection_sort(a, n);
            printf("A tomb rendezes utan: \n");
            print_array(a, n);
            break;
        }
        case 10: {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            bubble_sort(a, n);
            printf("A tomb rendezes utan: \n");
            print_array(a, n);
            break;
        }
        case 11: {
            int x, y;
            printf("Olvasd be a ket szamot: ");
            scanf("%i%i", &x, &y);
            printf("A ket szam legnagyobb kozos osztoja: %i", lnkoRec(x, y));
            break;
        }
        case 12: {
            int x, y, lcm;
            printf("Olvasd be a ket szamot: ");
            scanf("%i%i", &x, &y);
            lcm = lkktRec(x, y, x,y);
            printf("A ket szam legkisebb kozos tobbszorose: %i", lcm);
            break;
        }
        case 13: {
            int x, y;
            printf("Olvasd be a szamot es a hatvanyt: ");
            scanf("%i%i", &x, &y);
            printf("x ^ y = %i", powerRec(x, y));
            break;
        }
        case 14: /* es 15 */ {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            readArrayRec(a, n, f);
            printArrayRec(a, n);
            break;
        }
        case 16: {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            int sum = sumArrayRec(a, n);
            printf("A tomb elemeinek osszege: %i", sum);
            break;
        }
        case 17: {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            int max = maxArrayRec(a, n, a[n - 1]);
            printf("A tomb maximuma: %i", max);
            break;
        }
        case 18: {
            int n;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            printf("A tomb elemeinek legnagyobb kozos osztoja: %i", lnkoArrayRec(a, n));
            break;
        }
        case 20: {
            int n, invn = 0;
            printf("Olvasd be a szamot: ");
            scanf("%i", &n);
            invn = inverseNumber(n, invn);
            printf("A szam forditottja: %i", invn);
        }
        case 21: {
            int n, total;
            printf("Olvasd be a tomb hosszat: ");
            scanf("%i", &n);
            int a[n];
            read_array(a, n);
            total = sum(a, n);
            printf("A tomb azon elemeinek osszege amelyek oszthatoak szamjegyeik osszegevel: %i", total);
        }
    }
    return 0;
}
