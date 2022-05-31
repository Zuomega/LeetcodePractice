/*

给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        for (auto n : nums)
        {
            if (hash.count(n))
            {
                hash[n]++;
            }else{
                hash.insert(make_pair(n, 1));
            }
        }

        vector<int> order;
        for (auto m : hash)
        {
            order.push_back(m.second);
        }

        sort(order.begin(), order.end());

        int threshold = order[order.size() - k];
        
        vector<int> out;
        for (auto m : hash)
        {
            if (m.second >= threshold)
            {
                out.push_back(m.first);
            }
        }

        return out;
    }
};