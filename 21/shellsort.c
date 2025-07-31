/**
 * Shell sort
 * Luca Gagliardelli
 * 31/07/2025
*/
#include <stdio.h>

/** Prototipi */

//Implementa l'shell sort
void shellSort(int[], int);

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
    
    shellSort(v, n);
    
    printf("\n\nArray ordinato\n");
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}


/* Implementazioni */
void shellSort(int v[], int n){
    int gap = n/2;
    while(gap > 0){
        for(int i=gap, j, val; i<n; i++){
            int val = v[i];
            j = i;
            while(j >= gap && v[j-gap] > val){
                v[j] = v[j-gap];
                j -= gap;
            }
            v[j] = val;
        }
        gap = gap/2;
    }
}