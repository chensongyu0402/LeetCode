#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool method1(int *nums, int numsSize) // 浪費記憶體
{
    int min = nums[0];
    int max = nums[0];
    for(int i = 1; i < numsSize; i++) {
        min = ((nums[i] < min) ? nums[i] : min);
        max = ((nums[i] > max) ? nums[i] : max);
    }
    int len = max - min + 1;
    int *HT = (int *)malloc(sizeof(int) * len);
    for(int i = 0; i < numsSize; i++) {
        if (HT[nums[i] - min] == 1)
            return true;
        else
            HT[nums[i] - min] = 1;
    }
    return false;

}
int compare(const void *a, const void *b)
{
    int n1 = *(int*)a;
    int n2 = *(int*)b;
    return n1 - n2;
}

bool containsDuplicate(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);
    for(int i = 0; i < numsSize - 1; i ++)
        if(nums[i] == nums[i + 1])
            return true;
    return false;
}
