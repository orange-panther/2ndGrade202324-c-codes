/*
 * Übung 08: Stringfunktionen
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    15.12.2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char string[])
{
    int length = 0;
    while (*string != '\0')
    {
        length++;
        string++;
    }
    return length;
}

int mystrcpy(char dest[], const char source[])
{
    int i = 0;
    while (1)
    {
        dest[i] = source[i];

        if (dest[i] == '\0')
        {
            break;
        }

        i++;
    }
    return 0;
}

int mystrcmp(char string1[], char string2[] )
{
    for (int i = 0; ; i++)
    {
        if (string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if (string1[i] == '\0')
        {
            return 0;
        }
    }
}



int main()
{
    char myString[] = {"Hello World!\n"};
    printf("String: ");
    puts(myString);

    // Länge der Zeichenkette
    int myLength = mystrlen(myString);
    printf("Länge der Zeichenkette laut meiner Methode: %i\n", myLength);
    int length = strlen(myString);
    printf("Länge der Zeichenkette: %i\n", length);
    printf("\n");

    // Kopieren der Zeichenkette
    char stringCopy[length];
    mystrcpy(stringCopy, myString);
    printf("Originaler String: ");
    puts(myString);
    printf("Kopierter String: ");
    puts(stringCopy);

    // Zeichenketten vergleichen
    char stringToCompare[] = {"Hello World!\n"};
    int result = mystrcmp(myString, stringToCompare);

    printf("Ausgabe meiner Methode:\n");
    if (result < 0)
    {
        printf("myString is less than stringToCompare\n");
    }
    else if (result > 0)
    {
        printf("myString is greater than stringToCompare\n");
    }
    else
    {
        printf("The strings are equal\n");
    }

    int result2 = strcmp(myString, stringToCompare);

    printf("Ausgabe der Bibliotheksfunktion:\n");
    if (result2 < 0)
    {
        printf("myString is less than stringToCompare\n");
    }
    else if (result2 > 0)
    {
        printf("myString is greater than stringToCompare\n");
    }
    else
    {
        printf("The strings are equal\n");
    }

    return 0;
}
