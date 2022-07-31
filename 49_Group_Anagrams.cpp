#include <iostrem>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sort_str(strs);
        map<string, vector<string>> map_ans;
        vector<vector<string>> ans;
        
        for(int i = 0; i < strs.size(); i++)
            sort(sort_str[i].begin(), sort_str[i].end());
        for(int i = 0; i < strs.size(); i++) {
            if(map_ans.find(sort_str[i]) == map_ans.end())
                map_ans[sort_str[i]] = vector<string>();
            map_ans[sort_str[i]].push_back(strs[i]);
        }
        for(auto it : map_ans)
            ans.push_back(it.second);
        return ans;
    }
};