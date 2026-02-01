/*
 * Übung 37: Queues mittels verketteter Liste
 * =============================================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    16.04.2024
 */

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int daten;
    struct element *next;
};
struct element *anfang = NULL;

void Display()
{
    struct element *help;
    help = anfang;

    if (anfang == NULL)
    {
        printf("Die Queue ist leer");
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

void EnQueue(int wert)
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

void DeQueue()
{
    struct element *help;
    help = anfang;
    anfang = anfang -> next;
    free(help);
}

void Top()
{
    if(anfang == NULL)
    {
        printf("Die Queue ist leer.");
    }
    else 
    {
    printf("%d\n", (int)anfang->daten);
    }
}

void Pop()
{
    struct element *help;
    help = anfang;
    anfang = anfang -> next;
    free(help);
}

int QueueEmpty()
{
    if (anfang == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ClearQueue()
{
    while( anfang != NULL)
    {
        DeQueue();
    }
}


int main()
{
    printf("Gib einen neuen Wert ein: ");
    int wert;
    scanf("%i", &wert);

    printf("\n========================================\n");
    printf("Die Queue ist leer:\n");
    Display();

    printf("\n========================================\n");
    printf("Unser Wert wurde eingefügt:\n");
    EnQueue(wert);
    Display();

    printf("\n========================================\n");
    printf("Füge 39, 54, 1044 hinzu:\n");
    EnQueue(39);
    EnQueue(54);
    EnQueue(1044);
    Display();

    printf("\n========================================\n");
    printf("Lösche das erste Element der Queue:\n");
    DeQueue();
    Display();

    printf("\n========================================\n");
    printf("Zeige das erste Element an:\n");
    Top();

    printf("\n========================================\n");
    printf("Füge 23 hinzu:\n");
    EnQueue(23);
    Display();

    printf("\n========================================\n");
    printf("Ist die Queue leer (1 -> ja, 0 -> nein): ");
    printf("%d\n", QueueEmpty());
    
    printf("\n========================================\n");
    printf("Leere die Queue:\n");
    ClearQueue();
    Display();

    printf("\n========================================\n");
    printf("Ist die Queue leer (1 -> ja, 0 -> nein): ");
    printf("%d\n", QueueEmpty());

    return 0;
}
