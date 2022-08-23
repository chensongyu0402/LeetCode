#include<stdio.h>
#include<stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
    int max = 0;
    int min = 99999;
    for(int i = 0; i < pricesSize; i++) {
       if(prices[i] < min)
           min = prices[i];
       if(prices[i] - min > max)
           max = prices[i] - min;
    }
    return max;
}