#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLongestSubstring(char * s)
{
    int *table = (int*)malloc(127 * sizeof(int));
    for(int i = 0; i < 127; i++)
        table[i] = -1;
    int len = strlen(s);
    int start = 0, max = 0;
    for(int i = 0; i < len; i++) {
        if(table[s[i]] >= start) {
            start = table[s[i]] + 1;
            table[s[i]] = i;
        }
        else {
            table[s[i]] = i;
            if((i - start + 1) > max)
                max = i - start + 1;
        }
        
    }
    return max;
}

int main()
{
    char s[50000];
    scanf("%s",s);
    int max_substring = lengthOfLongestSubstring(s);
    printf("%d\n",max_substring);
    return 0;
}