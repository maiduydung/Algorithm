#https://leetcode.com/problems/average-of-levels-in-binary-tree/
# Given a non-empty binary tree, 
# return the average value of the nodes on each level in the form of an array.

# Input:
#     3
#    / \
#   9  20
#     /  \
#    15   7
# Output: [3, 14.5, 11]

# The average value of nodes on level 0 is 3,  
# level 1 is 14.5
# level 2 is 11.
# return [3, 14.5, 11].

#overall the idea is straightforward 
#store the sum and number of nodes in each depth lv, then divide them to get the avg
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        info_arr = []
        def dfs(node, depth = 0):
            if node:
                if(len(info_arr) <= depth):
                    #2 element arr
                    info_arr.append([0,0]) #sum, nodes seen
                info_arr[depth][0] += node.val
                info_arr[depth][1] += 1
                #info_arr will be sth like this

                #input [3,9,20,15,7] (the above tree)

                # [[3, 1]]
                # [[3, 1], [9, 1]]
                # [[3, 1], [9, 1], [15, 1]]
                # [[3, 1], [9, 1], [22, 2]]
                # [[3, 1], [29, 2], [22, 2]]


                dfs(node.left, depth + 1)#increase depth by 1 everytime we go down 1lv deeper
                dfs(node.right, depth + 1)
        dfs(root)
        return [float(sum/nodes_seen) for sum, nodes_seen in info_arr]
        #returning an array, each element is a float num(sum/nodes_seen), which can be found in info_arr