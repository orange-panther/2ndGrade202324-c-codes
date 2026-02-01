/*
 * Übung 06: Funktionen
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    01.12.2023
 */ 

#include <stdio.h>

int einlesenWerte (float *zahl1, float *zahl2)
{
    printf("Enter the first number: ");
    scanf("%f", &*zahl1);
    printf("Enter second number: ");
    scanf("%f", &*zahl2);

}

int ausgabeErgebnis(float ergebnis)
{
    printf("Result: %1.2f\n", ergebnis);
}

int addiere(float zahl1, float zahl2, float *ergebnis)
{
    *ergebnis = zahl1 + zahl2;
}

int subtrahiere(float zahl1, float zahl2, float *ergebnis)
{
    *ergebnis = zahl1 - zahl2;
}

float multipliziere(float zahl1, float zahl2)
{
    float ergebnis = zahl1 * zahl2;
    return ergebnis;
}

float dividiere(float zahl1, float zahl2)
{
    float ergebnis;

    if (zahl2 != 0)
    {
        ergebnis = zahl1 / zahl2;
        return ergebnis;
    }
    else
    {
        printf("Division durch 0 ist nicht erlaubt!");
    }
}

int main(void)
{
    float zahl1 = 0;
    float zahl2 = 0;
    float ergebnis = 0;

    einlesenWerte(&zahl1, &zahl2);

    char operator;
    printf("Enter Operator: ");
    scanf(" %c", &operator);

    switch (operator)
    {
    case '+':
        addiere(zahl1, zahl2, &ergebnis);
        break;
    case '-':
        subtrahiere(zahl1, zahl2, &ergebnis);
        break;
    case '*':
        ergebnis = multipliziere(zahl1, zahl2);
        break;
    case '/':
        ergebnis = dividiere(zahl1, zahl2);
        break;
    }

    ausgabeErgebnis(ergebnis);

    return 0;
}