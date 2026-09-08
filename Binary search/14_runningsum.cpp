/*
Problem: Running Sum of 1d Array
Platform: LeetCode 1480
Problem Statement:
Given an array nums, define the running sum of nums as runningSum[i] = sum(nums[0]...nums[i]).
Return the running sum of nums.
Approach: Prefix Sum
Start from the second element and add the previous element's running sum to the current element.
For each index i, update nums[i] = nums[i] + nums[i - 1].
The modified array represents the running sum of the original array.
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
    }
};