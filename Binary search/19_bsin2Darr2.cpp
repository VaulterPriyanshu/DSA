/*
Problem: Search a 2D Matrix II
Platform: LeetCode 240
Problem Statement:
Write an efficient algorithm that searches for a target value in an m x n integer matrix. Each row is sorted in ascending order from left to right, and each column is sorted in ascending order from top to bottom.
Return true if the target exists in the matrix. Otherwise, return false.
Approach: Staircase Search
Start from the top-right corner of the matrix.
If matrix[row][col] == target, return true.
If matrix[row][col] > target, move left because all elements below are greater.
If matrix[row][col] < target, move down because all elements to the left are smaller.
Continue until the target is found or the search goes out of bounds.
Time Complexity: O(m + n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bs(const vector<int>& arr,int target){
        int high=arr.size()-1;
        int low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target)return true;
            else if(arr[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target&&target<=matrix[i][m-1]){
                if(bs(matrix[i],target)) return true;
            }
        }
        return false;
    }
};