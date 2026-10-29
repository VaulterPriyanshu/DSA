/*
Problem: Count Number of Nice Subarrays
Platform: LeetCode

Problem Statement:
Given an array of integers nums and an integer k, return
the number of nice subarrays. A nice subarray is a
contiguous subarray that contains exactly k odd numbers.

Approach:
- Use the sliding window technique to count subarrays
  containing at most k odd numbers.
- Maintain two pointers, left and right, and a variable
  to count the odd numbers in the current window.
- Expand the window by moving the right pointer.
- If nums[right] is odd, increment the odd count.
- While the number of odd elements exceeds k, shrink
  the window by moving the left pointer.
- For each valid window, add (right - left + 1) to the
  count of subarrays containing at most k odd numbers.
- Calculate the final answer using:
  atMost(k) - atMost(k - 1).
- If k is negative, atMost(k) should return 0.

Time Complexity: O(n)
where n = length of the nums array

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int getsub(vector<int>& nums,int k){
    int l=0;
    int count=0;
    int ans=0;
    for(int r=0;r<nums.size();r++){
        if(nums[r]%2!=0){
            count++;
        }
        while(count>k){
            if(nums[l]%2!=0){
                count--;
            }
            l++;
        }
        ans=ans+(r-l+1);
    }
    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res=getsub(nums,k)-getsub(nums,k-1);
        return res;
    }
};