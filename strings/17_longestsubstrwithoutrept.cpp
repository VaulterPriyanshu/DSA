/*
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode
Problem Statement:
Given a string s, find the length of the longest substring
without repeating characters.
Approach:
- Use a sliding window with two pointers, left and right.
- Maintain a frequency array/map to keep track of characters
  present in the current window.
- Move the right pointer and add each character to the window.
- If a character is repeated, move the left pointer forward
  until the duplicate character is removed.
- Keep updating the maximum length of the current window.
- Return the maximum length found.
Time Complexity: O(n)
where n = length of the string
Space Complexity: O(k)
where k = number of distinct characters
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        maxlen=max(maxlen,r-l);
        }
        return maxlen;
    }
};