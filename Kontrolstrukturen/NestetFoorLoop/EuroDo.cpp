// EuroDo.c --> Programm zur Umrechnung von Euro in US-$

# include <stdio.h>

int main()
{
    long  euro, step, lower, upper, maxeuro;
    float kurs;                     // US-$ für einen Euro

    printf("\n\n * * * KURSTABELLE  Euro - US$ * * *\n\n");

    printf("\nBitte den Kurs  Euro - US$  eingeben:   ");
    scanf_s("%f", &kurs);

    printf("\nBitte Obergrenze der Tabelle eingeben:  ");
    scanf_s("%ld", &maxeuro);

    /*  ---   Ausgabe der Tabelle   ---  */

                                    // Spalten Ueberschriften:
    printf("\n\n%12s %20s\t\tKurs: %.2f\n\n", "Euro", "US-$", kurs);

    // Die aeussere Schleife bestimmt die aktuelle Untergrenze
    // und die Schrittbreite:  
    for (lower = step = 1; lower <= maxeuro; step *= 10, lower = 2 * step)
        // Die innere Schleife gibt ein "Paeckchen" aus:
        for (euro = lower, upper = step * 10;
            euro <= upper && euro <= maxeuro;  euro += step)
            printf("%12ld %20.2f\n", euro, euro * kurs);

    return 0;
}

