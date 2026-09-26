
#include <bits/stdc++.h>
using namespace std;
/*
Problem: Group Anagrams
Platform: LeetCode
Problem Statement:
Given an array of strings, group the anagrams together.
Anagrams are strings that contain the same characters
with the same frequencies but may appear in a different
order.
Approach:
- Create a map to store groups of anagrams.
- Traverse each string in the given array.
- Sort the characters of each string to create a common key.
- Use the sorted string as a key in the map.
- Add the original string to the group corresponding to
  its sorted key.
- Return all the grouped anagrams.
Time Complexity: O(n * k log k)
where n = number of strings
      k = maximum length of a string
Space Complexity: O(n * k)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(string word:strs){
            string key=word;
            sort(key.begin(),key.end());
            mpp[key].push_back(word);
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};