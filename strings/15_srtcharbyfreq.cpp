/*
Problem: Sort Characters By Frequency
Platform: LeetCode
Problem Statement:
Given a string s, sort it in decreasing order based on
the frequency of each character. The frequency of a
character is the number of times it appears in the string.
Approach:
- Use a frequency map to count the occurrences of each
  character.
- Store each character along with its frequency in a vector.
- Sort the vector in decreasing order of frequency.
- Traverse the sorted vector and add each character to
  the answer according to its frequency.
- Return the resulting string.
Time Complexity: O(n + k log k)
where n = length of the string
      k = number of distinct characters

Space Complexity: O(n + k)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        map<char,int>freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        vector<pair<char,int>> v;
        for(auto it:freq){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        string ans;
     for(auto p : v) {
    ans += string(p.second, p.first);
       }
    return ans;
    }
};