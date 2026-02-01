/*
 * Übung 02: Taschenrechner
 * ===============================
 * Autor: Katharina Einzenberger
 * Klasse: 2AHIF
 * Datum:06.10.2023
 */

#include <stdio.h>

int main(void)
{
    printf("Geben Sie den Operanten ein: ");
    char operant;
    scanf("%c", &operant);

    printf("Geben Sie die erste Zahl ein: ");
    int zahl1;
    scanf("%i", &zahl1);

    printf("Geben Sie die zweite Zahl ein: ");
    int zahl2;
    scanf("%i", &zahl2);

    float ergebnis = 0;
    switch (operant)
    {
    case '+':
        ergebnis = zahl1 + zahl2;
        break;
    case '-':
        ergebnis = zahl1 - zahl2;
        break;
    case '*':
        ergebnis = zahl1 * zahl2;
        break;
    case '/':
        if (zahl2 == 0)
        {
            printf("Die Division durch 0 ist nicht erlaubt.\n");
            return 0;
        }
        ergebnis = zahl1 / zahl2;
        break;
    case '%':
        if (zahl2 == 0)
        {
            printf("Die Division durch 0 ist nicht erlaubt, somit kann kein Rest entstehen.\n");
            return 0;
        }
        ergebnis = zahl1 % zahl2;
        break;
    default:
        printf("Sie haben einen ungültigen Operanten eingegeben.\n");
        return 0;
    }

    printf("Ihr Ergebnis lautet %5.2f\n", ergebnis);
    return 0;
}
