/*
 * Übung 04: Bitoperatoren
 * ===============================
 * Autor:   Katharina Einzenberger
 * Klasse:  2AHIF
 * Datum:   24.10.2023
 */
#include <stdio.h>

int ausgabe(unsigned char reg)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (reg & 128)
            printf("1");
        else
            printf("0");
        reg = reg << 1;
    }
    printf("\n");
    return 0;
}

/// @brief
/// @return
int main()
{

    unsigned char reg1 = 21;
    // printf("%x\n", reg1 & 3);
    // printf("%d\n", (reg1 || 0) & 3);
    ausgabe(reg1);
    reg1 = reg1 & ~5;
    ausgabe(reg1);
    int wert;
    unsigned char reg;
    printf("Geben Sie einen Wert ein: ");
    scanf("%d", &wert);
    reg = (char)wert;

    // Ausgabe des Registers binär
    int help = ausgabe(reg);

    int pos;
    unsigned char x = 1;

    // Bit auf Position einschalten
    printf("Geben Sie die Position ein, die Sie einschalten wollen: ");
    scanf("%d", &pos);
    if (pos > 8)
    {
        printf("Fehlermeldung: Der Wert darf nicht größer als 8 sein.\n");
        return 0;
    }
    x = x << (pos - 1);
    reg = reg | x;
    help = ausgabe(reg);

    // Bit auf Position ausschalten
    x = 1;
    printf("Geben Sie die Position ein, die Sie ausschalten wollen: ");
    scanf("%d", &pos);
    if (pos > 8)
    {
        printf("Fehlermeldung: Der Wert darf nicht größer als 8 sein.\n");
        return 0;
    }
    x = x << (pos - 1);
    reg = reg & ~x;
    help = ausgabe(reg);

    // Bit auf Position umschalten
    x = 1;
    printf("Geben Sie die Position ein, die Sie umschalten wollen: ");
    scanf("%d", &pos);
    if (pos > 8)
    {
        printf("Fehlermeldung: Der Wert darf nicht größer als 8 sein.\n");
        return 0;
    }
    x = x << (pos - 1);
    reg = reg ^ x;
    help = ausgabe(reg);

    // Bit auf Position abfragen
    x = 1;
    printf("Geben Sie die Position ein, die Sie abfragen wollen: ");
    scanf("%d", &pos);
    if (pos > 8)
    {
        printf("Fehlermeldung: Der Wert darf nicht größer als 8 sein.\n");
        return 0;
    }
    x = x << (pos - 1);
    if (reg & x)
        printf("1");
    else
        printf("0");
    printf("\n");

    return 0;
}
