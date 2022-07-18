#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> temperatures;
vector<int>ans;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    vector<int>answer(temperatures.size());
    for(int i = 0; i < temperatures.size(); i++) {
        if(ans.empty() || temperatures[i] <= temperatures[ans.back()]) {
            ans.push_back(i);
        }
        else {
            int indx = ans.back();
            ans.pop_back();
            answer[indx] = i - indx;
            i --;
        }
    }
    ans.clear();
    ans.shrink_to_fit();
    return answer;  
}

int main()
{
    int temperaturesSize;
    printf("temperaturesSize:");
    scanf("%d",&temperaturesSize);
    for(int i = 0; i < temperaturesSize; i++) {
        int temp;
        scanf("%d",&temp);
        temperatures.push_back(temp);
    }
    ans = dailyTemperatures(temperatures);
    printf("Output:");
    for(int j = 0; j < temperaturesSize; j++)
        printf("%d ",ans[j]);
    printf("\n");
    return 0;
}