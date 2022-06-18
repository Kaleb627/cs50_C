#include <cs50.h>
#include <stdio.h>

//This program simply displays a pyramid akin to blocks in mario
//using user input for the height of the pyramid

int main(void)
{
    //asks user for input until posative non-zero number is input
    int n;
    do
    {
        n = get_int("How tall should we make the pyramid? ");
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
        printf("\n");
    }
}