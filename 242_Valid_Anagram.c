#include <stdio.h>
#include <stdlib.h>

bool isAnagram(char * s, char * t)
{
    if(strlen(s) != strlen(t))
        return false;
    int table[26] = {0};
    for(int i = 0; i < strlen(s); i++)
        table[s[i] - 'a'] ++;
    for(int i = 0; i < strlen(t); i++) {
        table[t[i] - 'a'] --;
        if(table[t[i] - 'a'] < 0)
            return false;
    }
    return true;
}