class Solution(object):
    def lengthOfLongestSubstring(self, s):
        a_ptr = 0
        b_ptr = 0
        hash_set = set()
        max_val = 0
        
        while(b_ptr < len(s)):
            if (s[b_ptr] not in hash_set):                
                hash_set.add(s[b_ptr])
                max_val = max(len(hash_set), max_val)
                b_ptr = b_ptr + 1
            else:
                #to initialize that s[b_ptr] onwards is now a an different substring
                hash_set.discard(s[a_ptr])
                a_ptr = a_ptr + 1
        return max_val