/*  Bubble.c --> Ganze Zahlen mit dem Sortier-         */
/*               algorithmus "Bubble-Sort" sortieren.  */

#include <stdio.h>

#define  MAX          100             // Maximale Anzahl 

long zahl[MAX];               // Zur Speicherung der Zahlen

int main()
{
    int  i, anzahl;           // Index und aktuelle Anzahl. 
    int  sortiert = 0;        // Merker, ob Zahlen sortiert. 
    long hilf;                // Hilfsvariable beim Tauschen.

    printf("\n\n\t\t"
        "-------  Ganze Zahlen sortieren  -------");

    printf("\n\nGeben Sie bis zu 100 ganze Zahlen ein:"
        "\n(Abbruch durch ungueltige Eingabe)\n\n");

    /*     ---   Zahlen einlesen:   ---     */

    for (i = 0; i < MAX && scanf_s("%ld", zahl + i) == 1; ++i)
        ;
    anzahl = i;

    /*     ---  Zahlen sortieren:   ---     */

    while (!sortiert)         // Solange die Zahlen noch 
    {                         // nicht sortiert sind.
        sortiert = 1;

        for (i = 1; i < anzahl; ++i)   // Benachbarte Zahlen
            if (zahl[i - 1] > zahl[i])      // vergleichen.  
            {
                sortiert = 0;
                hilf = zahl[i];        // Tauschen 
                zahl[i] = zahl[i - 1];
                zahl[i - 1] = hilf;
            }
    }

    /*     ---  Zahlen sortiert ausgeben:  ---     */

    printf("\n\nDie Zahlen sortiert:\n\n");
    for (i = 0; i < anzahl; ++i)
        printf("%10ld", zahl[i]);

    printf("\n\n");
    return 0;
}

