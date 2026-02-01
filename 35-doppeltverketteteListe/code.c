/*
 * Übung 35: Doppeltverkettete Liste 
 * =============================================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    02.04.2024
 */

#include <stdio.h>
#include <stdlib.h>

// Definition eines Knotens
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Globale Variable für den Kopf der Liste
struct Node* head = NULL;

// Funktion zum Erstellen eines neuen Knotens
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Funktion zum Einfügen eines Knotens am Anfang der Liste
void prepend(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Funktion zum Einfügen eines Knotens am Ende der Liste
void append(int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = head;
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// Funktion zum Löschen des Knotens am Anfang der Liste
void deleteFirst() {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Funktion zum Löschen des Knotens am Ende der Liste
void deleteLast() {
    if (head == NULL) {
        return;
    }
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    if (last->prev != NULL) {
        last->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(last);
}


// Funktion zum Ausdrucken der doppelt verketteten Liste
void printList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("Prepend 7:\n");
    prepend(7);
    printList();

    printf("Append 4:\n");
    append(4);
    printList();

    printf("Prepend 1:\n");
    prepend(1);
    printList();

    printf("Delete first:\n");
    deleteFirst();
    printList();

    printf("Delete last:\n");
    deleteLast();
    printList();
    return 0;
}
