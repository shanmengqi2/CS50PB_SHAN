#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int countLetters = 0;
    int countSentences = 0;
    int countWords = 1;
    string text = get_string("Text: ");
    bool isBlank = false;

    // index = 0.0588 * L - 0.296 * S - 15.8
    /*where L is the average number of letters per 100 words in the text,
     *and S is the average number of sentences per 100 words in the text.
     */

    int i = 0;
    while (text[i] != '\0')
    {
        if (isalpha(text[i]) && !ispunct(text[i]))
        {
            countLetters += 1;
            isBlank = false;
        }
        else if (isblank(text[i]) && !isBlank)
        {
            countWords += 1;
            isBlank = true;
        }
        else if ((text[i]) == '.' || text[i] == '!' || text[i] == '?')
        {
            countSentences += 1;
            isBlank = false;
        }
        i++;
    }
    float L = countLetters / (float) countWords * 100;
    float S = countSentences / (float) countWords * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
