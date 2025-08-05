/*  Dreh.c  -->  Eine Zeile einlesen und umgekehrt ausgeben.    */

#include <stdio.h>
#define  MAXL  100

int main()
{
    int  c, i;  char puffer[MAXL];
    printf("\nsize of puffer: %d", (sizeof(puffer) / sizeof(puffer[0])) );
    printf("\nBitte geben Sie eine Zeile Text ein:\n\n");

    for (i = 0; i < MAXL && (c = getchar()) != '\n'; ++i)
        puffer[i] = c;                  // Zeile einlesen. 

    putchar('\n');                     // Neue Zeile. 

    while (--i >= 0)                   // Zeile umgekehrt 
        putchar(puffer[i]);            // ausgeben.      

    putchar('\n');                     // Neue Zeile.
    return 0;
}