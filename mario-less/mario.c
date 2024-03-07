#include <cs50.h>
#include <stdio.h>
int get_height(void);

int main(void)
{
    // get the pyramid's height from user
    int height = get_height();

    for (int i = 0; i < height; i++)
    {
        // loop for printing spaces
        for (int j = i + 1; j < height; j++)
        {
            printf(" ");
        }
        // loop for printing bricks of pyramid
        for (int k = i + 1; k > 0; k--)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}
