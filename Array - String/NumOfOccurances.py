# Returning a dictionary with number of occurances for each item 
# O(n)
# Similar to collections.count
def NumOfOccurances(arr):
    set_arr = set(arr)
    dict_occur = {}
    for i in range(0,len(arr)):
        dict_occur[arr[i]] = 0
    for i in range(0,len(arr)):
        if (arr[i] in set_arr):
            #access using keys
            dict_occur[arr[i]] = 1 + dict_occur[arr[i]]
    #print(dict_occur)
    return dict_occur


print(NumOfOccurances([1,2,3,4,5,1,2,2,2,4]))