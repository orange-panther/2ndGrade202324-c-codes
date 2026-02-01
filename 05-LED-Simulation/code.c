/*
 * Übung 05: LED-Simulation
 * ===============================
 * Autor:   Katharina Einzenberger
 * Klasse:  2AHIF
 * Datum:   24.11.2023
 */

#include <stdio.h>

int ausgabe(unsigned char reg)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (reg & 128)
            printf("x ");
        else
            printf("  ");
        reg = reg << 1;
    }
    printf("\n");
    return 0;
}

int main()
{
    //variablen
    unsigned char reg1 = 128;
    unsigned char reg2 = 1;

    // erstes Muster
    for (int i = 0; i < 7; i++)
    {
        ausgabe(reg1);
        reg1 = reg1 >> 1;
    }
    for (int i = 0; i < 8; i++)
    {
        ausgabe(reg2);
        reg2 = reg2 << 1;
    }

    // reset 
    reg1 = 128;
    reg2 = 1;
    printf("\n");
    printf("\n");

    // zweites Muster
    for (int i = 0; i < 8; i++)
    {
        ausgabe(reg1 + reg2);
        reg1 = reg1 >> 1;
        reg2 = reg2 << 1;
    }

    // reset
    reg1 = 128;
    reg2 = 1;
    printf("\n");
    printf("\n");
    
    //drittes Muster
    ausgabe (reg1 | 255);
    for (int i = 0; i < 6; i++)
    {
        reg1 = reg1 >> 1;
        reg2 = reg2 << 1;
        ausgabe(reg1 + reg2);
    }
    ausgabe (reg1 | 255);

    return 0;
}
