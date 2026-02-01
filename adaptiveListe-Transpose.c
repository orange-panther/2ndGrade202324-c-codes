/*
 * Übung 40: adaptive Liste Transpose
 * =============================================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    07.05.2024
 */

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int nummer;
    struct element *next;
    struct element *prev;
};

struct element *anfang = NULL;
struct element *ende = NULL;

struct element* createElement(int nummer)
{
    struct element* newElement = (struct element*)malloc(sizeof(struct element));
    newElement->nummer = nummer;
    newElement->next = NULL;
    newElement->prev = NULL;
    return newElement;
}

void ausgabe()
{
    struct element *help = anfang;
    if(anfang == NULL)
    {
        printf("Die Liste ist leer.");
    }
    else
    {
        while(help != NULL)
        {
            printf("%i ", help->nummer);
            help = help->next;
        }
    }
    printf("\n");
}

void appendAtHead(int nummer)
{
    struct element* newElement = createElement(nummer);
    newElement->next = anfang;
    if(anfang != NULL)
    {
        anfang->prev = newElement;
    }
    anfang = newElement;
    if(ende == NULL)
    {
        ende = anfang;
    }

}

void deleteAtTail()
{
    if(anfang == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }

    struct element *temp = ende;
    ende = ende->prev;
    if(ende != NULL)
    {
        ende->next = NULL;
    }
    else 
    {
        anfang = NULL;
    }  
    free(temp); 
}

void transpose(int nummer)
{
    if(anfang == NULL || anfang->next == NULL)
    {
        printf("Liste ist leer oder hat nur einen Eintrag.");
        return;
    }

    struct element *current = anfang;

    while(current != NULL)
    {
        if(current->nummer == nummer)
        {
            if(current != anfang)
            {
                current->prev->next = current->next;
                if(current != ende)
                {
                    current->next->prev = current->prev;
                }
                else 
                {
                    ende = current->prev;
                }

                current->next = current->prev;
                current->prev = current->prev->prev;
                current->next->prev = current;

                if(current->prev != NULL)
                {
                    current->prev->next = current;
                }
                else
                {
                    anfang = current;
                }
                break;
            }
        }
        current = current->next;
    }
}


int main(void)
{
    printf("Füge Daten am Anfang an.\n");
    appendAtHead(4);
    appendAtHead(3);
    appendAtHead(2);
    appendAtHead(1);
    ausgabe();

    printf("Lösche den letzten Eintrag.\n");
    deleteAtTail();
    ausgabe();

    printf("Tranpose 3\n");
    transpose(3);
    ausgabe();

    return 0;
}