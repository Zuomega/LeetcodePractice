/**
 *序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xomr73/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 
 * 
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (root == nullptr)
        {
            return "";
        }else{
            s += to_string(root->val);
            s += ",";
        }
        if (root->left != nullptr)
        {
           s += serialize(root->left);
        }else{
            s+= "n";
            s+= ",";
        }
        if (root->right != nullptr)
        {   
            s += serialize(root->right);
        }else{
            s+= "n";
            s+= ",";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.size())
        {
            return nullptr;
        }
        vector<string> slist;
        string ss= {};
        for (auto a : data)
        {
            if (a != ',')
            {
                ss += a;
            }else{
                if (ss.size())
                {
                    slist.push_back(ss);
                }
                ss = {};
            }
        }
        return sdeserialize(slist);
    }

     // Decodes your encoded data to tree.
    TreeNode* sdeserialize(vector<string> & data) {
        if (data.front() == "n")
        {
            data.erase(data.begin());
            return nullptr;
        }
        string ss = data.front();
        int newval = std::stoi(ss, nullptr, 10);
        TreeNode* newnode = new TreeNode(newval);
        data.erase(data.begin());
        newnode->left = sdeserialize(data);
        newnode->right = sdeserialize(data);
        return newnode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));