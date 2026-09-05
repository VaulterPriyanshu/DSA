/*
Problem: Minimum Number of Days to Make m Bouquets
Platform: LeetCode 1482
Problem Statement:
Given an integer array bloomDay where bloomDay[i] represents the day the ith flower will bloom.
To make one bouquet, k adjacent flowers are required. A flower can be used in only one bouquet.
Return the minimum number of days needed to make m bouquets. If it is impossible to make m bouquets, return -1.
Approach: Binary Search on Answer
The minimum possible day is the minimum value in bloomDay and the maximum possible day is the maximum value in bloomDay.
For each possible day mid, count how many bouquets can be made using flowers that have bloomed by that day.
If the number of bouquets is greater than or equal to m, the answer is possible, so search for a smaller number of days.
Otherwise, increase the number of days.
Continue until low == high. This gives the minimum number of days required.
Time Complexity: O(n log(max(bloomDay)))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     int findmax(vector<int>& vec){
        int maxi=INT_MIN;
        for(int i=0;i<vec.size();i++){
            maxi=max(vec[i],maxi);
        }
        return maxi;
     }
     int findmin(vector<int>& vec){
        int mini=INT_MAX;
        for(int i=0;i<vec.size();i++){
            mini=min(vec[i],mini);
        }
        return mini;
     }
     int flower(vector<int>& vec,int k1,int mid){
        int count=0;
           int noflower=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]<=mid){
                count=count+1;
            if(count==k1){
                noflower=noflower+1;
                count=0;
            }
                
            }else{
              count=0;
            }
            
        }
    
       return noflower;
     }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans;
        int low=findmin(bloomDay);
        int high=findmax(bloomDay);
        if((long long)m*k >bloomDay.size()){
            return -1;
            
        }
        else{
        while(low<=high){
           long int mid=low+(high-low)/2;
           long int fl=flower(bloomDay,k,mid);
            if(fl>=m){
                ans=mid;
               high=mid-1;
            }else{
                low=mid+1;
            }
        }
    }
    return ans;
    }
};