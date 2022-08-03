#include <stdio.h>
#include <stdlib.h>
#define MALLOC_UNIT 5000
static int compare(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if(numsSize < 3)
        return NULL;
    
    qsort(nums, numsSize, sizeof(int), compare);
    int count = MALLOC_UNIT, ret_size = 0;
    int **ret = (int **)malloc(sizeof(int *)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    
    for(int i = 0; i < numsSize - 2; i++) {
        if(i > 0 && nums[i - 1] == nums[i])
            continue;
        int target = (-1) * (nums[i]), left = i + 1, right = numsSize - 1;
        while(left < right) {
            if(left > i + 1 && nums[left -1] == nums[left]) {
                left ++;
                continue;
            }
            if(nums[left] + nums[right] == target) {
                ret_size ++;
                if(ret_size == count) {
                    count <<= 1;
                    ret = realloc(ret, sizeof(int *) * count);
                    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * count);
                }
                ret[ret_size - 1] = malloc(sizeof(int) * 3);
                ret[ret_size - 1][0] = nums[i];
                ret[ret_size - 1][1] = nums[left];
                ret[ret_size - 1][2] = nums[right];
                (*returnColumnSizes)[ret_size - 1] = 3;
                left ++;
            }
            else if (nums[left] + nums[right] < target) {
                left ++;
            }
            else {
                right --;
            }
        }
    }
    *returnSize = ret_size;
    return ret;
}