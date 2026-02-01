/*
 * Übung 30: Sortieren eines Arrays
 * Übung 31: Binäre Suche
 * ================================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    27.02.2024
 */

#include <stdio.h>
const int LÄNGE = 8;

int ausgabe(int numbers[])
{
    for (int i = 0; i < LÄNGE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    return 0;
}

int bubblesort(int numbers[])
{
    int somethingSwitched = 0;

    do 
    {
        somethingSwitched = 0;
        for(int i = 0; i < LÄNGE -1; i++)
        {
            if (numbers[i] > numbers[i+ 1]){
                int help = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = help;
                somethingSwitched = 1;
            }
        }
    } while(somethingSwitched);

    return 0;
}

int binarySearch(int numbers[], int lookNumber)
{
    int begin = 0; 
    int end = LÄNGE + 1;

    while(begin != end)
    {
        int pos = (begin + end) / 2;
        if (numbers[pos]  < lookNumber)
        {
            begin = pos;
        }
        else if (numbers[pos] > lookNumber)
        {
            end = pos;
        }
        else 
        {
            return pos;
        }
    }
    return -1;
    

}

int main()
{
    int numbers[] = { 1, 15, 3, 84, 54, 73, 76, 2};

    ausgabe(numbers);
    bubblesort(numbers);
    ausgabe(numbers);

    int position = binarySearch(numbers, 3);
    printf("Position of 3: %i\n", position);

    return 0;
}

