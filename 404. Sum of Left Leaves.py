'''
Description:
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
'''

'''
Information about input objects in test phase:
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
'''


# My Implementation:
class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        sum = 0
        backup = []
        if root == None:
            return 0
        while(True):
            if root.left != None:
                if root.left.left==None and root.left.right ==None:
                    sum += root.left.val
                if root.right ==None:
                    root = root.left
                else:
                    backup.append(root.right)
                    root = root.left
            else:
                if root.right != None:
                    root = root.right
                else:
                    if len(backup)!=0:
                        root = backup.pop(-1)
                    else:
                        break
        return sum
        
'''
Comment:
I just used a while loop for this task, since I am not used to recursion at now. 
My code runs for 20ms and consume 13MB memory space.
But the fast code runs for 8ms use recursion, as shown below:
'''

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        else:
            r = 0
            if root.left and root.left.left is None and root.left.right is None:
                r += root.left.val
            elif root.left:
                r += self.sumOfLeftLeaves(root.left)
            if root.right:
                r += self.sumOfLeftLeaves(root.right)
            return r
            
  '''
  The code using least memory of 12.05MB is shown below. We could see it utilize a container deque(). 
  '''
  class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        res = 0
        
        from collections import deque
        q = deque([(root, False), ])
        while q:
            n, is_left = q.popleft()
            if not n.left and not n.right and is_left:
                res += n.val 
                continue
            if n.left:
                q += (n.left, True),
            if n.right:
                q += (n.right, False),
        return res
    
 # TODO
 ''' 
 Don't know the details about their advatages. May study it later.
 '''
 
