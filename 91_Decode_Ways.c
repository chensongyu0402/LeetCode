#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool islegal(char c1, char c2)
{
    int n1 = (c1 - '0') * 10;
    int n2 = c2 - '0';
    return (n1 + n2 > 26) ? false : true;
}

int numDecodings(char * s)
{
    int len = strlen(s);
    if(len == 0 || s[0] == '0')
        return 0;
    if(len == 1)
        return 1;
    
    int a = 1, b = 1;
    for(int i = 1; i < len; i++) {
        int tmp = 0;
        if(s[i] == '0' && !islegal(s[i -1],s[i]))
            return 0;
        if(s[i] != '0')
            tmp = a;
        if(islegal(s[i -1],s[i]) && s[i - 1] != '0')
            tmp += b;
        b = a;
        a = tmp;
    }
    return a;
}