#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

const int ARR[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int ASCII_LOWER_A = 97;
const int ASCII_UPPER_A = 65;

int calculateScore(string str);

int main(void)
{

    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    if (calculateScore(p1) > calculateScore(p2))
    {
        printf("Player 1 wins!\n");
    }
    else if (calculateScore(p1) < calculateScore(p2))
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculateScore(string str)
{

    int score = 0;
    int n;
    int i = 0;
    while (str[i] != '\0')
    {
        if (islower(str[i]))
        {
            n = str[i] - ASCII_LOWER_A;
            score += ARR[n];
        }
        else if (isupper(str[i]))
        {
            n = str[i] - ASCII_UPPER_A;
            score += ARR[n];
        }
        i++;
    }
    return score;
}
