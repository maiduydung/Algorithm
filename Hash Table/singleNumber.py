# // https://leetcode.com/problems/single-number/
# // Given a non-empty array of integers, every element appears twice except for one.
# // Find that single one.

# // Input: [4,1,2,1,2]
# // Output: 4

#an equivalent solution in c++ would use std map 
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        all_dict = dict(val=0, times = 0)
        #storing val and appearance times 
        for i in nums:
            if(i not in all_dict):
                all_dict[i] = 0
            if(i in all_dict):
                all_dict[i] += 1
        #traversing nums again
        #if element in all_dict has appearance times 1 -> return
        for j in nums:
            if all_dict[j] == 1:
                return j