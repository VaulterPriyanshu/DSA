/*
Problem: Isomorphic Strings
Platform: LeetCode
Problem Statement:
Given two strings s and t, determine whether they are
isomorphic. Two strings are isomorphic if the characters
in s can be replaced to obtain t while maintaining the
same character pattern.
Approach:
- Maintain a mapping from characters of s to characters of t.
- Also maintain a reverse mapping from t to s.
- For every character, check whether the existing mapping
  is consistent.
- If a character maps to different characters or two
  different characters map to the same character, return false.
- If all mappings are valid, return true.
Time Complexity: O(n)
where n = length of the string
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int n=s.length();
        map<char,char>m1,m2;
        for(int i=0;i<n;i++){
            if(m1.find(s[i])!=m1.end()){
                if(m1[s[i]]!=t[i]){
                    return false;
                }
            }else if(m2.find(t[i])!=m2.end()){
                if(m2[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                m1[s[i]]=t[i];
               m2[t[i]]=s[i];
            }
        }
        return true;
    }
};