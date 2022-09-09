#define max(a,b) (a > b ? a : b)

int maxSubArray(int* nums, int numsSize)
{
    int ans = -99999;
    int count = 0;
    for(int i = 0; i < numsSize; i++) {
        count += nums[i];
        ans = max(ans,count);
        if(count < 0)
            count = 0;
    }
    return ans;
}