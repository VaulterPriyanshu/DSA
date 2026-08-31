
/*Problem: Find First and Last Position of Element in Sorted Array
Platform: LeetCode 34
Problem Statement:
Given a sorted array of integers, find the starting and ending position of a given target value.
If the target is not present in the array, return [-1, -1].
Approach: Lower Bound + Upper Bound Binary Search
Use Lower Bound to find the first index where nums[i] >= target.
Use Upper Bound to find the first index where nums[i] > target. The last occurrence of the target is therefore upper_bound - 1.
If the target is not found, return [-1, -1].
Time Complexity: O(log n)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int lowerbound(vector<int>& arr, int x,int n){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int upperbound(vector<int>& arr, int x,int n){
    int low=0;
    int high=n-1;
    int ans2=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>x){
            ans2=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans2;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerbound(nums,target,n);
        if(lb==n||nums[lb]!=target)return{-1,-1};
        return{lb,upperbound(nums,target,n)-1};
    }
};