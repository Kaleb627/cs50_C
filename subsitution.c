#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //verifying user input 2 command line arguments
    if (argc != 2)
    {
        printf("Usage: ./subsituion key \n");
        return 1;
    }

    //checking key length
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        //checking that key only contains alpha characters
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only letters. \n");
            return 1;
        }

        //checking that each letter in k is unique
        for (int q = i + 1; q < strlen(argv[1]); q++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][q]))
            {
                printf("Key must contain each letter only once. \n");
                return 1;
            }
        }
    }

    for (int u = 0; u < strlen(argv[1]); u++)
    {
        argv[1][u] = toupper(argv[1][u]);
    }

    string plainText = get_string("Enter text to be cyphered:  ");
    printf("Cyphertext:  ");

    for (int j = 0; j < strlen(plainText); j++)
    {
        //matching to key if uppercase
        if (isupper(plainText[j]))
        {
            printf("%c", (argv[1][(plainText[j] - 65)]));
        }

        //matching to key if lowercase
        else if (islower(plainText[j]))
        {
            printf("%c", (argv[1][(plainText[j]- 97)]) + 32);
        }

        //ignoring non alpha characters
        else
        {
            printf("%c", plainText[j]);
        }
    }
    printf("\n");
}