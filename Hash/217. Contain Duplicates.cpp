/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;

        for (auto a : nums)
        {
            if (hash.count(a))
            {
                return true;
            }
            hash.insert(a);
        } 
        return false;
    }
};