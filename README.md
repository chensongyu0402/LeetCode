# Leetcode
###### tags: `github_project`

## Source
- [Coding interview study plan](https://www.techinterviewhandbook.org/coding-interview-study-plan/)
## Array
### 3. Longest Substring Without Repeating Characters
- We use the table to remember the latest starting value of the char.
- Initializing table to -1 is to avoid the case where the starting value is 0.
- len is length of string.
- start is starting value of substring.
- max value  is lengthOfLongestSubstring, which we want to return.
- First, we use table to determine if the char is in the substring
  * Yes --> if：
    * update starting vlaue of substring.
      * if we don't want to update it to table[s[i]] + 1, the same thing must happen again soon.
    * update table value to the latest starting value of the char.
  * No  --> else:
    * we haven't seen this char.
    * update table value to the latest starting value of the char.
    * use i - start + 1 to calculate length of substring and find maximum value.
```c
int lengthOfLongestSubstring(char * s)
{
    int *table = (int*)malloc(127 * sizeof(int));
    for(int i = 0; i < 127; i++)
        table[i] = -1;
    int len = strlen(s);
    int start = 0, max = 0;
    for(int i = 0; i < len; i++) {
        if(table[s[i]] >= start) {
            start = table[s[i]] + 1;
            table[s[i]] = i;
        }
        else {
            table[s[i]] = i;
            if((i - start + 1) > max)
                max = i - start + 1;
        }
        
    }
    return max;
}
```
### 209. Minimum Size Subarray Sum
- min is minSubArrayLen
- start is starting value of the substring
- sum is total value of the substring
- target is baseline and we must greater or equal than it
- i is end of substring
- if sum < target, we will keep adding num to sum
- if sum >= target, we will first check to see if there is too much member num in the substring
  * too much: because we only need to be just greater or equal than target
  * Yes: we will remove num[start] and start++
- if i - start + 1 < min:
  * YES:  i - start + 1 is current minimal
```c
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int min = numsSize;
    int start = 0, sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if(sum >= target) {
            while((sum - nums[start]) >= target) {
                sum -= nums[start];
                start ++;
            }
            if(i - start + 1 < min)
                min = i - start + 1;
        }
    }
    if (sum < target)
        return 0;
    else
        return min;
    
}
```
### 647. Palindromic Substrings
- we use dynamic programming method to solve this problem
- count is the number of palindromic substrings 
- len is length of string
- dp array is table
  * dp[i][j] means that whether the index i to j of the string is a palindromic substrings.
    * YES-->1, NO-->0
- First, we initialize table
  * dp[i][i] must 1
  * and check to see whether dp[i - 1][i] is a palindromic substrings.
- Second, we can use this algorithm to solve it
  * start is starting value of substrings
  * end is end of substring
  * i is length of substring
  * dp[i][j] == 1 if dp[i + 1][j - 1] && s[i] == s[j]
- Third, we free memory
```c
int countSubstrings(char * s)
{
    int count = 0;
    int len = strlen(s);
    char **dp = malloc(sizeof(char *) * len);
    for(int i = 0; i < len; i++) {
        dp[i] = calloc(len,sizeof(char));
        dp[i][i] = 1;
        count++;
    }
    for(int i = 1; i < len; i++) {
        if(s[i - 1] == s[i]) {
            dp[i - 1][i] = 1;
            count ++;
        }
    }
    for(int i = 3; i <= len; i++) {
        int start = 0, end = start + i -1;
        while(end < len) {
            if(dp[start + 1][end - 1] && s[start] == s[end]) {
                dp[start][end] = 1;
                count ++;
            }
            start ++;
            end++;
        }
    }
    for (int i = 0; i < len; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return count;
}
```
### 739. Daily Temperatures
- [hackmd](https://hackmd.io/@kenjin/S1Eb1YTa4)
- vector 可以比較簡單，可以看 github
### 56. Merge Intervals
- [hackmd](https://hackmd.io/@kenjin/BJdXqbzGB)
- vector 可以比較簡單，可以看 github
- Intervals 的問題很常跟 sort 一起出現
### 435. Non-overlapping Intervals
- [hackmd](https://hackmd.io/@kenjin/0435_non-overlapping-intervals#C-Solution)
- Intervals 的問題很常跟 sort 一起出現
### 238. Product of Array Except Self
- [hackmd](https://hackmd.io/@kenjin/0238_product-of-array-except-self)
### 1. Two Sum
- qsort and bibary search
- [hackmd](https://hackmd.io/@brad84622/ByifDY_ZD)
### 152. Maximum Product Subarray
- [hackmd](https://hackmd.io/@kenjin/SyU2ViFPB)
### 33. Search in Rotated Sorted Array
- [hackmd](https://hackmd.io/@kenjin/rJwzA6gyB)
### 11. Container With Most Water
- [hackmd](https://hackmd.io/@Zero871015/BJbqwPKs4?type=view)
### 15. 3Sum
- [hackmd](https://hackmd.io/@kenjin/0015_3Sum)
## string
### 208. Implement Trie (Prefix Tree)
- [Tree - Trie](https://ithelp.ithome.com.tw/articles/10248152)
- [Trie from wikipedia](https://en.wikipedia.org/wiki/Trie)
### Suffix Tree
- [演算法知識 - Suffix Tree 後綴樹 (Using Ukkonen Algorithm)](https://theriseofdavid.github.io/2020/11/03/Explain_Algorithm/suffix-tree/)
- [Generalized Suffix Tree 1](https://www.geeksforgeeks.org/generalized-suffix-tree-1/)
### 49. Group Anagrams
- [hackmd](https://hackmd.io/@Zero871015/LeetCode-49)
- [C++ map用法总结（整理）](https://blog.csdn.net/sevenjoin/article/details/81943864)
- [C++ map end() 函数使用方法及示例](https://www.nhooo.com/cpp/cpp-map-end-function.html)
### 5. Longest Palindromic Substring
- [hackmd](https://hackmd.io/@YLowy/HyNJkLyVO)
### 516. Longest Palindromic Subsequence
- [hackmd](https://hackmd.io/@kenjin/BJ49BNvyL)
### 424. Longest Repeating Character Replacement
- [hackmd](https://hackmd.io/Vtj6bEAlSDKuRTuPWjTUpw)
### 438. Find All Anagrams in a String
- [hackmd](https://hackmd.io/@kenjin/BkO3caEGH)
## Dynamic programming
### 300. Longest Increasing Subsequence
- [hackmd](https://hackmd.io/@kenjin/H1U-RElR4)
### 416. Partition Equal Subset Sum
- [hackmd](https://hackmd.io/@kenjin/HkoDcRtPB)
### 139. Word Break
- [hackmd](https://hackmd.io/@kenjin/0139_Word-Break)
### 213. House Robber II
- [csdn](https://blog.csdn.net/shen_zhu/article/details/81904706)
### 91. Decode Ways
- [hackmd](https://hackmd.io/@kenjin/ry_F0UqxB)
### 62. Unique Paths
- [hackmd](https://hackmd.io/@kenjin/0062_unique-path)
### 55. Jump Game
- [hackmd](https://hackmd.io/@Zero871015/S1JFXHxaN?type=view)

## other
### 733. Flood Fill
- [hackmd](https://hackmd.io/@Zero871015/LeetCode-733)
### 141. Linked List Cycle
- [hackmd](https://hackmd.io/@Ji0m0/SJP448Oo4)
### 110. Balanced Binary Tree
- [GeeksforGeeks](https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/)
- [csdn](https://blog.csdn.net/ds19980228/article/details/82958272)

