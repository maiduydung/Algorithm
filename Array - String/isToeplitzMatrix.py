#https://leetcode.com/problems/toeplitz-matrix/
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        for r in range(0, len(matrix[0])-1):
            for c in range(0, len(matrix)-1):
                if(matrix[c][r] != matrix[c+1][r+1]):
                    return False
        return True