/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xx5bzh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0)
        {
            return false;
        }
        unordered_map<int,int> hash;
        int cnt = 1;
        hash.insert(make_pair(nums[0], 0));
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (hash.count(nums[i]))
            {
                return true;
            }else{
                if (cnt < k )
                {
                    cnt++;
                    hash.insert(make_pair(nums[i], i));
                }else{
                    hash.erase(nums[i-k]);
                    hash.insert(make_pair(nums[i], i));
                }
            }
        }
        return false;
    }
};