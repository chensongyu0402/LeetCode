int majorityElement(int* nums, int numsSize)
{
    int res = nums[0];
    int count = 1;
    for(int i = 1; i < numsSize; i++) {
        if(res == nums[i])
            count ++;
        else {
            count --;
            if(count < 0) {
                res = nums[i];
                count = 1;
            }
        }
    }
    return res;
}