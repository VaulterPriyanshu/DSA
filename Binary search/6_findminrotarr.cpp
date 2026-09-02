/*
# LeetCode 153 - Find Minimum in Rotated Sorted Array
## Problem Statement
Given a sorted array of unique integers that has been rotated an unknown number of times, return the minimum element of the array.
You must write an algorithm that runs in **O(log n)** time.
## Approach
* Use binary search with two pointers: `low` and `high`.
* Calculate the middle index:
  `mid = low + (high - low) / 2`
* If `nums[mid] > nums[high]`, the minimum element lies in the right half, so update:
  `low = mid + 1`
* Otherwise, the minimum element lies in the left half including `mid`, so update:
  `high = mid`
* Continue until `low == high`.
* The minimum element is `nums[low]`.
## Complexity
* **Time Complexity:** O(log n)
* **Space Complexity:** O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& arr) {
        int high=arr.size()-1;
        int low=0;
        while(low<high){
            int mid=low+(low+high)/2;
            if(arr[mid]>arr[high]){
                low=mid+1;
            }else{
             high=mid;
            }
        }
        return low;
    }
};