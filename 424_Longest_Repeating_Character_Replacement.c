#include<stdio.h>
#include<stdlib.h>
int characterReplacement(char * s, int k)
{
    int max_counter = 0, left = 0, max_len = 0;
    int counter[26] = {0};
    
    for(int right = 0; right < strlen(s); right++) {
        counter[s[right] - 'A'] += 1;
        max_counter = counter[s[right] - 'A'] > max_counter ? counter[s[right] - 'A'] : max_counter;
        while(left <= right && (right - left + 1 - max_counter) > k) {
            counter[s[left] - 'A'] -= 1;
            left ++;
        }
        
        max_len = (right - left + 1) > max_len ? (right - left + 1) : max_len; 
    }
    return max_len;
}