#https://leetcode.com/problems/minimum-absolute-difference
class Solution:    
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff = 10**6
        for i in range(0,len(arr)-1):
            if(arr[i+1]-arr[i]<min_diff):
                min_diff = arr[i+1]-arr[i]
        res = []
        for i in range(0,len(arr)-1):
            if(arr[i+1]-arr[i] == min_diff):
                res.append([arr[i], arr[i+1]])
        return(res)
