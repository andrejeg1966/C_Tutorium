//*   Sincurve.c   -->   Ausgabe der Sinus-Kurve                 */

#include <stdio.h>
#include <math.h>

#ifndef  PI                           /* Falls PI nicht definiert  */ 
#define  PI        3.1415926536
#endif
#define  U_GRENZE  0                              /* Untergrenze   */
#define  O_GRENZE  (2 * PI)                       /* Obergrenze    */
#define  ANZ_PKT   64                 /* Anzahl Punkte der Kurve   */
#define  SCHRITT   ((O_GRENZE - U_GRENZE) / ANZ_PKT)
#define  zN        15                 /* Zeile des Nullpunkts      */
                                      /* = Zeile der x-Koordinate. */
#define  sN        10                 /* Spalte des Nullpunkts     */
                                      /* = Spalte der y-Koordinate.*/

#define  CLS          printf("\033[2J")
#define  LOCATE(z,s)  printf("\033[%d;%dH", z, s)

int main()
{
    int  zeile, spalte, anfsp, endsp;

    CLS;
    LOCATE(2, 25); printf("-------  Die Sinus-Funktion  -------");


    /*    ---  Koordinaten-Kreuz zeichnen: ---    */

    LOCATE(zN, 1);                                      // x-Achse
    for (spalte = 1; spalte < 78; ++spalte)
        //(spalte - sN) % 8 ? putchar('Ä') : putchar('Å');
        (spalte - sN) % 8 ? putchar('X') : putchar('O');
    putchar('\020');                                   // Spitze 
    LOCATE(zN - 1, sN + 64);  printf("2pi  x");
    
    for (zeile = 6; zeile < 25; ++zeile)             // y-Achse
        LOCATE(zeile, sN), putchar('Å');
    LOCATE(5, sN);  printf("\036 sin(x)");            // Spitze
    
   
    LOCATE(zN - 8, sN + 1);  printf(" 1");
    LOCATE(zN + 8, sN + 1);  printf(" -1");
    
    
    /*     ---  Sinus-Funktion ausgeben:  ---     */
    
    anfsp = sN;    endsp = anfsp + ANZ_PKT;

    for (spalte = anfsp; spalte <= endsp; ++spalte)
    {
        double y = sin((spalte - sN) * SCHRITT);
        zeile = (int)(zN - 8.0 * y + 0.5);

        LOCATE(zeile, spalte);  putchar('*');
    }

    LOCATE(25, 1);                      // Cursor in letzte Zeile 
    
    return 0;
}