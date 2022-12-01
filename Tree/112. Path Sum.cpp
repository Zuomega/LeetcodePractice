/**
 * @brief 
 * 
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

叶子节点 是指没有子节点的节点。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xo566j/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumSub(root, 0, targetSum);
    }

    bool  hasPathSumSub(TreeNode* root, int curSum, int targetSum)
    {
         if (root == nullptr)
        {
            return false;
        }

        curSum += root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            if (targetSum == curSum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return hasPathSumSub(root->left, curSum, targetSum) || hasPathSumSub(root->right, curSum, targetSum);
    }
};