# if the number of element in set_num is larger than cnt, then it contains duplicate

def containsDuplicate(self, nums):
    set_nums = set(nums)
    cnt=0
    for i in nums:
        if(i in set_nums):
            cnt = cnt + 1
    if(cnt >len(set_nums)):
        return True
    else: return False
