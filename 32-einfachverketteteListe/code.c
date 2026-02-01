/*
 * Übung 32: Einfachverkettete Liste mittels Datenkapselung
 * ========================================================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    15.03.2024
 */

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int daten;
    struct element *next;
};
struct element *anfang = NULL;

void PrintList()
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
            printf("%i ", help->daten);
            help = help->next;
        }
    }
    printf("\n");
}

void Append(int wert)
{
    struct element *neu;
    struct element *help;
    help = anfang;

    // neues Element erzeugen
    neu = (struct element *)malloc(sizeof(struct element));

    // neues Element ausfüllen
    neu->daten = wert;
    neu->next = NULL;

    // in Liste einhängen
    if (anfang == NULL)
    {
        anfang = neu;
    }
    else
    {
        while (help->next != NULL)
        {
            help = help->next;
        }
        help->next = neu;
    }
}

void DeleteTail()
{
    struct element *help;
    help = anfang;

    if (anfang == NULL)
    {
        printf("Die Liste ist leer\n");
    }
    else if (anfang->next == NULL)
    {
        free(anfang);
        anfang = NULL;
    }
    else
    {
        while (help->next->next != NULL)
        {
            help = help->next;
        }
        free(help->next);
        help->next = NULL;
    }
}

int main()
{
    printf("Gib einen neuen Wert ein: ");
    int wert;
    scanf("%i", &wert);

    printf("\n========================================\n");
    printf("Die Liste ist leer:\n");
    PrintList();

    printf("\n========================================\n");
    printf("Unser Wert wurde eingefügt:\n");
    PrintList();
    Append(wert);

    printf("\n========================================\n");
    printf("Andere Werte wurden eingefügt:\n");
    Append(5);
    Append(130);
    Append(90);
    PrintList();

    printf("\n========================================\n");
    printf("Lösche das letzte Element der Liste:\n");
    DeleteTail();
    PrintList();

    return 0;
}
