/*
 * Übung 13: Rekursion
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    06.02.2024
 */

#include <stdio.h>

long Fakultät(long nummer)
{
    if (nummer)
    {
        return nummer * Fakultät(nummer - 1);
    }
    return 1;
}

int Multiplikation(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    else
    {
        return a + Multiplikation(a, b - 1);
    }
}

int Division(int a, int b)
{
    if (a < b)
    {
        return 0;
    }
    else
    {
        return 1 + Division(a - b, b);
    }
}

int Fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

long ggt(long a, long b)
{
    int ergebnis = 0;
    if (a == b || b == 0)  {return a;}
    else {
        return ggt(b, a % b);
    }
}

int main(void)
{
    printf("FAKULTÄT\n");
    printf("------------------------------------\n");
    printf("Fakultät von 5 = %ld\n", Fakultät(5));
    printf("Fakultät von 9 = %ld\n", Fakultät(9));
    printf("\n");

    printf("MULTIPLIKATION\n");
    printf("------------------------------------\n");
    printf("Multipliziere 5 mit 9: %d\n", Multiplikation(5, 9));
    printf("Multipliziere 3 mit 17: %d\n", Multiplikation(3, 17));
    printf("\n");

    printf("DIVISION\n");
    printf("------------------------------------\n");
    printf("Division von 24 durch 6: %d\n", Division(24, 6));
    printf("Division von 121 durch 11: %d\n", Division(121, 11));
    printf("\n");

    printf("FIBONACCI\n");
    printf("------------------------------------\n");
    printf("Stelle der Fibonacci-Zahl in der Sequenz: ");
    int stelle;
    scanf("%i", &stelle);
    printf("Fibonacci term at position %d is %d\n", stelle, Fibonacci(stelle));
    printf("Stelle der Fibonacci-Zahl in der Sequenz: ");
    scanf("%i", &stelle);
    printf("Fibonacci-Zahl an der Stelle %d ist %d\n", stelle, Fibonacci(stelle));

    printf("GRÖSSTER GEMEINSAMER TEILER\n");
    printf("------------------------------------\n");
    printf("Größter gemeinsamer Teiler von 3 und 6: %ld\n", ggt(3, 6));
    printf("Größter gemeinsamer Teiler von 11 und 50: %ld\n", ggt(11, 50));
    printf("\n");
    return 0;
}
