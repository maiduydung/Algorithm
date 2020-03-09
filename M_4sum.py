# https://leetcode.com/problems/4sum/

# Given an array nums of n integers and an integer target.
# there are elements a, b, c, and d in nums such that a + b + c + d = target? 
# Find all unique quadruplets in the array which gives the sum of target.

# The solution set must not contain duplicate quadruplets.

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        i = 0
        sorted_nums = sorted(nums)
        print(sorted_nums)
        for i in range(len(sorted_nums)):
            for j in range(i+1, len(sorted_nums)):
                left = j + 1
                right = len(sorted_nums)-1
                while(left < right):
                    if (sorted_nums[left] + sorted_nums[right] == sorted_nums[i] + sorted_nums[j]):
                        print(sorted_nums[i], " ", sorted_nums[j], " ", sorted_nums[left], " ", sorted_nums[right])
