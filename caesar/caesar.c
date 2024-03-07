#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string str);
char rotate(char chr, int key);

int main(int argc, string argv[])
{
    // Check the numbers of command line arguments
    if (argc == 2)
    {
        // Check the argument string contains only digits
        if (only_digits(argv[1]))
        {
            int key = atoi(argv[1]);

            // Get the plaintext from user
            string plaintext = get_string("plaintext: ");
            char ciphertext[strlen(plaintext) - 1];
            for (int i = 0; i < strlen(plaintext); i++)
            {
                // Rotate the characters one by one
                char chr = rotate(plaintext[i], key);
                ciphertext[i] = chr;
            }
            // Display the ciphertext
            printf("ciphertext: %s\n", ciphertext);
        }
        else
        {
            // Display error message if argument string contains characters other than digits
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        // Display error message if number of arguments greater than one
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char chr, int key)
{
    if (isupper(chr))
    {
        chr = (chr - 'A' + key) % 26 + 'A';
    }
    else if (islower(chr))
    {
        chr = (chr - 'a' + key) % 26 + 'a';
    }
    return chr;
}
