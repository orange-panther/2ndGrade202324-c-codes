/*
 * Übung 22: Zeitroutinen
 * ===============================
 * Autor:    Katharina Einzenberger
 * Klasse:   2AHIF
 * Datum:    05.03.2024
 */

    #include<stdio.h>
    #include<time.h>

int main() {
	time_t now;
	now = time(0);
	printf("%s\n", ctime(&now));
	return 0;
}