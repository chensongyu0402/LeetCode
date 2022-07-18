#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int *answer = malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    for(int i = 0; i < temperaturesSize; i++) {
        bool flag = false;
        for(int j = i; j < temperaturesSize; j++) {
            if(temperatures[j] > temperatures[i]) {
                answer[i] = j - i;
                flag = true;
                break;
            }
        }
        if(!flag)
            answer[i] = 0;
    }
    return answer;
}