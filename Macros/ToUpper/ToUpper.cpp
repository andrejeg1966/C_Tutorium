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
        case 0x84:  c = '�';                     //  0x84 = '�' 
            break;

        case 0x94:  c = '�';                     //  0x94 = '�' 
            break;

        case 0x81:  c = '�';                     //  0x81 = '�' 
            break;

        case 0xE1:  putchar('S'); c = 'S';       //  0xE1 = '�' 
            break;

        default:    c = toupper(c);
        }
        printf("%d \n", c);
        putchar(c);              // Umgewandeltes Zeichen ausgeben.
    }
    return 0;
}