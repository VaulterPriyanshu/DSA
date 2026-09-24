/*
Problem: Ransom Note
Platform: LeetCode
Problem Statement:
Given two strings ransomNote and magazine, determine whether
ransomNote can be constructed using the characters from
magazine. Each character from magazine can be used only once.
Approach:
- Create a frequency array to count the characters available
  in magazine.
- Traverse ransomNote and decrease the frequency of each
  required character.
- If the frequency of any character becomes zero before it
  is used, return false.
- If all characters of ransomNote can be formed, return true.
Time Complexity: O(n + m)
where n = length of ransomNote
      m = length of magazine

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]={0};
        for(char ch:magazine){
            freq[ch-'a']++;
        }
        for(char ch:ransomNote){
            freq[ch-'a']--;
        }
        for(int i=0;i<sizeof(freq)/sizeof(freq[0]);i++){
            if(freq[i]<0){
                return false;
            }
        }
        return true;
    }
};
