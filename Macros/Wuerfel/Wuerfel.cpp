/*  Wuerfel.c  -->    Simuliert einen 6-seitigen Wuerfel         */

#include <stdio.h>
#include <conio.h>         // Prototypen von kbhit() und getch()

#define  ESC          27
#define  CLS          printf("\033[2J")
#define  LOCATE(z,s)  printf("\033[%d;%dH", z, s)

int main()
{
    unsigned  c, count = 0;;

    CLS;
    LOCATE(1, 25);  printf("****   WUERFEL   ****");

    LOCATE(3, 1);
    printf("Ich wuerfel eine Zahl zwischen 1 und 6\n\n"
        "<Leertaste> = Ergebnis,   <Esc> = Ende des Programms"
        "\n\nErgebnisse:\n\n");

    do
    {
        while (!_kbhit())
            ++count;

        if ((c = _getch()) == ' ')
            printf("%5u", count % 6 +1);

    } while (c != ESC);

    CLS;
    return 0;
}
