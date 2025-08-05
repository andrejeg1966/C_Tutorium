/* Cutline1.c --> Ein Filter, der ueberfluessige Zwischenraum-  *
 *                zeichen am Ende von Zeilen entfernt.          *
 *                                                              *
 *                Module:  Cutline1.c, Cutline2.c               */

 /* Beispiel-Aufrufe:  Cutline  < Datei1.txt  > Datei2.txt       *
  *                    Cutline  > Notiz.txt                      *
  * Beim Lesen von der Tastatur (2. Beispiel) wird die Eingabe   *
  * mit Strg+Z (DOS/Windows) oder Strg+D (Unix) beendet.         */

#include <stdio.h>
#define  MAX  512+1                     // Maximale Zeilenlaenge 

extern void cutline(void);             // Prototyp von cutline()

char line[MAX];                                 // Definition

int main()
{                                   // Text zeilenweise einlesen: 
    while (fgets(line, MAX, stdin) != 0)
    {
        cutline();                               // Zeile kuerzen. 
        fputs(line, stdout);                     // Zeile ausgeben.
    }

    return 0;
}
