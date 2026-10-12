/*
Problem: Longest Palindromic Substring
Platform: LeetCode

Problem Statement:
Given a string s, return the longest palindromic substring
in s. A palindrome is a string that reads the same forward
and backward.

Approach:
- Traverse each character of the string as a possible
  center of a palindrome.
- Expand around the center for both odd-length and
  even-length palindromes.
- Compare the length of each palindrome with the current
  maximum length.
- Update the starting index and maximum length whenever
  a longer palindrome is found.
- Return the longest palindromic substring.

Time Complexity: O(n^2)
where n = length of the string

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int expand(string s,int l,int r){
    while(l>=0&&r<s.size()&&s[l]==s[r]){
        r++;
        l--;
    }
    return r-l-1;
}
    string longestPalindrome(string s) {
        if(s.size()==0)return "";
        int st=0;
        int maxlen=1;
        for(int i=0;i<s.size();i++){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int len=max(len1,len2);
            if(len>maxlen){
                maxlen=len;
                st=i-(len-1)/2;
            }
        }
        return s.substr(st,maxlen);
    }
};