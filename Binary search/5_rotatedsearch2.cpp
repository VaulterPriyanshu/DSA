/*
Problem: Search in Rotated Sorted Array II
Platform: LeetCode 81
Problem Statement:
Given an integer array sorted in ascending order that may contain duplicate elements and is rotated at an unknown pivot,
determine whether a given target exists in the array.
Return true if the target is found, otherwise return false.
Approach: Modified Binary Search
At every step, check which half of the array is sorted.
If nums[low] == nums[mid] == nums[high],
 duplicates make it impossible to determine which half is sorted, so move low++ and high--.
If the lower half is sorted, check whether the target lies within its range. 
If yes, search the lower half; otherwise, search the upper half.
If the upper half is sorted, check whether the target lies within its range. 
If yes, search the upper half; otherwise, search the lower half.
Time Complexity: O(log n) average, O(n) worst case due to duplicates
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return true;
            if(nums[mid]==nums[low]&&nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target&&target<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if(nums[mid]<=target&&target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
     return false;
    }
};
