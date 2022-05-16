/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xxo631/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<int>> hash;

        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            if (hash.count(tmp))
            {
                hash[tmp].push_back(i);
            }else{
                vector<int> tmpi = {i};
                hash.insert(make_pair(tmp, tmpi));
            }
                    
        }

        vector<vector<string>> out;
        for (auto j = hash.begin(); j != hash.end(); j++)
        {
            vector<string> tmpout;
            for (auto k: j->second)
            {
                tmpout.push_back(strs[k]);
            }
            out.push_back(tmpout);
        }
        return out;
    }
};