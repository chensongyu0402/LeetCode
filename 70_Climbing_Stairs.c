#include<stdio.h>
#include<stdlib.h>

int climbStairs(int n)
{
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    
    int a = 1, b = 2;
    int c;
    for(int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}