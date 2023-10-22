/*
LeetCode problem no.: 213

Problem Statement: You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3


Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 1000

Approach: The given approach employs dynamic programming to solve the problem of robbing houses arranged in a circular manner without triggering adjacent security systems.
The algorithm maintains two variables, prev (maximum amount robbed till the previous house) and prev2 (maximum amount robbed till the house before the previous one),
updating them iteratively while considering two scenarios at each house: robbing the current house or skipping it. To handle the circular arrangement, the algorithm runs twice,
once excluding the first house and once excluding the last house, and returns the maximum amount robbed from these two cases. This ensures an optimal solution by considering all
possible combinations of robbing houses along the street without alerting the police.
*/

// Following is the code:
class Solution
{
public:
    int help(long long int index, vector<int> &nums)
    {
        long long int prev = nums[0];
        long long int prev2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            long long int take = nums[i];
            if (i > 1)
                take += prev2;

            long long int notTake = 0 + prev;

            long long int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int> &nums)
    {
        long long int n = nums.size();
        vector<int> temp1, temp2;

        if (n == 1)
        {
            return nums[0];
        }

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        return max(help(n, temp1), help(n, temp2));
    }
};