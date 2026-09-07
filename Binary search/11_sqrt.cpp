/*
Problem: Sqrt(x)
Platform: LeetCode 69
Problem Statement:
Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
The returned integer should satisfy:
ans * ans <= x
You are not allowed to use any built-in exponent function or operator.
Approach: Binary Search
Use Binary Search in the range from 1 to x.
Calculate mid and check whether mid * mid is less than or equal to x.
If mid * mid <= x, mid can be a possible answer, so store it and search in the upper half for a larger valid value.
Otherwise, search in the lower half.
Continue until the search range is exhausted. The stored value is the integer square root of x.
Time Complexity: O(log x)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
     long long low=1;
     long long high=x;
     long long ans=0;
     while(low<=high){
        long long mid=low+(high-low)/2;
        if(mid*mid<=x){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
     }
     return ans;   
    }
};