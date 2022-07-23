#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int maxProduct(int* nums, int numsSize)
{
    int ret = nums[0];
    int *pos = (int*)malloc(sizeof(int) * numsSize);
    int *neg = (int*)malloc(sizeof(int) * numsSize);
    pos[0] = neg[0] = nums[0];
    
    for(int i = 1; i < numsSize; i++) {
        int temp1 = nums[i] * pos[i - 1];
        int temp2 = nums[i] * neg[i - 1];
        if(temp1 > temp2) {
            pos[i] = max(temp1, nums[i]);
            neg[i] = min(temp2, nums[i]);
        } else {
            pos[i] = max(temp2, nums[i]);
            neg[i] = min(temp1, nums[i]);
        }
        ret = max(ret, pos[i]);
    }
    free(pos);
    free(neg);
    return ret;
}