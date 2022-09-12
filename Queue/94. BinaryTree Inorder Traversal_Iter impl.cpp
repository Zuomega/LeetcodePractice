/**
 * 
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        vector<TreeNode*> stack;
        unordered_set<TreeNode*> visited;
        vector<int> out;

        stack.push_back(root);
        while (stack.size())
        {

            TreeNode* cur = stack.back();

            if (cur->left != nullptr && !visited.count(cur->left))
            {
                stack.push_back(cur->left);
                continue;
            }
            
            if (!visited.count(cur))
            {
                out.push_back(cur->val);
                visited.insert(cur);
            }
            
            if (cur->right != nullptr && !visited.count(cur->right))
            {
                stack.push_back(cur->right);
            }else{
                stack.pop_back();
            }
                
            
        }
        return out;
    }
};