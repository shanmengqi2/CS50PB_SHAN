#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

const int ASCII_LOWER_A = 97;
const int ASCII_UPPER_A = 65;

string cipher(string plain, int key);
int checkArgv(string str);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("must only have 1 argument\n");
        return 1;
    }

    if (checkArgv(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plainTxt = get_string("plaintext: ");
    int key = atoi(argv[1]);

    string cipherTxt = cipher(plainTxt, key);
    printf("ciphertext: %s\n", cipherTxt);
}

int checkArgv(string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

string cipher(string plain, int key)
{
    int i = 0;
    string cipherTxt = plain;

    while (plain[i] != '\0')
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                cipherTxt[i] = (plain[i] - ASCII_UPPER_A + key) % 26 + ASCII_UPPER_A;
            }
            else
            {
                cipherTxt[i] = (plain[i] - ASCII_LOWER_A + key) % 26 + ASCII_LOWER_A;
            }
        }
        i++;
    }
    return cipherTxt;
}
