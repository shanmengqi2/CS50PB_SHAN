#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkCard(string id);
string checkCardType(string id);
int validateCard(string id);

int main(void)
{
    long cardID = get_long("Number: ");
    string id = malloc(sizeof(long int) + 1);
    sprintf(id, "%ld", cardID);

    checkCard(id);
}

void checkCard(string id)
{
    if (strlen(id) < 13)
    {
        printf("INVALID\n");
        return;
    }

    if (validateCard(id) == 0)
    {
        printf("INVALID\n");
    }
    else
    {
        string cardType = checkCardType(id);
        printf("%s\n", cardType);
    }
}

string checkCardType(string id)
{
    int length = strlen(id);
    if (length == 15)
    {
        if (id[0] == '3' && (id[1] == '4' || id[1] == '7'))
        {
            return "AMEX";
        }
    }
    else if (length == 16)
    {
        if (id[0] == '5' &&
            (id[1] == '1' || id[1] == '2' || id[1] == '3' || id[1] == '4' || id[1] == '5'))
        {
            return "MASTERCARD";
        }
        else if (id[0] == '4')
        {
            return "VISA";
        }
    }
    else if (length == 13 && id[0] == '4')
    {
        return "VISA";
    }

    return "INVALID";
}

int validateCard(string id)
{
    int sum1 = 0;
    int sustracted = 0;
    for (int i = strlen(id) - 1; i > -1; i--)
    {
        if (sustracted % 2 == 0)
        {
            sum1 = sum1 + id[i] - '0';
        }
        else
        {
            int temp = (id[i] - '0') * 2;
            if (temp < 10)
            {
                sum1 = sum1 + temp;
            }
            else
            {
                sum1 = sum1 + (temp % 10) + (temp / 10);
            }
        }
        sustracted++;
    }

    // printf("sum1 = %i\n", sustracted);

    if (sum1 % 10 == 0)
    {
        return 1;
    }

    return 0;
}
