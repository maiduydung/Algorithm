# https://leetcode.com/problems/subarray-sum-equals-k/submissions/
# Given an array of integers and an integer k, 
# you need to find the total number of continuous subarrays whose sum equals to k.

# Example 1:
# Input:nums = [1,2,1,1,1], k = 3
# Output: 3 
# [1,2] [2,1] [1,1,1]

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sub_arr_cnt = 0
        dict_set = {0:1}
        sum = 0
        for i in range(len(nums)):
            sum = sum + nums[i]
            if (sum - k) in dict_set:
                sub_arr_cnt += dict_set[sum - k]
            if sum not in dict_set:
                dict_set[sum] = 1
            else:
                dict_set[sum] += 1
        return sub_arr_cnt