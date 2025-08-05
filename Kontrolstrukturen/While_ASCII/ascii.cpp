// While_ASCII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include  <stdio.h>


int main()
{
    char answer;  
    int upper;
    int ac = 32;    // Ab ASCII-Code 32 

    // ohne Steuerzeichen.
    while (1)
    {
        printf("\n\nZeichen    Dezimal    Hexadezimal\n\n");

        for (upper = ac + 20; ac < upper && ac < 256; ++ac)
            printf("   %c  %10d  %10X\n", ac, ac, ac);

        if (upper >= 256)  break;

        printf("\nWeiter --> <Return>,   Ende --> <q>+<Return> ");
        scanf_s("%c", &answer);
        if (answer == 'q' || answer == 'Q')  break;

        fflush(stdin);                // Eingabepuffer loeschen
    }
    return 0;
}

