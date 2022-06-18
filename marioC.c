#include <cs50.h>
#include <stdio.h>

//Similar to MarioL.c this program takes user input and outputs 2 pyramids askin to 
//mario blocks with a height based off the input

int main(void)
{
    //asks user for input until posative non-zero number is input
    int n;
    do
    {
        n = get_int("How tall should we make the pyramids? ");
    }
    while (n < 1 || n > 8);


    for (int i = 0; i < n; i++)
    {
        for (int s = n; s > i; s--)
        {
            printf(" ");
        }
        for (int j = -1; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int r = -1; r < i; r++)
        {
            printf("#");
        }
        printf("\n");
    }
}