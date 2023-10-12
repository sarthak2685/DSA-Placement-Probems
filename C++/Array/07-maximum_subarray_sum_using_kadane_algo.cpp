/*https://leetcode.com/problems/maximum-subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
For array [-2, 1, -3, 4, -1, 2, 1, -5, 4] the maximum contiguous subarray sum is 6 [4, -1, 2, 1]

More examples :

[-1, 1]  => Max Contiguous Subarray sum is 1
[-1, 1, 2, -1, 2]  => Max Contiguous Subarray sum is 4 [1, 2, -1, 2]
This is a beautiful question 😲
We can use the Kadane's algorithm to find the maximum contiguous subarray sum in just one iteration through the input array.
*/
#include<bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize current and total sum
        int currentSum =nums[0], totalSum = nums[0];
        //Iterate through the array
        for(int i=1; i<nums.size(); i++) {
            
            //Current max sum is either the current element OR current element + Previous Maximum subarray)
            currentSum = max(nums[i], currentSum+nums[i]); 
            
            //If the current maximum array sum is greater than the global total. Update it
            totalSum = max(totalSum, currentSum);
    }
        return totalSum;
    }
};
/*
Runtime Complexity : O(n)
Space Complexity   : O(1)
*/
