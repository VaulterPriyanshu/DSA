/*
Problem: Binary Search
Platform: LeetCode
Problem Statement:
Given a sorted array of integers, find the index of the target element. If target is not present,return -1
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end=nums.size()-1;
        int st=0;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                st=mid+1;
            }else{
                end=mid-1;
            }
     }
     return -1;
    }
};