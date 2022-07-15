#include<stdio.h>
#include<stdlib.h>

void method1(int* nums, int numsSize) // as same as BubbleSort
{
    for(int i = 0; i < numsSize; i++)
        for(int j = 0; j < numsSize - i - 1; j++)
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
}

void method2(int* nums, int numsSize) // better than method1
{
    int red = 0, white = 0, blue = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0)
            red++;
        else if(nums[i] == 1)
            white++;
        else
            blue ++;
    }
    for(int i = 0; i < numsSize; i++) {
        if(red > 0) {
            nums[i] = 0;
            red --;
        }
        else if (red <= 0 && white > 0) {
            nums[i] = 1;
            white --;
        }
        else {
            nums[i] = 2;
            blue --;
        }
    }
}

void method3(int* nums, int numsSize) // better than method3 because it has less comparisons than method2
{
    int red = 0, white = 0, blue = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0)
            red++;
        else if(nums[i] == 1)
            white++;
        else
            blue ++;
    }
    int i = 0;
    while(red > 0) {
        nums[i++] = 0;
        red --;
    }
    while(white > 0) {
        nums[i++] = 1;
        white --;
    }
    while(blue > 0) {
        nums[i++] = 2;
        blue --;
    }
    
}