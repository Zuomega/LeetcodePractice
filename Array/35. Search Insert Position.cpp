/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/cxqdh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        if (length == 0)
        {
            return 0;
        }
        int left= 0;
        int right = length -1;
        int mid = length/2;
        int cur;
        while (left < right)
        {
            cur = nums[mid];
            if (target == cur)
            {
                return mid;
            }else if (target > cur)
            {
                left = mid + 1;
                mid = (right + left)/2;
            }else{
                right = mid;
                mid = (right + left)/2;
            }
        }

        cur =  nums[right];
        if (target == cur)
        {
            return right;
        }else if (target > cur)
        {
            return right + 1;
        }else{
            return right;
        }
    }
};