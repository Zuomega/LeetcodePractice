/*
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int cursum = 0;
        int idx = 0;
        return bfs(nums, target, idx, cursum );
    }

    int bfs(vector<int>& nums, int target, int idx, int cursum)
    {
        if (nums.size()<=idx + 1)
        {
            int returnnum = 0;
            if((cursum + nums[idx]) == target)
            {
                returnnum++;
            }
            if((cursum - nums[idx]) == target)
            {
               returnnum++;
            }
            return returnnum++;
        }
        return bfs(nums, target, idx+1, cursum + nums[idx]) + bfs(nums, target, idx+1, cursum - nums[idx]);

    }
};