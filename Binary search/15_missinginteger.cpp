/*
Problem: Kth Missing Positive Number
Platform: LeetCode 1539
Problem Statement:
Given a sorted array arr of positive integers and an integer k, return the kth positive integer that is missing from the array.
Approach: Binary Search
For every index mid, calculate how many positive numbers are missing before arr[mid].
The number of missing elements before arr[mid] is:
arr[mid] - (mid + 1)
If the number of missing elements is less than k, move low to mid + 1 to search for more missing numbers.
Otherwise, move high to mid - 1.
After the binary search, the kth missing positive number is low + k.
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k)low=mid+1;
            else high=mid-1;
        }
    return (k+high+1);
    }
};