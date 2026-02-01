/*
 * Übung 25: Zeugnisnoten Struktur-Typ
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    27.02.2024
 */

#include <stdio.h>
#include <string.h>

    struct Student {
        char Name[30];
        int E_Grade;
        int G_Grade;
        int M_Grade;
    };

int main()
{
    struct Student student1;

    printf("EINGABE:\n");
    printf("==================================================\n");
    printf("student name: ");
    scanf("%s", student1.Name);
    printf("english grade: ");
    scanf("%d", &student1.E_Grade);
    printf("german grade: ");
    scanf("%d", &student1.G_Grade);
    printf("math grade: ");
    scanf("%d", &student1.M_Grade);

    double durchschnitt = (double)(student1.E_Grade  + student1.G_Grade + student1.M_Grade) /3;
    char erfolg[23];

    int Vierer = 0;
    if (student1.E_Grade == 4 || student1.G_Grade == 4 || student1.M_Grade == 4)
    {
        Vierer = 1;
    }

    if(durchschnitt > 4)
    {
        strcpy( erfolg, "nicht bestanden");
    }
    else if (durchschnitt > 1.5 && durchschnitt < 2 && !Vierer)
    {
        strcpy( erfolg, "guter Erfolg");
    }
    else if (durchschnitt < 1.5 && durchschnitt < 2 && !Vierer) 
    {
        strcpy( erfolg, "ausgezeichneter Erfolg");
    }
    else 
    {
        strcpy( erfolg, "bestanden");
    }

    printf("\nAUSGABE:\n");
    printf("==================================================\n");
    printf("Name des Schülers: %s\n", student1.Name);
    printf("Englischnote des Schüler: %d\n", student1.E_Grade);
    printf("Deutschnote des Schüler: %d\n", student1.G_Grade);
    printf("Mathenote des Schüler: %d\n", student1.M_Grade);
    printf("Notendurchschnitt des Schülers: %f\n", durchschnitt);
    printf("Erfolg des Schülers: %s\n", erfolg);
    
    return 0;
}