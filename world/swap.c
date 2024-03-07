#include <stdio.h>

void swap(int *a, int *b, int *c);
int main(void)
{
    int a = 12;
    int b = 2;
    int c = 4;

    printf("a is: %i\nb is: %i\nc is: %i\n", a, b, c);
    swap(&a, &b, &c);
    printf("a is: %i\nb is: %i\nc is: %i\n", a, b, c);
}

void swap(int *a, int *b, int *c)
{
    int temp = *a;
    *a = *c;
    *b = *b;
    *c = temp;
}
