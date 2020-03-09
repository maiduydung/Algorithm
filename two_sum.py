# leetcode.com/problems/two-sum
# Given nums = [2, 7, 11, 15], target = 9,

# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(nums):
            if nums[i] in d:
                return[i ,d[nums[i]]]
            else:
                d[target - nums[i]] = i