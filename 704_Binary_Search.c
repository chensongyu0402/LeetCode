int search(int* nums, int numsSize, int target)
{
    if(numsSize == 0)
        return -1;
    
    int left = 0, right = numsSize - 1, mid = 0;
    int i;
    while(left <= right) {
        mid = (left + right) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}