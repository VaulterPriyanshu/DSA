/*
Problem: Search Insert Position
Platform: LeetCode 35
Problem Statement:
Given a sorted array of distinct integers and a target value, return the index if the target is found.
 If target is not present, return the index where it should be inserted to maintain the sorted order.
Approach: Lower Bound Binary Search
Find the first index where nums[i] >= target. This index is the required answer.
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;
          while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
          }
          return ans;
    }
};