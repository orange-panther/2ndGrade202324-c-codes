/*
 * Übung 24: Kalenderwochen
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    05.03.2024
 */

#include <stdio.h>
#include <time.h>

int main()
{
    int day, month, year;
    printf("Datum eingeben (TT.MM.JJJJ): ");
    scanf("%d.%d.%d", &day, &month, &year);

    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    time_t time = mktime(&date);
    struct tm *dateInfo = localtime(&time);

    int week = dateInfo->tm_yday / 7 + 1;
    printf("Das Datum %02d.%02d.%04d ist in der %d. Kalenderwoche.\n", day, month, year, week);
}
