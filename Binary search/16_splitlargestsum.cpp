/*
Problem: Split Array Largest Sum
Platform: LeetCode 410
Problem Statement:
Given an integer array nums and an integer k, split the array into k non-empty contiguous subarrays. Minimize the largest sum among these subarrays.
Return the minimized largest sum.
Approach: Binary Search on Answer
The minimum possible answer is the maximum element in nums, and the maximum possible answer is the sum of all elements.
For each possible maximum sum mid, count how many subarrays are required such that the sum of each subarray does not exceed mid.
If the required number of subarrays is less than or equal to k, mid is possible, so search for a smaller value.
Otherwise, increase the value of mid.
Continue until low == high. This gives the minimum possible largest subarray sum.
Time Complexity: O(n log(sum(nums)))
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int getsplit(vector<int>& vec,int n){
    int arr=1;
    int sum=0;
    for(int i=0;i<vec.size();i++){
        if(sum+vec[i]<=n){
            sum=sum+vec[i];
        }else{
            arr++;
            sum=vec[i];
        }
    }
    return arr;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int countarr=getsplit(nums,mid);
            if(countarr>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};