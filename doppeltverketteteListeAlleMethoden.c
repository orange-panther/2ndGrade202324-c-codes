/*
 * Übung 37: doppeltverketteteListeDatenkapselung
 * ==============================================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    23.04.2024
 */

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int daten;
    struct element *next;
    struct element *prev;
};

struct element *anfang = NULL;
struct element *ende = NULL;

void appendHead(int daten)
{
    struct element *neu = (struct element *)malloc(sizeof(struct element));
    neu->daten = daten;
    neu->next = anfang;
    neu->prev = NULL;
    if (anfang != NULL)
    {
        anfang->prev = neu;
    }
    anfang = neu;
    if (ende == NULL)
    {
        ende = anfang;
    }
}

void appendTail(int daten)
{
    struct element *neu = (struct element *)malloc(sizeof(struct element));
    neu->daten = daten;
    neu->next = NULL;
    neu->prev = ende;
    if (ende != NULL)
    {
        ende->next = neu;
    }
    ende = neu;
    if (anfang == NULL)
    {
        anfang = ende;
    }
}

void deleteHead()
{
    if (anfang != NULL)
    {
        struct element *temp = anfang;
        anfang = anfang->next;
        if (anfang != NULL)
        {
            anfang->prev = NULL;
        }
        else
        {
            ende = NULL;
        }
        free(temp);
    }
}

void deleteTail()
{
    if (ende != NULL)
    {
        struct element *temp = ende;
        ende = ende->prev;
        if (ende != NULL)
        {
            ende->next = NULL;
        }
        else
        {
            anfang = NULL;
        }
        free(temp);
    }
}

void printList()
{
    struct element *temp = anfang;
    while (temp != NULL)
    {
        printf("%d ", temp->daten);
        temp = temp->next;
    }
    printf("\n");
}

void printListReverse()
{
    struct element *temp = ende;
    while (temp != NULL)
    {
        printf("%d ", temp->daten);
        temp = temp->prev;
    }
    printf("\n");
}

void searchElement(int daten)
{
    struct element *temp = anfang;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->daten == daten)
        {
            printf("Das gesuchte Element wurde an der Position %d gefunden. \n", index + 1);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Das gesuchte Element wurde nicht gefunden. \n");
}

void deleteElement(int daten)
{
    struct element *temp = anfang;
    while (temp != NULL)
    {
        if (temp->daten == daten)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                anfang = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                ende = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
}

void sortedInsert(int daten)
{
    struct element *neu = (struct element *)malloc(sizeof(struct element));
    neu->daten = daten;
    if (anfang == NULL)
    {
        anfang = neu;
        ende = neu;
        return;
    }
    struct element *temp = anfang;
    while (temp != NULL)
    {
        if (temp->daten > daten)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = neu;
            }
            else
            {
                anfang = neu;
            }
            neu->prev = temp->prev;
            neu->next = temp;
            temp->prev = neu;
            return;
        }
        if (temp->next == NULL)
        {
            temp->next = neu;
            neu->prev = temp;
            ende = neu;
            return;
        }
        temp = temp->next;
    }
}

void main(int)
{
    printf("Es werden Daten am Anfang der Liste hinzugefügt... \n");
    appendHead(3);
    appendHead(2);
    appendHead(1);
    printList();

    printf("Es werden Daten zum Ende der Liste hinzugefügt... \n");
    appendTail(4);
    appendTail(5);
    appendTail(6);
    printList();

    printf("Das erste Element der Liste wird gelöscht... \n");
    deleteHead();
    printList();

    printf("Das letzte Element der Liste wird gelöscht... \n");
    deleteTail();
    printList();

    printf("Die Liste wird in umgekehrter Reihenfolge ausgegeben... \n");
    printListReverse();

    printf("Es wird nach dem Element 5 gesucht... \n");
    searchElement(5);

    printf("Das Element 5 wird gelöscht... \n");
    deleteElement(5);
    printList();

    printf("Füge das Element 5 sortiert ein... \n");
    sortedInsert(5);
    printList();
}