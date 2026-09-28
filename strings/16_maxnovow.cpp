/*
Problem: Maximum Number of Vowels in a Substring of Given Length
Platform: LeetCode
Problem Statement:
Given a string s and an integer k, find the maximum number
of vowels present in any substring of length k.
Approach:
- Use a sliding window of size k.
- First, count the number of vowels in the first k characters.
- Store this count as the current maximum.
- Move the window one character at a time.
- If the new character entering the window is a vowel,
  increase the count.
- If the character leaving the window is a vowel,
  decrease the count.
- Update the maximum count after each window.
- Return the maximum number of vowels found.
Time Complexity: O(n)
where n = length of the string
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isvowel(char c){
    
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        return true;
    }
    return false;
  }
    int maxVowels(string s, int k) {
       int l=0;
       int r=k-1;
       int count=0;
       int ans;
       for(int i=0;i<k;i++){
        if(isvowel(s[i])){
            count++;
        }
       }
       ans=count;
       while(r<s.size()-1){
          if(isvowel(s[l])){
            count--;
          }
          r++;
          l++;
          if(isvowel(s[r])){
            count++;
          }
          ans=max(ans,count);
       } 
       return ans;
    }
};