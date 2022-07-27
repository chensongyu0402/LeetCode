#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define ALPHABET_SIZE (26)
typedef struct {
    struct Trie *children[ALPHABET_SIZE];
    bool isleaf;
} Trie;

Trie* trieCreate()
{
    Trie *newNode = malloc(sizeof(Trie));
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    newNode->isleaf = false;
    return newNode;
}

void trieInsert(Trie* obj, char * word)
{
    int len = strlen(word);
    int index;
    for(int i = 0; i < len; i++) {
        index = word[i] - 'a';
        if(!obj->children[index])
            obj->children[index] = trieCreate();
        obj = obj->children[index];
    }
    obj->isleaf = true;
}

bool trieSearch(Trie* obj, char * word)
{
    int len = strlen(word);
    int index;
    for(int i = 0; i < len; i++) {
        index = word[i] - 'a';
        if(!obj->children[index])
            return false;
        obj = obj->children[index];
    }
    return (obj != NULL && obj->isleaf);
}

bool trieStartsWith(Trie* obj, char * prefix)
{
    int len = strlen(prefix);
    int index;
    for(int i = 0; i < len; i++) {
        index = prefix[i] - 'a';
        if(!obj->children[index])
            return false;
        obj = obj->children[index];
    }
    return true;
}

void trieFree(Trie* obj)
{
    free(obj);
}