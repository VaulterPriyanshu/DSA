/*
Problem: Find the Smallest Divisor Given a Threshold
Platform: LeetCode 1283
Problem Statement:
Given an array of positive integers nums and an integer threshold,
 choose a positive integer divisor such that the sum of the division results is less than or equal to the threshold.
For each number, the division result is rounded up to the nearest integer.
Return the smallest possible divisor that satisfies the condition.
Approach: Binary Search on Answer
The minimum possible divisor is 1 and the maximum possible divisor is the maximum element in nums.
For each possible divisor mid, calculate the sum of ceil(nums[i] / mid) for all elements.
If the sum is less than or equal to threshold, mid is a possible answer, so search for a smaller divisor.
Otherwise, increase the divisor.
Continue until low == high. This gives the smallest valid divisor.
Time Complexity: O(n log m), where m is the maximum element in nums
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int divisor(vector<int>& vec,int n){
        int sum=0;
        for(int i=0;i<vec.size();i++){
        sum=sum+ceil((double)vec[i]/n);
        }
        return sum;
    }
    int getmax(vector<int>& vec){
        int maxi=INT_MAX;
        for(int i=0;i<vec.size();i++){
            maxi=max(vec[i],maxi);
        }
        return maxi;

    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=getmax(nums);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int result=divisor(nums,mid);
            if(result<=threshold){
             ans=mid;
             high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};