
/*
Problem: Koko Eating Bananas
Platform: LeetCode 875
Problem Statement:
Koko loves to eat bananas. There are n piles of bananas, and Koko has h hours to eat all the bananas.
Koko can choose an eating speed of k bananas per hour. In each hour, she chooses one pile and eats k bananas from it. 
If the pile has fewer than k bananas, she eats all the bananas in that pile and waits for the rest of the hour.
Return the minimum integer k such that Koko can eat all the bananas within h hours.

Approach: Binary Search on Answer
The minimum possible eating speed is 1 and the maximum possible speed is the largest pile.
For each possible speed mid, calculate the total hours required to finish all piles.
If the required hours are less than or equal to h, the speed is possible, so search for a smaller speed.
Otherwise, increase the speed.
Continue until low == high. This gives the minimum possible eating speed.
Time Complexity: O(n log m), where m is the maximum pile size
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int findmax(vector<int>& vec){
    int n=vec.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
    maxi=max(vec[i],maxi);
    }
    return maxi;
}
long long totalhrs(vector<int>& vec, int hrs){
    int m=vec.size();
    long long  totalhr=0;
    for(int i=0;i<m;i++){
        totalhr+=ceil((double)vec[i]/(double)hrs);
    }
    return totalhr;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalhours=totalhrs(piles,mid);
            if(totalhours<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};