/* Scanf.c  --> Beispiele zu scanf() zum Einlesen von Strings */

# include <stdio.h>

char text[501], rest[501], a[2];

int main()
{
    do
    {
        fflush(stdin);                      // Eingabepuffer leeren.

        puts("\nBitte Text eingeben!\n"
            "Mit <.> oder <!> und <Return> abschliessen:\n");

        //scanf_s("%500[^!.]", text);
        scanf_s("%500[^bB]", text);
       // gets(rest); 
       fgets(rest, 500, stdin); 

        puts("\nMit scanf() wurde eingelesen:");
        puts(text);

        puts("\nNicht gelesen wurde:");
        puts(rest);

        printf("\nWeiter machen (j/n)?  ");
        while (scanf_s("%1[JNjn]", a) == 0)     // Antwort einlesen.
            fflush(stdin);                    // Wiederholen, bis
        // gueltige Eingabe kommt.
    } while (a[0] == 'j' || a[0] == 'J');

    puts("\nGOOD BYE");
    return 0;
}

