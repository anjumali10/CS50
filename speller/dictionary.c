// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // find the index of word by using hash function
    int index = hash(word);

    // Iterate over the table and compare the words
    for (node *temp = table[index]; temp != NULL; temp = temp->next)
    {
        // If word is present in the dictionary then return true otherwise return false
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Give hashes to the words
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Declare the words array to store the word from dictionary
    char word[LENGTH];

    // Open the dictionary
    FILE *file = fopen(dictionary, "r");

    // Check if file is null then close the file and return false
    if (file == NULL)
    {
        fclose(file);
        return false;
    }

    // Read the words from dictionary and store them in new node one by one
    while (fscanf(file, "%s", word) != EOF)
    {
        // Creating new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return false;
        }
        // Find the index using hash function
        int index = hash(word);

        // Copy the word into the word of node
        strcpy(n->word, word);
        n->next = table[index];

        // Insert node into the hash table
        table[index] = n;
    }

    // Close the file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Initialize the no of words with 0
    int no_of_words = 0;

    // Iterate table indexes
    for (int i = 0; i < N; i++)
    {
        // Iterate the linked list located in the given index of table
        for (node *temp = table[i]; temp != NULL; temp = temp->next)
        {
            no_of_words++;
        }
    }
    return no_of_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate the table and free nodes one by one
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        for (node *temp = table[i]; current != NULL; temp = current)
        {
            current = current->next;
            free(temp);
        }
    }
    return true;
}
