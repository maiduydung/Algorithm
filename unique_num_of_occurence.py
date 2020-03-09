# https://leetcode.com/problems/unique-number-of-occurrences/
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        hashset = set()
        count = 0
        count_arr = []
        for i in arr:
            hashset.add(i)
        
        for j in arr:
            if j in hashset:
                print(arr.index(j))
                #count_arr[j]