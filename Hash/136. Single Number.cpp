/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xhsyr2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int length = nums.size();
//         int offset = length%2;
//         for(int i = 0; i < length - offset; i += 2)
//         {
//             if (nums[i] != nums[i+1])
//             {
//                 return nums[i];
//             }
//         }
//         if (offset)
//         {
//             return nums[length-1];
//         }
//         return NULL;
//     }
// };

//快排算法不具有线性时间复杂度。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};

/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/