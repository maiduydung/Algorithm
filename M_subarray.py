# https://leetcode.com/problems/subarray-sum-equals-k/submissions/
# Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

# Example 1:
# Input:nums = [1,1,1], k = 2
# Output: 2

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        first = 0
        second = 0
        temp = 0
        result = 0
        for i in range(len(nums)):
            temp = temp + nums[i]
            first = first + 1
            if(temp == k):
                result = result + 1