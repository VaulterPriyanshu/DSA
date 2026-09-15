/*
Problem: Find a Peak Element II
Platform: LeetCode 1901
Problem Statement:
A peak element in a 2D grid is an element that is strictly greater than its adjacent elements. Given an m x n matrix, find any peak element and return its position as [row, column].
Approach: Binary Search on Columns
Apply Binary Search on the columns of the matrix.
For each mid column, find the row containing the maximum element in that column.
Compare this element with its left and right neighbors.
If it is greater than both neighbors, it is a peak element.
If the left neighbor is greater, search in the left half; otherwise, search in the right half.
Continue until a peak element is found.
Time Complexity: O(m log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int getmax(vector<vector<int>>& mat,int n,int mid){
    int maxi=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        if(mat[i][mid]>maxi){
            maxi=mat[i][mid];
            index=i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int  mid=low+(high-low)/2;
       int getpeak=getmax(mat,n,mid);
       int l=mid-1>=0?mat[getpeak][mid-1]:-1;
       int r=mid+1<m?mat[getpeak][mid+1]:-1;
       if(mat[getpeak][mid]>l&&mat[getpeak][mid]>r){
        return {getpeak,mid};
       }else if(mat[getpeak][mid]<l){
        high=mid-1;
       }else{
        low=mid+1;
       }
        }
        return {-1,-1};
    }
};