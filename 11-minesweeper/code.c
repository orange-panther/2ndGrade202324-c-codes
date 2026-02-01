/*
 * Übung 11: Minesweeper 1
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    30.01.2024
 */

#include <stdio.h>

#define ROWS 4
#define COLS 5

/******************Ausgabe****************/

int Ausgabe(char matrixAusgabe[ROWS][COLS])
{
    int zeile = 0;
    int spalte = 0;

    printf("\n");

    for (zeile = 0; zeile < ROWS; zeile++)
    {
        for (spalte = 0; spalte < COLS; spalte++)
        {
            printf(" %c", matrixAusgabe[zeile][spalte]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

/******************Ausgabe Test int-Matrix ****************/
int Ausgabe_int(int matrixAusgabe[ROWS][COLS])
{
    int zeile = 0;
    int spalte = 0;

    printf("\n");

    for (zeile = 0; zeile < ROWS; zeile++)
    {
        for (spalte = 0; spalte < COLS; spalte++)
        {
            printf(" %d", matrixAusgabe[zeile][spalte]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

/***********Hauptprogramm********/
int main(void)
{
    int matrix[ROWS][COLS] =
        {
            {0, 0, 9, 0, 0},
            {0, 0, 9, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 9, 9, 9, 0},
        };
    char matrixAusgabe[ROWS][COLS] =
        {
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.'},
        };
    int zeile = 0;
    int spalte = 0;
    int versuche = 0;
    int ende = 0;
    int z;
    int sp;
    int minen = 0;
    int success = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (matrix[i][j] == 9)
            {
                minen++;
            }
        }
    }

    while (ende == 0)
    {
        Ausgabe(matrixAusgabe);

        printf("Bitte Zeile eingeben: ");
        scanf("%d", &zeile);
        if (zeile > ROWS || zeile < 1)
        {
            printf("Eingabe ist ungültig. Bitte versuche es erneut.\n");
            continue;
        }
        zeile = zeile - 1;

        printf("Bitte Spalte eingeben: ");
        scanf("%d", &spalte);
        if (spalte > COLS || spalte < 1)
        {
            printf("Eingabe ist ungültig. Bitte versuche es erneut.\n");
            continue;
        }
        spalte = spalte - 1;
        getchar();

        if (matrix[zeile][spalte] != 9 && matrixAusgabe[zeile][spalte] != matrix[zeile][spalte] + '0')
        {
            matrixAusgabe[zeile][spalte] = matrix[zeile][spalte] + '0';
            versuche++;
        }
        else
        {
            matrixAusgabe[zeile][spalte] = 'X';
            ende = 1;
        }

        if (COLS * ROWS - minen == versuche)
        {
            ende = 1;
            success = 1;
        }
    }
    if (success == 0)
    {
        Ausgabe(matrixAusgabe);
        printf("Sie sind explodiert!\n");
        printf("Sie hatten %d erfolgreiche Versuche. \n", versuche);
    }
    else
    {
        printf("Herzlichen Glückwunsch! Sie haben alle Minen gefunden\n");
    }
    // getchar();

    return (0);
}