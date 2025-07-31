/**
 * Merge sort
 * Luca Gagliardelli
 * 31/07/2025
*/
#include <stdio.h>

/** Prototipi */

//Implementa il Merge sort
void merge(int[], int, int, int);
void mergeSort(int[], int, int);

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
    
    mergeSort(v, 0, n-1);
    
    printf("\n\nArray ordinato\n");
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}


/* Implementazioni */

void merge(int v[], int left, int center, int right) {
    int i = left;
    int j = center + 1;
    int k = 0;
    int size = right - left + 1;
    int b[size];

    // Unisce gli elementi ordinati da entrambi i sotto-vettori
    while (i <= center && j <= right) {
        if (v[i] <= v[j]) {
            b[k++] = v[i++];
        } else {
            b[k++] = v[j++];
        }
    }

    // Copia gli eventuali elementi rimanenti del sotto-vettore sinistro
    while (i <= center) {
        b[k++] = v[i++];
    }

    // Copia gli eventuali elementi rimanenti del sotto-vettore destro
    while (j <= right) {
        b[k++] = v[j++];
    }

    // Copia il contenuto ordinato da b a v
    for (k = 0; k < size; k++) {
        v[left + k] = b[k];
    }

}

void mergeSort(int v[], int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(v, left, center);        // Ordina la parte sinistra
        mergeSort(v, center + 1, right);   // Ordina la parte destra
        merge(v, left, center, right);     // Unisce i due risultati
    }
}

