class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        hash_set = set()
        count = 0
        for s in S:
            hash_set.add(s)
        
        for j in J:
            if j in hash_set:
                count++
        
        return count