#include <stdio.h>
#include <stdlib.h>

// ---------- Definizione delle strutture ----------
typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

// ---------- Prototipi delle funzioni ----------
Queue* new_queue();
int is_empty_queue(Queue* Q);
void enqueue(Queue* Q, int x);
int first(Queue* Q);
int dequeue(Queue* Q);

// ---------- Funzione main ----------
int main() {
    Queue* Q = new_queue();

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);

    printf("Primo elemento: %d\n", first(Q));
    printf("Elemento rimosso: %d\n", dequeue(Q));
    printf("Nuovo primo: %d\n", first(Q));

    // Pulizia finale
    while (!is_empty_queue(Q)) {
        dequeue(Q);
    }
    free(Q);
    return 0;
}

// ---------- Definizioni delle funzioni ----------
Queue* new_queue() {
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}

int is_empty_queue(Queue* Q) {
    return Q->head == NULL;
}

void enqueue(Queue* Q, int x) {
    Node* e = (Node*)malloc(sizeof(Node));
    e->val = x;
    e->next = NULL;

    if (Q->head == NULL) {
        Q->head = e;
    } else {
        Q->tail->next = e;
    }
    Q->tail = e;
}

int first(Queue* Q) {
    if (is_empty_queue(Q)) {
        printf("Coda vuota.\n");
        return -1; // Valore sentinella
    }
    return Q->head->val;
}

int dequeue(Queue* Q) {
    if (is_empty_queue(Q)) {
        printf("Coda vuota.\n");
        return -1;
    }

    int x = Q->head->val;
    Node* temp = Q->head;
    Q->head = Q->head->next;

    if (Q->head == NULL) {
        Q->tail = NULL;
    }

    free(temp);
    return x;
}
