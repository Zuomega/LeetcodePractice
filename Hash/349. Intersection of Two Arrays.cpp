/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        vector<int> out;
       
       for (auto i:nums1)
       {
           hash.insert(i);
       }
       for (auto j :nums2)
       {
           if (hash.count(j))
           {
               out.push_back(j);
               hash.erase(j);
           }
       }
       return out;

    }
};