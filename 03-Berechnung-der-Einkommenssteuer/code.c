/*
 * Übung 03: Berechnung der Lohnsteuer
 * ===============================
 * Autor:   Katharina Einzenberger
 * Klasse:  2AHIF
 * Datum:   13.10.2023
 */
#include <stdio.h>

int main()
{
    printf("Geben Sie Ihr Jahresgehalt ein: ");
    int gehalt;
    scanf("%i", &gehalt);

    printf("Geben Sie Ihre Werbekosten ein: ");
    int werbekosten;
    scanf("%i", &werbekosten);

    printf("Geben Sie Ihre Pendlerpauschale ein: ");
    int pendlerpauschale;
    scanf("%i", &pendlerpauschale);

    printf("Geben Sie Ihren Pendlereuro ein: ");
    int pendlereuro;
    scanf("%i", &pendlereuro);

    gehalt = gehalt - werbekosten - pendlerpauschale;
    float steuern;

    while (gehalt > 0)
    {
        if (gehalt > 1000000)
        {
            steuern += (gehalt - 1000000) * 55 / (float)100;
            gehalt -= (gehalt - 1000000);
        }
        else if (gehalt > 90000)
        {
            steuern += (gehalt - 90000) * 50 / (float)100;
            gehalt -= (gehalt - 90000);
        }
        else if (gehalt > 60000)
        {
            steuern += (gehalt - 60000) * 48 / (float)100;
            gehalt -= (gehalt - 60000);
        }
        else if (gehalt > 31000)
        {
            steuern += (gehalt - 31000) * 42 / (float)100;
            gehalt -= (gehalt - 31000);
        }
        else if (gehalt > 18000)
        {
            steuern += (gehalt - 18000) * 35 / (float)100;
            gehalt -= (gehalt - 18000);
        }
        else if (gehalt > 11000)
        {
            steuern += (gehalt - 11000) * 20 / (float)100;
            gehalt -= (gehalt - 11000);
        }
        else 
        {
            steuern += 0;
            gehalt = 0;
        }
    }

    steuern -= pendlereuro;
    printf("Sie müssen %5.2f Euro an Steuern zahlen.\n", steuern);

    return 0;
}
