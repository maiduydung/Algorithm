def removeDuplicates( nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 2 pointers
        i=0
        for j in range(1,len(nums)):
            if nums[j]!=nums[i]:
                i+=1
                nums[i]=nums[j]
        return nums
                



print(removeDuplicates([0,0,1,1,1,2,2,3,3,4]))

