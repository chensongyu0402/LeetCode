#include<stdio.h>
#include<stdlib.h>
int search(int* nums, int numsSize, int target)
{
    int head = 0, tail = numsSize - 1;
    while (head <= tail) {
        int mid = (head + tail) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < nums[tail]) {
            if (nums[mid] < target && nums[tail] >= target)
                head = mid + 1;
            else
                tail = mid - 1;
        } else {
            if (nums[mid] > target && nums[head] <= target)
                tail = mid - 1;
            else
                head = mid + 1;
        }
    }
    return -1;
}