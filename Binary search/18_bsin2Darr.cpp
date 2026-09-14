/*
Problem: Search a 2D Matrix
Platform: LeetCode 74
Problem Statement:
Given an m x n integer matrix where each row is sorted in ascending order and the first integer of each row is greater than the last integer of the previous row, return true if the target exists in the matrix. Otherwise, return false.
Approach: Binary Search
Treat the 2D matrix as a single sorted 1D array and apply Binary Search.
For an index mid, convert it into row and column using mid / n and mid % n.
If matrix[mid / n][mid % n] == target, return true.
If the value is less than target, search in the right half; otherwise, search in the left half.
If the target is not found, return false.
Time Complexity: O(log(m * n))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int high=(m*n-1);
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
};