/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/array-and-string/c0w4r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int cnt = 0;
        bool has = false;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int tmpsum = sum + nums[i];
            if (tmpsum < target)
            {
                sum = tmpsum;
                cnt++;
            }else{
                has = true;
                cnt++;
                break;
            }
        }
        if (!has)
        {
            cnt = 0;
        }
        return cnt;
    }
};