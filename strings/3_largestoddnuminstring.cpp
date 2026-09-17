/*
Problem: 1903. Largest Odd Number in String
Platform: LeetCode
Problem Statement:
You are given a string num representing a large integer.
Return the largest-valued odd integer (as a string) that is a non-empty substring of num.
If no odd integer exists, return an empty string.
Approach:
Traverse the string from right to left and find the first odd digit.
The substring from the beginning of num up to that digit forms the largest odd number.
If no odd digit is found, return an empty string.
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        string ans="";
        string result="";
        int count=0;
        if(num[n-1]%2!=0){
            return num;
        }else{
            for(int i=n-1;i>=0;i--){
                if(num[i]%2!=0){
                    return num.substr(0,i+1);
                }      
                 else{
                    count++;
                 }
            }
            if(count==n){
                return "";
            }
        }
   return "";
    }
};