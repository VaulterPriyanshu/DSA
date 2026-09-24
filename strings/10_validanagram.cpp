/*
Problem: Valid Anagram
Platform: LeetCode
Problem Statement:
Given two strings s and t, determine whether t is an anagram
of s. An anagram is a word or phrase formed by rearranging
the letters of another word or phrase using all the original
characters exactly once.
Approach:
- If the lengths of both strings are different, return false.
- Create a frequency array to count the occurrences of each
  character in string s.
- Traverse string t and decrease the frequency of each
  character.
- If any character's frequency becomes negative, return false.
- If all frequencies are balanced, the strings are anagrams.
Time Complexity: O(n)
where n = length of the string
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int freq[26]={0};
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(char ch:t){
            freq[ch-'a']--;
        }
        for(int i=0;i<sizeof(freq) / sizeof(freq[0]);i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
    }
};