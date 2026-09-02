// LeetCode 540 - Single Element in a Sorted Array
// Problem Statement:
// You are given a sorted array consisting of integers where every element
// appears exactly twice, except for one element which appears exactly once.
// Return the element that appears only once.
// You must solve the problem in O(log n) time and O(1) extra space.
// Approach:
// - Use binary search with two pointers: low and high.
// - Calculate the middle index:
//   mid = low + (high - low) / 2
// - Make sure mid is even so that pairs can be compared correctly.
// - If nums[mid] == nums[mid + 1], the single element lies in the right half,
//   so update low = mid + 2.
// - Otherwise, the single element lies in the left half including mid,
//   so update high = mid.
// - Continue until low == high.
// - The single element is nums[low].
// Complexity:
// Time Complexity: O(log n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
       if(n==1)return nums[0];
       if(nums[0]!=nums[1])return nums[0];
       if(nums[n-1]!=nums[n-2])return nums[n-1];
       int low=1;
       int high=n-2;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
            return nums[mid];
        }
        if(mid%2!=0&&nums[mid]==nums[mid-1]||mid%2==0&&nums[mid]==nums[mid+1]){
            low=mid+1;
        }else {
            high=mid-1;
        }
       }
       return -1;
    }
};