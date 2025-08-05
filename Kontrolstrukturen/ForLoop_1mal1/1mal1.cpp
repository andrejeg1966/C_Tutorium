// ForLoop_1mal1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <iostream>

int main()
{
    int  faktor1, faktor2;

    printf("\n\n        ");
    printf(" *******   DAS KLEINE EIN-MAL-EINS   *******");
    printf("\n\n\n\n");

    /*  --- Die 1. Zeile und 2. Zeile der Tabelle ausgeben --- */

    printf("\n     ");                           // 1. Zeile
    for (faktor2 = 1; faktor2 <= 10; ++faktor2)
        printf("%5d", faktor2);

    printf("\n         ");                          // 2. Zeile
    

        /*  -----  Die weiteren Zeilen der Tabelle ausgeben  ----- */

        for (faktor1 = 1; faktor1 <= 10; ++faktor1)
        {
            printf("\n%5d", faktor1);
            for (faktor2 = 1; faktor2 <= 10; ++faktor2)
                 printf("%5d", faktor1 * faktor2);
        }
    printf("\n\n\n\n\n");                 // Tabelle hochschieben

    return 0;
}
