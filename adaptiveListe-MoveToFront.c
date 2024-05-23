/*
 * Übung 39: adaptive Liste MoveToFront
 * =============================================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    23.04.2024
 */


#include <stdio.h>
#include <stdlib.h>

struct element
{
    int nummer;
    int preis;
    struct element *next;
    struct element *prev;
};
struct element *anfang = NULL;
struct element *ende = NULL;

struct element* createElement(int nummer, int preis) {
    struct element* newElement = (struct element*)malloc(sizeof(struct element));
    newElement->nummer = nummer;
    newElement->preis = preis;
    newElement->prev = NULL;
    newElement->next = NULL;
    return newElement;
}

void Ausgabe()
{
    struct element *help;
    help = anfang;

    if (anfang == NULL)
    {
        printf("Die Liste ist leer");
    }
    else
    {
        while (help != NULL)
        {
            printf("%i ", help->nummer);
            help = help->next;
        }
    }
    printf("\n");
}

void EinfügenAmAnfang(int nummer, int preis) {
    struct element* newElement = createElement(nummer, preis);
    newElement->next = anfang;
    if (anfang != NULL) {
        anfang->prev = newElement;
    }
    anfang = newElement;
}

void LöschenAmEnde() {
    if (anfang == NULL) {
        return;
    }
    struct element* ende = anfang;
    while (ende->next != NULL) {
        ende = ende->next;
    }
    if (ende->prev != NULL) {
        ende->prev->next = NULL;
    } else {
        anfang = NULL;
    }
    free(ende);
}

void MoveToFront(int nummer)
{
    struct element *temp = anfang;
    struct element *prev = NULL;
    if(anfang-> nummer == nummer)
    {
        return;
    }
    while (temp != NULL && temp->nummer != nummer)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        prev->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = prev;
        }
        else
        {
            ende = prev;
        }
        temp->next = anfang;
        anfang->prev = temp;
        temp->prev = NULL;
        anfang = temp;
    
    }
}

int main()
{
   printf("Es werden Daten am Anfang der Liste hinzugefügt... \n");
    EinfügenAmAnfang(5, 1);
    EinfügenAmAnfang(4, 1);
    EinfügenAmAnfang(3, 1);
    EinfügenAmAnfang(2, 1);
    EinfügenAmAnfang(1, 1);
    Ausgabe();

    printf("Das letzte Element der Liste wird gelöscht... \n");
    LöschenAmEnde();
    Ausgabe();

    printf("Das Element mit der Nummer 3 wird an den Anfang der Liste verschoben... \n");
    MoveToFront(3);
    Ausgabe();
}
