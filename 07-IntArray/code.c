/*
 * Übung 07: Int-Array
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    12.12.2023
 */

#include <stdio.h>
const int LÄNGE = 5;

int Ausgabe(int numbers[])
{
    for (int i = 0; i < LÄNGE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    int zahlen[LÄNGE];

    // Eingabe des Arrays
    for (int i = 0; i < LÄNGE; i++)
    {
        int zahl;
        printf("Gib einen Wert ein: ");
        scanf("%i", &zahl);
        if (zahl > 0)
        {
            zahlen[i] = zahl;
        }
        else
        {
            printf("Die Eingabe muss positiv sein.\n");
            i--;
        }
    }
    printf("\n");

    // Ausgabe des Arrays
    printf("Ausgabe des Arrays: ");
    Ausgabe(zahlen);

    // Mittelwert des Arrays
    int Summe = 0;
    for (int i = 0; i < LÄNGE; i++)
    {
        Summe = Summe + zahlen[i];
    }
    float mittelwert = Summe / LÄNGE;
    printf("Mittelwert: %5.3f\n", mittelwert);

    // größte Zahl des Arrays
    int größte_Zahl = 0;
    int zweitgrößte_Zahl = 0;

    for (int i = 0; i < LÄNGE; i++)
    {
        if (zahlen[i] > größte_Zahl)
        {
            größte_Zahl = zahlen[i];
        }
    }
    printf("Größter Wert: %d\n", größte_Zahl);

    // zweitgrößte Zahl des Arrays
    for (int i = 0; i < LÄNGE; i++)
    {
        if (zahlen[i] < größte_Zahl)
        {
            if (zahlen[i] > zweitgrößte_Zahl)
            {
                zweitgrößte_Zahl = zahlen[i];
            }
        }
    }
    printf("Zweitgrößter Wert: %d\n", zweitgrößte_Zahl);

    // doppelte Werte entfernen
    for (int i = 0; i < LÄNGE; i++)
    {
        for (int j = 0; j < LÄNGE; j++)
        {
            if (zahlen[i] == zahlen[j] && j != i)
            {
                zahlen[j] = -1;
            }
        }
    }
    printf("Ausgabe des Arrays mit ersetzten Zahlen: ");
    Ausgabe(zahlen);

    // Arrays mit Bubble Sort sortieren
    for (int step = 0; step < LÄNGE - 1; ++step)
    {
        for (int i = 0; i < LÄNGE - step - 1; ++i)
        {
            if (zahlen[i] > zahlen[i + 1])
            {
                int temp = zahlen[i];
                zahlen[i] = zahlen[i + 1];
                zahlen[i + 1] = temp;
            }
        }
    }
    printf("Ausgabe des sortierten Arrays: ");
    Ausgabe(zahlen);

    return 0;
}