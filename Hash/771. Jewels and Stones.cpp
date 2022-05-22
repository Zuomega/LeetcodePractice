/*

 给你一个字符串 jewels 代表石头中宝石的类型，另有一个字符串 stones 代表你拥有的石头。 stones 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

字母区分大小写，因此 "a" 和 "A" 是不同类型的石头。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xx2a0c/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> dic;

        for (auto j : jewels)
        {
            dic.insert(j);
        }

        int cnt = 0;
        for (auto s : stones)
        {
            if (dic.count(s))
            {
                cnt++;
            }
        }
        return cnt;
    }
};

/*
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // 利用字符串find
        int ans=0;
        for(auto c:stones)
        {
            if(jewels.find(c)!=string::npos)
            {
                ++ans;
            }
        }
        return ans;
    }
};
*/