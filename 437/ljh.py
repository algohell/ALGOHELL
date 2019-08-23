# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
              return 0
        n_list = [root]
        result = []
        while n_list:
            node = n_list.pop()
            path = []
            self.dfs(node,sum,path)
            result += path
            if node.left:
                n_list.append(node.left)
            if node.right:
                n_list.append(node.right)
        return len(result)
    def dfs(self,node,s,path):
        if node:
            if s-node.val == 0:
                path.append(1)
            if node.left:
                self.dfs(node.left, s-node.val, path)
            if node.right:
                self.dfs(node.right, s-node.val, path)
        return 0    