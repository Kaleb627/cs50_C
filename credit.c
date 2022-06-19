#include <cs50.h>
#include <stdio.h>

int main(void)
{
//getting credit card number from user
    long cc = get_long("Input a card number 13-16 digits long: ");

//implementing Luhns algorithem for checking card number validity
//while also checking for length
    int sum1 = 0;
    int sum2 = 0;
    long n = cc;
    int cc_check = 0;
    int cc_length = 0;
    int digit1;
    int digit2;
    int modu2;

    while (n > 0)
    {
        sum1 += (n % 10);
        n = n / 10;
        cc_length ++;

        modu2 = ((n % 10));
        n = n / 10;
        modu2 = modu2 * 2;
        digit1 = modu2 % 10;
        digit2 = (modu2 / 10);
        sum2 = sum2 + digit1 + digit2;
        cc_length ++;
    }

    cc_check = sum1 + sum2;
    if ((cc_check % 10) != 0)
    {
        printf("INVALID\n");
    }

//checking card length
    if (cc_length != 13 && cc_length != 15 && cc_length != 16)
    {
        printf("INVALID\n");
    }

//finding first digit
    long first2 = cc;

    while (first2 >= 100 )
    {
        first2 = first2 / 10;
    }

//checking type of card using card length and first digits
    if (cc_length == 15 && (first2 == 34 || first2 == 37))
    {
            printf("AMEX\n");
    }
    else if (cc_length == 16 || cc_length == 13)
    {
        if (first2 >= 51 && first2 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (first2 / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}