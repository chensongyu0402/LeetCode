#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

int method1(char * s) //brute force
{
    int len = strlen(s);
    int numSub = 0;
    for(int i = 1; i <= len; i++) {
        for(int j = 0;j < len; j++) {
            bool p = true;
            if(j + i > len)
                break;
            for(int k = 0; k < i; k++) {
                if (j + k >= j + i - 1 - k)
                    break;
                if (s[j + k] != s[j + i - 1 - k])
                    p = false;
            }
            if(p) numSub++;
        }
    }
    return numSub;
}

int method2(char *s) //dynamic programming
{
    int count = 0;
    int len = strlen(s);
    char **dp = malloc(sizeof(char *) * len);
    for(int i = 0; i < len; i++) {
        dp[i] = calloc(len,sizeof(char));
        dp[i][i] = 1;
        count++;
    }
    for(int i = 1; i < len; i++) {
        if(s[i - 1] == s[i]) {
            dp[i - 1][i] = 1;
            count ++;
        }
    }
    for(int i = 3; i <= len; i++) {
        int start = 0, end = start + i -1;
        while(end < len) {
            if(dp[start + 1][end - 1] && s[start] == s[end]) {
                dp[start][end] = 1;
                count ++;
            }
            start ++;
            end++;
        }
    }
    for (int i = 0; i < len; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return count;
}

int main()
{
    char s[1000];
    scanf("%s",s);
    int count = method2(s);
    printf("countSubstrings==%d",count);
    return 0;
}