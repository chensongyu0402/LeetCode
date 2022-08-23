#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    return n1 -n2;
}
int* method1(int* nums, int numsSize, int target, int* returnSize)
{
    int save[numsSize];
    for(int i  = 0; i < numsSize; i++)
        save[i] = nums[i];
    qsort(nums, numsSize, sizeof(int), compare);
    int *ans = malloc(sizeof(int) * 2);
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++) {
        int key = target - save[i];
        if((int*) bsearch (&key, nums, numsSize, sizeof(int), compare) != NULL) {
            for(int j = 0; j < numsSize; j++)
                if(save[j] == key && j != i) {
                    ans[1] = j;
                    ans[0] = i;
                    break;
                }
        }
    }
    return ans;
}

int *method2(int* nums, int numsSize, int target, int* returnSize) //Hash table
{

}