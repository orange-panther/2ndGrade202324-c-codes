/*
 * Übung 36: Stack mittels verketteter Liste
 * =============================================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    12.04.2024
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
        printf("Der Stack ist leer");
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

void Push(int wert)
{
    struct element *neu;
    struct element *help;
    help = anfang;

    // neues Element erzeugen
    neu = (struct element *)malloc(sizeof(struct element));

    // neues Element ausfüllen
    neu->daten = wert;
    neu->next = anfang;

    // in Liste einhängen
    anfang = neu;

}

void Top()
{
    printf("%d\n", (int)anfang->daten);
}

void Pop()
{
    struct element *help;
    help = anfang;
    anfang = anfang -> next;
    free(help);
}

int StackEmpty()
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

void StackClear()
{
    while( anfang != NULL)
    {
        Pop();
    }
}


int main()
{
    printf("Gib einen neuen Wert ein: ");
    int wert;
    scanf("%i", &wert);

    printf("\n========================================\n");
    printf("Der Stack ist leer:\n");
    Display();

    printf("\n========================================\n");
    printf("Unser Wert wurde eingefügt:\n");
    Push(wert);
    Display();

    printf("\n========================================\n");
    printf("Füge 39, 54, 1044 hinzu:\n");
    Push(39);
    Push(54);
    Push(1044);
    Display();

    printf("\n========================================\n");
    printf("Lösche das oberste Element des Stacks:\n");
    Pop();
    Display();

    printf("\n========================================\n");
    printf("Zeige das oberste Element an:\n");
    Top();

    printf("\n========================================\n");
    printf("Füge 23 hinzu:\n");
    Push(23);
    Display();

    printf("\n========================================\n");
    printf("Ist der Stack leer (1 -> ja, 0 -> nein): ");
    printf("%d\n", StackEmpty());
    
    printf("\n========================================\n");
    printf("Lösche den Stack:\n");
    StackClear();
    Display();

    printf("\n========================================\n");
    printf("Ist der Stack leer (1 -> ja, 0 -> nein): ");
    printf("%d\n", StackEmpty());

    return 0;
}
