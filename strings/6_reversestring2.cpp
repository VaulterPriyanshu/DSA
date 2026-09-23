/*
Problem: Reverse String II
Platform: LeetCode
Problem Statement:
Given a string s and an integer k, reverse the first k
characters for every 2k characters counting from the start
of the string. If fewer than k characters remain, reverse
all of them. If between k and 2k characters remain, reverse
only the first k characters.
Approach:
- Traverse the string in blocks of 2k characters.
- For each block, reverse the first k characters.
- If fewer than k characters remain, reverse all remaining
  characters.
- Continue until the entire string is processed.
Time Complexity: O(n)
where n = length of the string
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        for(int i=0;i<n;i=i+2*k){
            int st=i;
            int j=min(i+k,n)-1;
            while(st<j){
                swap(s[st],s[j]);
                st++;
                j--;
            }
        }
        return s;
    }
};