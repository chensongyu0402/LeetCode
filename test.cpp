#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int *answer = malloc(sizeof(int) * temperaturesSize);
    vector<int>ans;
    ans[temperaturesSize];
    *returnSize = temperaturesSize;
    for(int i = 0; i < temperaturesSize; i++) {
        if(ans.empty() || temperatures[i] <= temperatures[ans.back()]) {
            ans.push_back(i);
        }
        else {
            int indx = ans.back();
            ans.pop_back();
            answer[i] = i - indx;
            i --;
        }
    }
    ans.clear();
    ans.shrink_to_fit();
    return answer;
}

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
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
};