/*
Problem: Longest Common Prefix
Platform: LeetCode
Problem Statement:
Given an array of strings, find the longest common prefix
shared by all the strings. If there is no common prefix,
return an empty string.
Approach:
- Take the first string as the initial prefix.
- Compare the prefix with every other string.
- If the current string does not match the prefix,
  remove characters from the end of the prefix.
- Continue until the prefix matches or becomes empty.
- The remaining prefix is the longest common prefix.
Time Complexity: O(n * m)
where n = number of strings
      m = length of the shortest string
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        sort(strs.begin(),strs.end());
        string first=strs.front();
        string last=strs.back();
        int i=0;
        while(i<first.size()&&i<last.size()&&first[i]==last[i]){
            i++;
        }
        return(first.substr(0,i));
    }
};