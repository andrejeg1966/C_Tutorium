/* Cutline2.c --> Die Funktion cutline() entfernt ueberfluessige  *
 *                Zwischenraumzeichen am End der Zeile line.      *
 *                (2. Modul zu cutline1.c)                        */

#include <string.h>                        // Prototyp von strlen() 

extern char line[];                 // Deklaration des Vektors line

void cutline()
{
    int i = strlen(line) - 1;

    if (line[i] != '\n')            // Falls keine vollstaendige
        return;                      // Zeile vorliegt.

    while (--i >= 0)               // Vom Ende her kuerzen.
        if (line[i] != ' ' && line[i] != '\t')
            break;

    line[++i] = '\n';   line[++i] = '\0';
}
