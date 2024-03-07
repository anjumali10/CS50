#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

bool binary_search(node *tree, int number);

void print_tree(node *root);
void free_tree(node *root);

int main(void)
{
    node *tree = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n -> number = 2;
    n -> left = NULL;
    n -> right = NULL;
    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }

    n -> number = 1;
    n -> left = NULL;
    n -> right = NULL;
    tree -> left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }

    n -> number = 3;
    n -> left = NULL;
    n -> right = NULL;
    tree -> right = n;

    print_tree(tree);
    int num = 4;
    if (binary_search(tree, num))
    {
        printf("Number %i is present in the list\n", num);
    }
    free_tree(tree);
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root -> left);
    printf("%i\n", root -> number);
    print_tree(root -> right);
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root -> left);
    free_tree(root -> right);
    free(root);
}

bool binary_search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }else if(number < tree -> number)
    {
        return binary_search(tree -> left, number);
    }
    else if(number > tree -> number)
    {
        return binary_search(tree -> right, number);
    }
    else
    {
        return true;
    }
}
