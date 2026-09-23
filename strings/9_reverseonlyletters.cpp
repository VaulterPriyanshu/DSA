/*
Problem: Reverse Only Letters
Platform: LeetCode
Problem Statement:
Given a string s, reverse the positions of only the
alphabetic characters while keeping all non-letter
characters in their original positions.
Approach:
- Use two pointers, one at the beginning and one at the end.
- Move the left pointer forward until it finds a letter.
- Move the right pointer backward until it finds a letter.
- Swap the two letters.
- Continue until the two pointers meet.
- Non-letter characters are skipped and remain in their
  original positions.
Time Complexity: O(n)
where n = length of the string
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(i<j&&!isalpha(s[i])){
               i++;  
        }else if(i<j&&!isalpha(s[j])){
            j--;
        }else if(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        }
        return s;
    }
};