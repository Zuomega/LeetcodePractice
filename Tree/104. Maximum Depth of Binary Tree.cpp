/**
 * @brief 给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。
 * 

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }else  if (root->left == nullptr && root->right != nullptr)
        {
            return 1 + maxDepth(root->right);
        }else if (root->left != nullptr && root->right == nullptr)
        {
            return 1 + maxDepth(root->left);
        }else if (root->left != nullptr && root->right != nullptr){
            return 1 + max(maxDepth(root->left),maxDepth(root->right));
        }else{
            return 1;
        }
        
    }
};