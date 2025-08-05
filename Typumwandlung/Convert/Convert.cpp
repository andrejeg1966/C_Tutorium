/*  Convert.c  -->  Demonstration von Typumwandlungen.        */

#include <stdio.h>

int main()
{
    unsigned char  v_uchar;
    unsigned long  v_ulong;
    int            v_int;
    float          x_float, y_float;
#define PULLUP (1 << 2)

    v_int = -2;
    printf("v_int:         %d  %u  %X\n", v_int, v_int, v_int);

    v_uchar = v_int;
    v_ulong = v_int;
    printf("v_uchar:       %u  %X\n", v_uchar, v_uchar);
    printf("v_ulong:       %lX\n", v_ulong);

    x_float = 3.6F;
    printf("x_float:       %f\n", x_float);
    printf("(int)x_float:  %d\n", (int)x_float);

    y_float = x_float / v_int;
    printf("y_float:       %f\n", y_float);
    printf("(int)y_float:  %d\n", (int)y_float);

    printf("\n PULLUP %d", PULLUP);

    return 0;
}
