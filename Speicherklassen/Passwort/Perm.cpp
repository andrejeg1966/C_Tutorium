#include <stdio.h>
#include <string.h>
#include <time.h>

#define FALSE  0
#define TRUE   1

static char geheimwort[21] = "YZARC";         // Passwort 
static int  maxanzahl = 3, maxzeit = 60;
static int  zeitdiff(void);

int permission()       // Passwort einlesen und pruefen
{                      // Return-Wert = 0, falls Passwort falsch
    char wort[21];                     // Fuer die Eingabe
    int count = 0, zeit = 0;

    zeitdiff();                        // Die Zeit laeuft.
    while (++count <= maxanzahl)       // Anzahl Versuche 
    {
        printf("\n\nGeben Sie das Passwort ein:  ");
        fflush(stdin);  scanf_s("%20s", wort);

        zeit += zeitdiff();
        if (zeit >= maxzeit)          // Zeitlimit:  
            break;                      // maxzeit Sekunden.

        if (strcmp(wort, geheimwort) == 0)
            return TRUE;                // Erlaubnis geben.

        printf("\nPasswort ungueltig!\n");
    }
    return FALSE;                      // Erlaubnis verweigern.
}

static int zeitdiff()           // Liefert die Anzahl Sekunden 
{                               // seit dem letzten Aufruf.
    static time_t  sec = 0;
    time_t  altsec;

    altsec = sec;                    // Alte Zeit merken.
    time(&sec);                      // Neue Zeit lesen. 

    return (int)(sec - altsec);
}


void change_permission()             // Passwort aendern
{
    char wort[21];

    /*  ---    Neues Passwort einlesen:     ---  */

    printf("\n\nNeues Passwort (2 bis 20 Zeichen):  ");
    fflush(stdin);  
    scanf_s("%20s", wort);

    if (strlen(wort) > 1)
    {
        strcpy_s(geheimwort, wort);
        printf("\nDas neue Passwort: %s\n", geheimwort);
    }
    else
        printf("\nDas Passwort wurde nicht ge„ndert!\n");

    printf("\n\nWeiter mit beliebiger Taste! "); 
    //getch();
}


