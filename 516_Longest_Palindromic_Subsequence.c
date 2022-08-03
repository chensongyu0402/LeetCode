#include<stdio.h>
#include<stdlib.h>
#include<string>
int longestPalindromeSubseq(char * s)
{
    int len = strlen(s);
    int table[1000][1000] = {0};
    
    for(int i = 0; i < len; i++)
        table[i][i] = 1;
    
    for(int i = 0; i < len - 1; i++) {
        if(s[i] == s[i + 1]) {
            table[i][i + 1] = 2;
        }
        else
            table[i][i + 1] = 1;
    }
    
    for(int l = 3; l <= len; l++) {
        for(int i = 0; i < len - l + 1;i++) {
            int j = i + l - 1;
            if(s[i] == s[j])
                table[i][j] = table[i + 1][j - 1] + 2;
            else
                table[i][j] = table[i + 1][j] > table[i][j - 1] ? table[i + 1][j] : table[i][j - 1];
        }
    }
    return table[0][len - 1];
}