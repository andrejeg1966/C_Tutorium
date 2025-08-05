/*  Ball2.c   -->    Simuliert einen springenden Ball           */

#include <stdio.h>
#include <conio.h>          // Prototypen von kbhit() und getch()

#define  DELAY        20000000L          // Verzoegerung der Ausgabe

#define  CLS          printf("\033[2J")
#define  LOCATE(z,s)  printf("\033[%d;%dH", z, s)
#define  WHITE_BLUE   printf("\033[37;44m")   // weiss auf blau
#define  YELLOW_BLUE  printf("\033[1;33;44m") // hell gelb (doppelte Helligkeit)
                                              // auf blau
#define  NORMAL       printf("\033[0m")       // Normale Darstellung

int main()
{
    int  x, y, dx = 1, geschw = 0;
    long warten;

    WHITE_BLUE;  CLS;
    LOCATE(1, 25);  printf("****  SPRINGENDER BALL  ****");

    for (y = 3; y < 25; ++y)                     // Linke Wand
        LOCATE(y, 1), putchar((unsigned char)'|');
    LOCATE(y, 1); putchar((unsigned char)'+');

    LOCATE(25, 2);                                  // Boden
    printf("--------------------------------------"
           "--------------------------------------");

    LOCATE(25, 79);  putchar((unsigned char)'+');
    for (y = 24; y > 2; --y)                     // Rechte Wand
        LOCATE(y, 79), putchar((unsigned char)'|');

    x = 3; y = 3;                        // Einwurf in diesem Punkt
    YELLOW_BLUE;                         // Ball gelb anzeigen
    
    while (!_kbhit())                    // solange keine Taste gedrückt
    {
        LOCATE(y, x); putchar('O');           // Ball anzeigen
        LOCATE(25, 1);                         // Cursor in die lezte Zeile
        fflush(stdout);

        for (warten = 0; warten < DELAY; ++warten)
            ;

        if (x == 2 || x == 78)  dx = -dx;     // An einer Wand? 

        if (y == 24)                           // Am Boden?   
        {
            geschw = -geschw;
            if (geschw == 0)  geschw = -7;       // Neu anstossen 
        }

        geschw += 1;                          // Beschleunigung = 1

        LOCATE(y, x); putchar(' ');            // Anzeige loeschen  

        y += geschw;  x += dx;                // Neue Position 
    }
    _getch();                     // Eingegebenes Zeichen auslesen 
    NORMAL; CLS;                 // Wieder normale Darstellung, Bildschirm loeschen 
    

    return 0;
}
