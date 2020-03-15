#https://leetcode.com/problems/permutation-in-string/
# Input: s1 = "ab" s2 = "eidbaooo"
# Output: True
# Explanation: s2 contains one permutation of s1 ("ba").

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_set = set(s1)
        for i in range(len(s2)):
            if i < len(s2) - len (s1):
                check_set = set()
                for j in range(len(s1))
                check_set.add(s2[i])
                check_set.add(s2[i+1])
                check_set.add(s2[i+2])
                if(check_set.issubset(s1_set)):
                    return True
        return False