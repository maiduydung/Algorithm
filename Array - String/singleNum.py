#XOR 1 ^ 2 ^ 1 = (1^1) ^ 2 = 0 ^ 2 = 2
# Given a non-empty array of integers nums, 
# every element appears twice except for one. 
# Find that single one.

def singleNumber(nums):
    temp = 0
    for i in nums:
        temp = temp ^ i
    return temp
print(singleNumber([1,1,2]))
