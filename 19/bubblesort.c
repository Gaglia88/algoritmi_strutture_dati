/**
 * Bubble sort
 * Luca Gagliardelli
 * 31/07/2025
*/
#include <stdio.h>

/** Prototipi */

//Scambia il valore di due variabili
void scambia(int*, int*);

//Implementa il bubble sort
void bubbleSort(int[], int);

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
    
    bubbleSort(v, n);
    
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

void bubbleSort(int v[], int n){
    short ordinato = 0;
    while(n>1 && !ordinato){
        ordinato = 1; //Supponiamo che il vettore sia ordinato
        for(int i=0; i<n-1; i = i+1){
            if (v[i] > v[i+1]){
                scambia(&v[i], &v[i+1]);
                ordinato = 0; //Siccome fa uno scambio non è ordinato
            }
        }
        n--;
    }
}