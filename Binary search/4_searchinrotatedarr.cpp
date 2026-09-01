/*
Problem: Search in Rotated Sorted Array
Platform: LeetCode 33
Problem Statement:
Given an array of distinct integers sorted in ascending order and rotated at an unknown pivot, return the index of the given target.
If the target is not present in the array, return -1.
Approach: Modified Binary Search
At every step, check which half of the array is sorted.
If the left half is sorted, check whether the target lies within the range of the left half. 
If yes, search there; otherwise, search in the right half.
If the right half is sorted, check whether the target lies within its range.
If yes, search there; otherwise, search in the left half.
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high =nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return mid;
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
        return -1;
    }
};