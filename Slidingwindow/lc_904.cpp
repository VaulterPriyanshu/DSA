/*
Problem: Fruit Into Baskets
Platform: LeetCode

Problem Statement:
You are given an integer array fruits, where fruits[i]
represents the type of fruit on the i-th tree. You have
two baskets, and each basket can hold only one type of fruit.
You can start at any tree and collect exactly one fruit
from each tree while moving to the right. Return the
maximum number of fruits you can collect.

Approach:
- Use the sliding window technique with two pointers,
  left and right.
- Maintain a frequency map to count the types of fruits
  in the current window.
- Expand the window by moving the right pointer and
  adding each fruit to the map.
- If the window contains more than two distinct fruit
  types, shrink it by moving the left pointer and updating
  the frequency map.
- Remove a fruit type from the map when its frequency
  becomes zero.
- Update the maximum window length at each step.
- Return the maximum number of fruits collected.

Time Complexity: O(n)
where n = length of the fruits array

Space Complexity: O(1)
because the window contains at most two distinct fruit types
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       unordered_map<int,int>mpp;
       int l=0,ans=0;
       for(int r=0;r<fruits.size();r++){
        mpp[fruits[r]]++;
       if(mpp.size()>2){
        mpp[fruits[l]]--;
        if(mpp[fruits[l]]==0){
            mpp.erase(fruits[l]);
        }
        l++;
       }
       ans=max(ans,r-l+1);
       }
       return ans;
    }
};