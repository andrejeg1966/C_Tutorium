/*  ToUpper.c  --> Wandelt in einem Text alle Kleinbuchstaben in    *
 *                 Grossbuchstaben um, einschliesslich der Umlaute  *
 * ---------------------------------------------------------------- *
 * Beim Lesen von der Tastatur (also ohne Eingabe-Umlenkung)        *
 * die Eingabe mit Strg+Z (DOS/Windows) bzw. Strg+D (Unix) beenden. */

#include <stdio.h>
#include <ctype.h>

int main()
{
    int  c;

    while ((c = getchar()) != EOF)       /* Zeichen einzeln lesen */
    {
        switch (c)
        {
        case 0x84:  c = 'é';                     //  0x84 = 'Ñ' 
            break;

        case 0x94:  c = 'ô';                     //  0x94 = 'î' 
            break;

        case 0x81:  c = 'ö';                     //  0x81 = 'Å' 
            break;

        case 0xE1:  putchar('S'); c = 'S';       //  0xE1 = '·' 
            break;

        default:    c = toupper(c);
        }
        printf("%d \n", c);
        putchar(c);              // Umgewandeltes Zeichen ausgeben.
    }
    return 0;
}