#include<stdio.h>
#include<stdlib.h>

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

int maxArea(int* height, int heightSize)
{
    int ans = 0;
    for(int i = 0, j = heightSize - 1; i <= j;) {
        ans = max(ans, min(height[i],height[j]) * (j - i));
        if(height[i] < height[j])
            i ++;
        else
            j --;
    }
    return ans;
}