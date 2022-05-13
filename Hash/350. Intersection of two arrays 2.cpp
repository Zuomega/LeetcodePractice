/*
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xx5hsd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();

        unordered_map<int,int> hash;

        for (int i = 0; i < l1; i++)
        {
            if (hash.count(nums1[i]))
            {
                hash[nums1[i]]++;
            }else{
                hash.insert(make_pair(nums1[i], 1));
            }
        }

        vector<int> out;
        for (int j = 0; j < l2; j++)
        {
            if (hash.count(nums2[j]))
            {
                out.push_back(nums2[j]);
                if (hash[nums2[j]] > 1)
                {
                    hash[nums2[j]]--;
                }else{
                    hash.erase(nums2[j]);
                }
            }
        }
        return out;
    }
};