/*
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

class Node {
    public int val;
    public List<Node> neighbors;
}
 

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/gmcr6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        {
            return nullptr;
        }
        queue<Node*> q;
        unordered_map<Node*, Node*> visited;

        Node* outnode = new Node(node->val);
        visited.insert(make_pair(node, outnode));
        q.push(node);


        while(q.size())
        {
            Node* tmp = q.front();
            q.pop();

            for (auto n : tmp->neighbors)
            {
                if(!visited.count(n))
                {
                    visited[n] = new Node(n->val);
                    q.push(n);
                }
                visited[tmp]->neighbors.emplace_back(visited[n]);
            }
        }
        return outnode;
    }
};