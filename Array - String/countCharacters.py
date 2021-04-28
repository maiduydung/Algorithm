#https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res = ""
        d = collections.Counter(chars)
        for word in words:
            dw = collections.Counter(word)
            for c in word:
                if (dw[c] > d[c]):
                    break
            # run all the way to the end of the array, if dw[c] still < d[c] then add to res
            else:
                res = res + word
        return len(res)
