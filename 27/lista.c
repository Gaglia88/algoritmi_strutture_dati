#include <stdio.h>
#include <stdlib.h>

// Definizione del nodo
typedef struct Node {
    int inf;                // Informazione contenuta nel nodo
    struct Node* next;      // Puntatore al nodo successivo
} Node;

// Tipo Lista: puntatore al primo nodo
typedef Node* List;
// Crea una nuova lista vuota
List new_list() ;
// Controlla se la lista è vuota
int is_empty_list(List L);
// Inserisce un nodo in testa alla lista
void insert_head(List*, Node*);
// Inserisce un nodo dopo un altro nodo p
void insert_after(Node*, Node*);
// Recupera il nodo in posizione i (0-based)
Node* retrieve(List, int);
// Inserisce un nodo e in posizione i
void insert(List*, Node*, int);
// Cancella un nodo p dalla lista
void delete_node(List*, Node*);
// Funzione di utilità: crea un nuovo nodo
Node* create_node(int value);



int main() {
    List myList = new_list();

    Node* n1 = create_node(10);
    Node* n2 = create_node(20);
    Node* n3 = create_node(30);

    insert_head(&myList, n1);    // Lista: 10
    insert(&myList, n2, 1);      // Lista: 10 -> 20
    insert(&myList, n3, 1);      // Lista: 10 -> 30 -> 20

    delete_node(&myList, n3);    // Rimuove 30

    // Libera la memoria residua
    while (!is_empty_list(myList)) {
        delete_node(&myList, myList);
    }

    return 0;
}

// Crea una nuova lista vuota
List new_list() {
    return NULL;
}

// Controlla se la lista è vuota
int is_empty_list(List L) {
    return L == NULL;
}

// Inserisce un nodo in testa alla lista
void insert_head(List* L, Node* e) {
    e->next = *L;
    *L = e;
}

// Inserisce un nodo dopo un altro nodo p
void insert_after(Node* p, Node* e) {
    if (p != NULL) {
        e->next = p->next;
        p->next = e;
    }
}

// Recupera il nodo in posizione i (0-based)
Node* retrieve(List L, int i) {
    int j = 0;
    Node* p = L;
    while (j < i && p != NULL) {
        p = p->next;
        j++;
    }
    return p;
}

// Inserisce un nodo e in posizione i
void insert(List* L, Node* e, int i) {
    if (i == 0) {
        insert_head(L, e);
    } else {
        Node* p = retrieve(*L, i - 1);
        if (p != NULL) {
            insert_after(p, e);
        }
    }
}

// Cancella un nodo p dalla lista
void delete_node(List* L, Node* p) {
    if (*L == NULL || p == NULL) return;

    if (*L == p) {
        *L = p->next;
        free(p);
    } else {
        Node* tmp = *L;
        while (tmp->next != NULL && tmp->next != p) {
            tmp = tmp->next;
        }
        if (tmp->next == p) {
            tmp->next = p->next;
            free(p);
        }
    }
}

// Crea un nuovo nodo
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->inf = value;
        new_node->next = NULL;
    }
    return new_node;
}
