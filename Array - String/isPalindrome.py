import string
#two pointer approach
def isPalindrome(s):
    s = s.lower()
    s = s.replace(" ", "")
    s = s.translate(str.maketrans('', '', string.punctuation))
    end = len(s)-1
    for start in range(len(s)//2):
        if(s[start] != s[end]):
            return False
        end = end - 1
        print(start, end)
    return True
print (isPalindrome('A man, a plan, a canal: Panama'))