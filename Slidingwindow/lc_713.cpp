/*
Problem: Subarray Product Less Than K
Platform: LeetCode

Problem Statement:
Given an array of positive integers nums and an integer k,
return the number of contiguous subarrays whose product is
strictly less than k.

Approach:
- Use the sliding window technique with two pointers, left
  and right.
- Maintain a variable to store the product of elements in
  the current window.
- Expand the window by multiplying the product by nums[right].
- While the product is greater than or equal to k, shrink
  the window by dividing the product by nums[left] and
  incrementing left.
- For each valid window, add (right - left + 1) to the count
  because all subarrays ending at right within this window
  have a product less than k.
- Return the total count.

Time Complexity: O(n)
where n = length of the nums array

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;long long p=1;
        int count=0;
        if(k <= 1) return 0;
        for(int r=0;r<nums.size();r++){
            p=p*nums[r];
            while(p>=k){
                p=p/nums[l];
                l++;
            }
            count=count+(r-l+1);
        }
        return count;
    }
};