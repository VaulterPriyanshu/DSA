/*
Problem: Binary Subarrays With Sum
Platform: LeetCode

Problem Statement:
Given a binary array nums and an integer goal, return the
number of non-empty subarrays whose sum is equal to goal.

Approach:
- Use the sliding window technique to count subarrays
  whose sum is at most goal.
- Maintain two pointers, left and right, and a variable
  to store the sum of the current window.
- Expand the window by adding nums[right] to the sum.
- While the sum exceeds goal, shrink the window by
  subtracting nums[left] and incrementing left.
- For each valid window, add (right - left + 1) to the
  count because all subarrays ending at right have a sum
  at most goal.
- Calculate the final answer using:
  countAtMost(goal) - countAtMost(goal - 1).
- If goal is negative, countAtMost(goal) should return 0.

Time Complexity: O(n)
where n = length of the nums array

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int atmostgoal(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
         int l=0;
        int count=0;
        int sum=0;
        for(int r=0;r<nums.size();r++){
            sum=sum+nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            count=count+(r-l+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=atmostgoal(nums,goal)-atmostgoal(nums,goal-1);
        return ans;
    }
};