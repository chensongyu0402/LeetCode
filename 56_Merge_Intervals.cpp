#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ret;
vector<vector<int>> intervals;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
    vector<int> prev(2);
    prev = intervals[0];
    for(int i = 1; i < intervals.size(); i++) {
        if(prev[1] >= intervals[i][0]) {
            prev[1] = ((prev[1] < intervals[i][1]) ? intervals[i][1] : prev[1]);
        }
        else {
            ret.push_back(prev);
            prev = intervals[i];    
        }
    }
    ret.push_back(prev);
    return ret;
}

int main()
{
    int intervalsSize;
    int j;
    printf("intervals_size:");
    scanf("%d",&intervalsSize);
    vector<int> points(2);
    for(int i = 0; i < intervalsSize; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        points[0] = a;
        points[1] = b;
        intervals.push_back(points);
    }
    ret = merge(intervals);
    printf("[");
    for(j = 0; j < ret.size() - 1; j++) {
        printf("[%d,%d],",ret[j][0],ret[j][1]);
    }
    printf("[%d,%d]]\n",ret[j][0],ret[j][1]);
    return 0;
}