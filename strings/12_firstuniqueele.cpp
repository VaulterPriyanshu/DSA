/*
Problem: First Unique Character in a String
Platform: LeetCode
Problem Statement:
Given a string s, find the index of the first character
that appears exactly once in the string. If no unique
character exists, return -1.
Approach:
- Create a frequency array to count the occurrences of
  each character in the string.
- Traverse the string again from left to right.
- Check the frequency of each character.
- The first character with frequency equal to 1 is the
  first unique character.
- Return its index. If no such character exists, return -1.
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        for(char ch:s){
            freq[ch-'a']++;
        }
        int i=0;
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};