#include<stdio.h>
#include<stdlib.h>

int minSubArrayLen(int target, int* nums, int numsSize)
{
    int min = numsSize;
    int start = 0, sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if(sum >= target) {
            while((sum - nums[start]) >= target) {
                sum -= nums[start];
                start ++;
            }
            if(i - start + 1 < min)
                min = i - start + 1;
        }
    }
    if (sum < target)
        return 0;
    else
        return min;
    
}

int main()
{
    int target;
    int num[50000];
    int numSize = 0;
    int elements;
    printf("target:");
    scanf("%d",&target);
    printf("numSize:");
    scanf("%d",&numSize);
    for(int i = 0; i < numSize; i++)
        scanf("%d",&num[i]);
    int minLen = minSubArrayLen(target, num, numSize);
    printf("minSubArrayLen==%d\n",minLen);
    return 0;
}