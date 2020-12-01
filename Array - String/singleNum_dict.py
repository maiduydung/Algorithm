# Given a non-empty array of integers nums, 
# every element appears twice except for one. 
# Find that single one.

def singleNumber(nums):
    dict_nums = {}
    for i in nums:
        dict_nums[i] = dict_nums.get(i, 0)+1
    for key, val in dict_nums.items():
        if val == 1:
            return key

print(singleNumber([1,1,2]))