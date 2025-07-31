/**
 * Insertion sort
 * Luca Gagliardelli
 * 31/07/2025
*/
#include <stdio.h>

/** Prototipi */

//Implementa l'insertion sort
void insertionSort(int[], int);

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
    
    insertionSort(v, n);
    
    printf("\n\nArray ordinato\n");
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}


/* Implementazioni */
void insertionSort(int v[], int n){
    for(int i=1, j=0; i<n; ++i){
        int val = v[i];
        j = i-1;
        while (v[j]>val && j>=0){
             v[j+1] = v[j];
             j--;
        }
        v[j+1] = val;
    }
}