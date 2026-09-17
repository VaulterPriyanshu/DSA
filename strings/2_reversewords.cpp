/*
Problem: 151. Reverse Words in a String
Platform: LeetCode
Problem Statement:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters.
The words in s will be separated by at least one space.
Return a string of the words in reverse order, concatenated by a single space.
Approach:
Remove leading, trailing, and extra spaces, then reverse the order of the words.
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            string wrd="";
            while(i<n && s[i]!= ' '){
                wrd=wrd+s[i];
                i++;
            }
            reverse(wrd.begin(),wrd.end());
            if(wrd.length()>0){
                ans+=" "+wrd;
          }
        }
        return ans.substr(1);
    }
};