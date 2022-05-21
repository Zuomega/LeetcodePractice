/**
 * 给定一棵二叉树 root，返回所有重复的子树。

对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

如果两棵树具有相同的结构和相同的结点值，则它们是重复的。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xxm0i6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * 
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string tmp = findDuplicateAndGetId(root);

        return out;
    }

    string findDuplicateAndGetId(TreeNode* root)
    {
        if (root -> left == nullptr && root -> right == nullptr)
        {
            string id = "." + std::to_string(root->val);
            id += ".";
            
            if (hash.count(id))
            {
                if (hash[id] == 1)
                {
                    this -> out.push_back(root);
                }
                hash[id]++;
            }else{
                this -> hash.insert(make_pair(id, 1));
            }
            return id;
        }

        string id = "."+std::to_string(root->val);
        if (root->left)
        {
            id += findDuplicateAndGetId(root -> left);
        }else{
            id += "_";
        }
        if (root->right)
        {
            id += findDuplicateAndGetId(root -> right);
        }else{
            id += "_";
        }
        id += ".";

        if (hash.count(id))
        {
            if (hash[id] == 1)
            {
                this -> out.push_back(root);
            }
            hash[id]++;
        }else{
            this -> hash.insert(make_pair(id, 1));
        }
        return id;
    }

private:
    unordered_map<string, int> hash;
    vector<TreeNode*> out;
};