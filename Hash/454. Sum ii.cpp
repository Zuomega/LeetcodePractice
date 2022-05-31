/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xxwhng/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> hash;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums1.size(); j++)
            {
                int sum = nums1[i] + nums2[j];
                if (hash.count(sum))
                {
                    hash[sum]++;
                }else{
                    hash.insert(make_pair(sum,1));
                }
            }
        }

        int count = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums1.size(); j++)
            {
                int sum =  nums3[i] + nums4[j];
                if (hash.count(-sum))
                {
                    count += hash[-sum];
                }
            }
        }

        return count;
    }
};