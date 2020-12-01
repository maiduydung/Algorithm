# Rotate Array

# Solution
# Given an array, rotate the array to the right by k steps, where k is non-negative.
def rotate(nums, k):
    new_nums = nums[:]
    for i in range(len(nums)):
        #print((i+k)%len(nums))
        new_nums[(i+k)%len(nums)] = nums[i]
    return new_nums


print(rotate([1,2,3,4,5,6,7], 1))
      #[7,1,2,3,4,5,6]