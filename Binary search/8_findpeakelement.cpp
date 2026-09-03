/*
Problem: Find Peak Element
Platform: LeetCode 162
Problem Statement:
A peak element is an element that is strictly greater than its neighboring elements.
Given an integer array nums, find a peak element and return its index.
You may imagine that nums[-1] = nums[n] = -∞.
The solution must run in O(log n) time.
Approach: Binary Search
Use Binary Search to find a peak element.
Compare nums[mid] with nums[mid + 1].
If nums[mid] > nums[mid + 1], a peak exists on the left side including mid, so set high = mid.
Otherwise, a peak exists on the right side, so set low = mid + 1.
Continue until low == high. This index represents a peak element.
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1]){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};