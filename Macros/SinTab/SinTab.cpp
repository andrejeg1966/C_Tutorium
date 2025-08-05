/*  SinTab.c  -->  Tabelle fuer  die Sinus-Funktion           */

#include <stdio.h>
#include <math.h>

#ifndef  PI                     // Falls PI nicht definiert ist 
#define  PI        3.1415926536
#endif

#define  U_GRENZE  0                          // Untergrenze 
#define  O_GRENZE  (2 * PI)                   // Obergrenze  
#define  SCHRITT   (PI / 8)                   // Schrittbreite 

int main()
{
    double x;

    printf("\n\n      "
        "*******  Tabelle fÅr die Sinus-Funktion  *******");

    printf("\n\n\n%20s   %20s", "x", "sin(x)");
    printf("\n            "
    "-------------------------------------------\n");

    for (x = U_GRENZE; x < O_GRENZE + SCHRITT / 2; x += SCHRITT)
        printf("   %20f %20f\n", x, sin(x));

    printf("\n");

    return 0;
}