/**
 * Naive sort
 * Luca Gagliardelli
 * 31/07/2025
*/
#include <stdio.h>

/** Prototipi */

//Scambia il valore di due variabili
void scambia(int*, int*);

//Implementa il naive sort
void naiveSort(int[], int);

//Punto di ingresso
int main() {
    int v[] = {10, 5, 4, 3, 12, 30, 1}; // Vettore
    int n = sizeof(v)/sizeof(int);     //Calcola la dimensione del vettore
    
    /*
        Visualizza l'array, lo ordina e lo rivisualizza
    */
    printf("Array in ingresso\n");
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    
    naiveSort(v, n);
    
    printf("\n\nArray ordinato\n");
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}


/* Implementazioni */
void scambia(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void naiveSort(int v[], int n){
    int pmax;
    while (n>1){
        pmax = 0;
        for(int i=1; i<n; i++){
            if (v[i] > v[pmax]){
                pmax = i;
            }
        }
        if (pmax < n-1){
            scambia(&v[n-1], &v[pmax]);
        }
        n = n-1;
    }
}