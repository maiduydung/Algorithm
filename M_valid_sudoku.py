# https://leetcode.com/problems/valid-sudoku/
# Each row must contain the digits 1-9 without repetition.
# Each column must contain the digits 1-9 without repetition.
# Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        check = set()
        for i in range(9):
            for j in range(9):
                current = board[i][j]
                if current != ".":
                    if (i,current) in check or (current,j) in check or (i/3,j/3,current) in check:
                        return False
                
                check.add((i,current))
                check.add((current,j))
                check.add((i/3,j/3,current))
                print(check)
        return True