/**
 * Counting sort
 * Luca Gagliardelli
 * 31/07/2025
*/
#include <stdio.h>

/** Prototipi */

//Implementa il counting sort
void countingSort(int[], int);

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
    
    countingSort(v, n);
    
    printf("\n\nArray ordinato\n");
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}


/* Implementazioni */
void countingSort(int v[], int n) {
    // Trova minimo e massimo
    int min = v[0];
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max)
            max = v[i];
        else if (v[i] < min)
            min = v[i];
    }

    // Crea il vettore di appoggio
    int range = max - min + 1;
    int tmp[range];

    for (int i = 0; i < range; i++)
        tmp[i] = 0;

    // Conta le occorrenze
    for (int i = 0; i < n; i++)
        tmp[v[i] - min]++;

    // Riempie il vettore originale in ordine
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (tmp[i] > 0) {
            v[j++] = i + min;
            tmp[i]--;
        }
    }
}