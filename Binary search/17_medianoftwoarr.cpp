/*
Problem: Median of Two Sorted Arrays
Platform: LeetCode 4
Problem Statement:
Given two sorted arrays nums1 and nums2, return the median of the two sorted arrays.
The overall run time complexity should be O(log(m + n)).
Approach: Binary Search
Apply Binary Search on the smaller array to find the correct partition between the two arrays.
For each partition, ensure that all elements on the left side are less than or equal to all elements on the right side.
Once the correct partition is found, calculate the median based on the maximum element of the left half and the minimum element of the right half.
If the total number of elements is odd, the median is the maximum element of the left half. If even, the median is the average of the maximum left element and minimum right element.
Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays( nums2, nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0;
        int high=n1;
        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=(n1+n2+1)/2-cut1;
         double l1;
      if (cut1 == 0) {
            l1 = INT_MIN;
            } else {
              l1 = nums1[cut1 - 1];
                 }
    double l2;
    if(cut2==0){
        l2=INT_MIN;
    }else{
        l2=nums2[cut2-1];
    }
     
      double r1;
    if(cut1==n1){
        r1=INT_MAX;
    }else{
        r1=nums1[cut1];
    }
    double r2;
    if(cut2==n2){
        r2=INT_MAX;
    }else{
        r2=nums2[cut2];
    }
    if(l1<=r2&&l2<=r1){
        if((n1+n2)%2==0){
            return (max(l1,l2)+min(r1,r2))/2.0;
        }else{
            return max(l1,l2);
        }
    }else if(l1>r2){
        high=cut1-1;
    }else{
        low=cut1+1;
    }
        }
        return 0.0;
    }
};