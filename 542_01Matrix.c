#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int,int>>bfs;
        vector<vector<int>>ans(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    bfs.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!bfs.empty()) {
            pair<int,int> now = bfs.front();
            bfs.pop();
            
            for(auto DIR : dir) {
                int next_x = now.first + DIR[0];
                int next_y = now.second + DIR[1];
                
                if(next_x < 0 || next_y >= n|| next_x >=m || next_y < 0
                   || ans[next_x][next_y] <= ans[now.first][now.second] + 1) continue;
                
                bfs.push({next_x,next_y});
                ans[next_x][next_y] = ans[now.first][now.second] + 1;
            }
        }
        
        return ans;
    }
};