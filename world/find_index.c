#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = "HELLO";
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int charlen = sizeof(characters) / sizeof(characters[0]);
    int pointlen = sizeof(POINTS) / sizeof(POINTS[0]);
    // printf("%i", charlen);
    // int strlen = sizeof(word) / sizeof(word[0]);
    int chr;
    int score = 0;
    for (int i = 0; i <= strlen(word); i++)
    {
        for (int j = 0; j <= charlen; j++)
        {
            if (islower(word[i]))
            {
                chr = toupper(word[i]);
            }
            else
            {
                chr = word[i];
            }
            if (chr == characters[j])
            {
                score = score + (int) POINTS[j];
                // printf("%i\n", j);
            }
            else if (chr != characters[j])
            {
                score = score + 0;
            }
        }
    }
    printf("%i\n", score);
}
