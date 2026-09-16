
/*
Problem: Reverse String
Platform: LeetCode 344
Problem Statement:
Write a function that reverses a string in-place.

Approach: Two Pointers
Use two pointers, one at the beginning and one at the end of the string.
Swap the characters at both pointers and move them towards the center.
Continue until the two pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0;
        int high=s.size()-1;
        while(st<high){
            swap(s[st],s[high]);
            st++;
            high--;
        }
        
    }
};