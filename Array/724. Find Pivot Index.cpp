/*
给你一个整数数组 nums ，请计算数组的 中心下标 。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/yf47s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int lefthalf = 0;
        int righthalf = 0;
        int length = nums.size();
        for (int i = 1; i < length; i++)
        {
            righthalf += nums[i];
        }
        if (lefthalf == righthalf)
        {
            return 0;
        }
        for (int i = 0; i < length - 1; i++)
        {
            lefthalf += nums[i];
            righthalf -= nums[i+1];
            if (lefthalf == righthalf)
            {
                return i+1;
            }
        }
        return -1;
    }
};