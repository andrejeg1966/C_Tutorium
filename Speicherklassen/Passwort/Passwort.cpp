#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define  CLS   printf("\033[2J")

extern int   permission(void);                          // Prototypen
extern void  change_permission(void);
//extern int   toupper(int);

static char menu[] = "\n\n"                      // Das Menue im Test 
"\n\n              B = Buchung durchfuehren"
"\n\n              E = Ende des Programms"
"\n\nIhre Wahl:  ";

int main()
{
    int jn;                                             // fuer Abfrage
    int ende = 0;                             // Flag fuer Programmende

    do
    {
        CLS;
        printf("\n\n"
            "            ---  Passwort in Menueauswahl B testen  ---");
        printf(menu);

        switch (_getch())
        {
        case 'b':  case 'B':                // Buchung durchfuehren 

            CLS;
            if (!permission())
            {
                printf("\nErlaubnis verweigert!!\n");
                printf("\n\nWeiter mit beliebiger Taste! ");
                _getch();
            }
            else
            {
                CLS;
                printf("\nHerzlich willkommen . . .\n"
                    "\nWollen Sie das Passwort aendern? (J/N) ");
                fflush(stdout);

                while ((jn = toupper(_getch())) != 'J' && jn != 'N')
                    ;
                if (jn == 'J')
                    change_permission();

                /*    Hier folgt die eigentliche Anwendung.   */

            }
            break;

        case 'e':  case 'E':                 // Ende des Programms 
            CLS;
            printf("\n  GOOD BYE!\n"); ende = 1;
            break;

        } /* Ende switch */

    } while (!ende);

    return 0;
}

