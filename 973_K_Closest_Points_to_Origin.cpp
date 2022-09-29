#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
bool compare(vector<int>&a, vector<int>&b)
{
    int n1 = pow(a[0],2) + pow(a[1],2);
    int n2 = pow(b[0],2) + pow(b[1],2);
    return n1 < n2;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>>ans;
        sort(points.begin(), points.end(),compare);
        points.resize(k);
        return points;
    }
};