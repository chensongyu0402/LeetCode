#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(char * s)
{
    int len = strlen(s), i = 0, j = len - 1;
    if(len == 0 || len == 1)
        return true;
    
    while(i < j) {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i]>='0'&&s[i]<='9') {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
        else{
            i ++;
            continue;
        }
        
        if(s[j] >= 'A' && s[j] <= 'Z' || s[j] >= 'a' && s[j] <= 'z' || s[j]>='0'&&s[j]<='9') {
            if(s[j] >= 'A' && s[j] <= 'Z')
                s[j] += 32;
        }
        else{
            j --;
            continue;
        }
        
        if(s[i] != s[j])
            return false;
        i ++;
        j --;
    }
    return true;
}