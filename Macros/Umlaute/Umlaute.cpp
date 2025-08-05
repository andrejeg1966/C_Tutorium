/*   Umlaute.c  -->  Wandelt in einem Text die Umlaute  Ñ, î, Å   *
 *                   in ae, oe, ue um, sowie · in ss.             *
 *                   (é, ô, ö  werden nicht beruecksichtigt.)     *
 * -------------------------------------------------------------- *
 * Beim Lesen von der Tastatur (also ohne Eingabe-Umlenkung) die  *
 * Eingabe mit Strg+Z (DOS/Windows) bzw. Strg+D (Unix) beenden.   */

#include <stdio.h>        // Definitionen der Konstanten EOF 
 // und der Makros getchar(), putchar().
int main()
{
    int  c;

    while ((c = getchar()) != EOF)       // Zeichen einzeln lesen
        switch (c)
        {
        case 0x84:                                //  0x84 = 'Ñ' 
            putchar('a');  putchar('e');
            break;
        case 0x94:                                //  0x94 = 'î'
            putchar('o');  putchar('e');
            break;
        case 0x81:                                //  0x81 = 'Å'
            putchar('u');  putchar('e');
            break;
        case 0xE1:                                //  0xE1 = '·'
            putchar('s');  putchar('s');
            break;
        default:
            putchar(c);           // Jedes andere Zeichen 
        }                                   // unveraendert ausgeben.

    return 0;
}

