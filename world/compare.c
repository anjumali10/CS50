#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = get_int("Enter value of a ");
    int b = get_int("Enter value of b ");

    if(a < b)
    {
        printf("a is less than b\n");
    }
    else if(a > b)
    {
        printf("a is greater than b\n");
    }
    else
    {
        printf("a is equal to b\n");
    }
}
