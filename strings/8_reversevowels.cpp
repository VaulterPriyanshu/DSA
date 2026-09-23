/*
Problem: Reverse Vowels of a String
Platform: LeetCode
Problem Statement:
Given a string s, reverse only the vowels in the string.
The positions of all consonants and other characters must
remain unchanged.

Approach:
- Use two pointers, one at the beginning and one at the end.
- Move the left pointer until it finds a vowel.
- Move the right pointer until it finds a vowel.
- Swap the two vowels.
- Continue moving both pointers towards the center.
- Return the modified string.
Time Complexity: O(n)
where n = length of the string
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isvowel( char ch){
   char c=tolower(ch);
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        return true;
    }
    return false;
  }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(i<j&&!isvowel(s[i])){
                i++;
            }
             else if(i<j&&!isvowel(s[j])){
                j--;
            }
            else if(i<j){
                swap(s[i],s[j]);
                 i++;
                 j--;
            }
        }
        return s;
    }
};