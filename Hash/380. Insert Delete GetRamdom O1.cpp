/*
实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xx0zpt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class RandomizedSet {
public:
    unordered_map<int,int> hash;
    vector<int> dic;
    RandomizedSet() {
        std::srand(std::time(nullptr));
    }
    
    bool insert(int val) {
        if (!hash.count(val))
        {
            hash.insert(make_pair(val, dic.size()));
            dic.push_back(val);
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if (!hash.count(val))
        {
            return false;
        }else{
            int idxtmp = hash[val];
            int valtmp = dic[dic.size()-1];
            dic[idxtmp] = valtmp;
            hash[valtmp] = idxtmp;
            dic.pop_back();
            hash.erase(val);   
            return true;
        }
    }
    
    int getRandom() {
        int r = std::rand()*dic.size()/RAND_MAX;
        return dic[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */