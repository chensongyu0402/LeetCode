#include<iostream>
#include<string>

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxStart = 0;
        int maxlen = 1;
        bool table[1000][1000] = {false};
    
        for(int i = 0; i < n; i ++)
            table[i][i] = true;
    
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                maxStart = i;
                maxlen = 2;
            }
        }
    
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if(table[i + 1][j - 1] && s[i] == s[j]) {
                    table[i][j] = true;
                    maxStart = i;
                    maxlen = len;
                }
            }
        }
    
        return s.substr(maxStart,maxlen);
    }
};