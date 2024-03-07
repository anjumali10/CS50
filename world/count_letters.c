#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string text = "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.";
    int counter = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if ((text[i] >= 65 & text[i] <= 90) || (text[i] >= 97 & text[i] <= 122))
        {
            counter += 1;
        }
    }
    printf("Letters: %i\n", counter);
}
