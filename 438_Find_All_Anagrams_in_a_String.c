#include<stdio.h>
#include<stdlib.h>
// brute
int* findAnagrams(char * s, char * p, int* returnSize)
{
    int slen = strlen(s), plen = strlen(p);
    int p_count[26] = {0}, save[26] = {0};
    int *result = (int *)malloc(sizeof(int) * slen);
    *returnSize = 0;
    
    for(int i = 0; i < plen; i++) {
        p_count[p[i] - 'a'] += 1;
        save[p[i] - 'a'] += 1;
    }
    
    for(int i = 0; i < slen; i++) {
        for(int j = i;j < slen; j ++) {
            if((p_count[s[j] - 'a'] - 1) < 0)
                break;
            p_count[s[j] - 'a'] -= 1;
            plen --;
            if(plen == 0) {
                result[*returnSize] = i;
                (*returnSize) ++;
                break;
            }
        }
        
        for(int i = 0; i < strlen(p); i++)
            p_count[p[i] - 'a']  = save[p[i] - 'a'];
        plen = strlen(p);
    }
    return result;
}
// good
int* findAnagrams(char * s, char * p, int* returnSize)
{
    int slen = strlen(s), plen = strlen(p);
    int alpha[26] = {0}, alpha_cal[26] = {0};
    int *result = (int *)malloc(sizeof(int) * slen);
    *returnSize = 0;

    for(int i = 0; i < plen; i++)
        alpha[p[i] - 'a'] += 1;

    for(int i = 0; i < slen; i++) {
        int cur = s[i] - 'a';
        if(i >= plen)
            alpha_cal[s[i - plen] - 'a'] --;
        alpha_cal[cur] ++;
        if(!memcmp(alpha, alpha_cal, sizeof(int) * 26)) {
            result[*returnSize] = i - plen + 1;
            (*returnSize) ++;
        }
    }
    return result;
}