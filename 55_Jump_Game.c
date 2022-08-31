// method1
bool canJump(int* nums, int numsSize)
{
    if(numsSize == 1)
        return true;
    if(nums[0] == 0)
        return false;

    bool dp[numsSize];
    for(int i = 0; i < numsSize; i++)
        dp[i] = false;
    dp[0] = true;
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = 0; j <= nums[i]; j++) {
            if(i + j > numsSize - 1)
                break;
            else
                dp[i + j] = dp[i];
        }
    }
    return dp[numsSize - 1];
}
// method2

bool canJump(int* nums, int numsSize)
{
    int max = 0;
    for(int i = 0; i <= max; i++) {
        max = max < i + nums[i] ? i + nums[i] : max;
        if(max >= numsSize - 1)
            return true;
    }
    return false;
}