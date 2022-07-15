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