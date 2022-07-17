#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caeser key \n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caeser key \n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    string plainText = get_string("Enter text to be cyphered:  ");
    printf("Cyphertext:  ");

    for (int j = 0; j < strlen(plainText); j++)
    {
        if (isupper(plainText[j]))
        {
            printf("%c", ((plainText[j] + key - 65) % 26) + 65);
        }

        else if (islower(plainText[j]))
        {
            printf("%c", ((plainText[j] + key - 97) % 26) + 97);
        }

        else
        {
            printf("%c", plainText[j]);
        }
    }
    printf("\n");
}