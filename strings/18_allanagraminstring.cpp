/*
Problem: Find All Anagrams in a String
Platform: LeetCode

Problem Statement:
Given two strings s and p, find all the starting indices
of p's anagrams in s. An anagram is a string formed by
rearranging the characters of another string using the
same characters with the same frequencies.

Approach:
- Create a frequency array to store the character counts
  of string p.
- Use a sliding window of size equal to the length of p.
- Maintain the character frequencies of the current window
  in string s.
- Compare the frequency arrays of p and the current window.
- If both frequency arrays match, add the starting index
  of the window to the answer.
- Slide the window forward by removing the outgoing
  character and adding the incoming character.
- Return the list of starting indices.

Time Complexity: O(n + m)
where n = length of s
      m = length of p

Space Complexity: O(1)
assuming a fixed-size character set
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
          if(p.size() > s.size()) {
            return ans;
        }
        int freq[26]={0};
        for(char ch:p){
            freq[ch-'a']++;
        }
        int k=p.size();
        int freq2[26]={0};
        for(int i=0;i<k;i++){
            freq2[s[i]-'a']++;
        }
        bool same=true;
        for(int i=0;i<26;i++){
            if(freq[i]!=freq2[i]){
                same=false;
                break;
            }
        }
        if(same){
            ans.push_back(0);
        }
        for(int i=k;i<s.size();i++){
            freq2[s[i]-'a']++;
            freq2[s[i-k]-'a']--;
            bool same=true;
            for(int i=0;i<26;i++){
                if(freq[i]!=freq2[i]){
                    same=false;
                    break;
                }
            }
            if(same){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};