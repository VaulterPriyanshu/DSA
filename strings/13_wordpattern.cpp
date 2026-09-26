/*
Problem: Word Pattern
Platform: LeetCode
Problem Statement:
Given a pattern and a string s, determine whether s follows
the same pattern. Each character in the pattern must map to
exactly one word, and each word must map to exactly one
character.
Approach:
- Split the string s into individual words using stringstream.
- Check whether the number of words matches the length of
  the pattern.
- Use two maps to maintain mappings between characters and
  words in both directions.
- Traverse the pattern and words simultaneously.
- If an existing mapping is inconsistent, return false.
- If all mappings are valid, return true.
Time Complexity: O(n + m)
where n = length of the pattern
      m = length of the string

Space Complexity: O(n + m)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string>words;
        while(ss>>word){
            words.push_back(word);
        }
        if(pattern.length()!=words.size()){
            return false;
        }
       map<char,string>mpp;
       map<string,char>mp;
       for(int i=0;i<pattern.size();i++){
        char c1=pattern[i];
        string c2=words[i];
        if(mpp.find(c1)!=mpp.end()){
            if(mpp[c1]!=c2){
                return false;
            }
        }else if(mp.find(c2)!=mp.end()){
            if(mp[c2]!=c1){
                return false;
            }
        }
        else{
            mpp[c1]=c2;
            mp[c2]=c1;
        }
       }
      return true;
    }
};