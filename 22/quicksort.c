/**
 * Quicksort
 * Luca Gagliardelli
 * 31/07/2025
*/
#include <stdio.h>

/** Prototipi */

//Scambia il valore di due variabili
void scambia(int*, int*);

//Implementa il quicksort
void quickSort(int[], int, int);

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
    
    quickSort(v, 0, n-1);
    
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

void quickSort(int v[], int first, int last){
    if(first < last){
        //Sceglie come pivot l’elemento centrale
        int pivot = v[(first+last)/2];
        int i = first;
        int j = last;
        while (i <= j){
            while (v[i] < pivot) i++;
            while (v[j] > pivot) j--;
            if (v[i]>=v[j]){
                scambia(&v[i], &v[j]);
                i++;
                j--;
            }
            quickSort(v, first, j);
            quickSort(v, i, last);
        }
    }
}