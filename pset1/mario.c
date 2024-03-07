#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt the user for pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        //loop for printing spaces
        for (int j = i + 1; j < n; j++)
        {
            printf(" ");
        }
        //loop for printing bricks of pyramid
        for (int k = i + 1; k > 0; k--)
        {
            printf("#");
        }
    printf("\n");
    }
}

