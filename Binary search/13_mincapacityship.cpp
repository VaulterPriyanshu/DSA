
/*
Problem: Capacity To Ship Packages Within D Days
Platform: LeetCode 1011
Problem Statement:
A conveyor belt has packages that must be shipped within D days.
The packages must be shipped in the same order as given in the array weights.
 Each day, the ship can carry packages up to its maximum weight capacity.
Return the least weight capacity of the ship that will result in all packages being shipped within D days.
Approach: Binary Search on Answer
The minimum possible capacity is the maximum package weight, 
and the maximum possible capacity is the sum of all package weights.
For each possible capacity mid, 
calculate the number of days required to ship all packages while maintaining their order.
If the required days are less than or equal to D,
 the capacity is possible, so search for a smaller capacity.
Otherwise, increase the capacity.
Continue until low == high. This gives the minimum ship capacity required.
Time Complexity: O(n log(sum(weights)))
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int  getsum(vector<int>& vec){
    int sum=0;
    for(int i=0;i<vec.size();i++){
        sum=sum+vec[i];
    }
    return sum;
}
int getdays(vector<int>& vec,int n){
    int count=1;
    int load=0;
    for(int i=0;i<vec.size();i++){
        if(load+vec[i]>n){
            count++;
            load=vec[i];
        }else{
            load=load+vec[i];
        }
    }
    return count;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=getsum(weights);
        int ans=0;
        while(low<=high){
            int mid= low+(high-low)/2;
             int result=getdays(weights,mid);
            if(result<=days){
            ans=mid;
            high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};