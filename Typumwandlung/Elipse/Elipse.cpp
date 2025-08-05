/* Ellipse.c  -->  Dieses Programm zeichnet eine Ellipse.         *
 * Fuer die Punkte (x,y) einer Ellipse mit dem Mittelpunkt (0,0), *
 * der Hauptachse A und der Nebenachse B gilt:                    *
 *    x = A*cos(t), y = B*sint(t)  fuer  0 <= t <= 2*PI .         */


#include <stdio.h>
#include <math.h>                  // Prototypen von sin() und cos() 

#define  CLS          printf("\033[2J")
#define  LOCATE(z,s)  printf("\033[%d;%dH", z,s)

 // Einen Stern an der Stelle (x,y) ausgeben:
#define  DOT(x,y)     LOCATE(y,x), putchar('*')

#ifndef  PI                         // Falls PI nicht definiert ist 
#define  PI  3.1416
#endif

#define  Mx  40                     // Der Punkt (Mx, My) ist der
#define  My  12                     // Mittelpunkt der Ellipse.
#define  A   25                     // Laenge der Hauptachse, 
#define  B   20                     // Laenge der Nebenachse. 

int main()
{
    int x, y;                        // Bildschirmkoordinaten. 
    double t, scale = 0.4;          // scale = Verhaeltnis der Punkt- 
    // abstaende in x und y-Richtung.
    CLS;
    for (t = 0.0; t < PI / 2; t += 0.03)
    {
        x = (int)(A * cos(t) + 0.5);
        y = (int)(scale * B * sin(t) + 0.5);

        DOT(x + Mx, y + My);
        DOT(x + Mx, -y + My);
        DOT(-x + Mx, y + My);
        DOT(-x + Mx, -y + My);
    }
    LOCATE(24, 1); getchar();

    return 0;
}

