#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get text from the user
    string text = get_string("Text: ");

    // Count letters in the text
    int letters = count_letters(text);

    // Count words in the text
    int words = count_words(text);

    // Count sentences in the text
    int sentences = count_sentences(text);

    // Find the average number of letters per 100 words
    float L = letters / (float) words * 100;

    // Find the average number of sentences per 100 words
    float S = sentences / (float) words * 100;

    // Find the index value
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Display the readability level
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

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if ((text[i] >= 'A' & text[i] <= 'Z') || (text[i] >= 'a' & text[i] <= 'z'))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences += 1;
        }
    }
    return sentences;
}
