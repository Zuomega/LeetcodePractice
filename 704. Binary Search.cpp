/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        if (length == 0)
        {
            return -1;
        }
        int left = 0;
        int right = length - 1;
        int mid = length/2;
        int curnum;
        while(left < right)
        {
            curnum = nums[mid];
            if (target == curnum)
            {
                return mid;
            }else if(target > curnum)
            {   
                left = mid + 1;
                mid = (right + left)/2;  
            }else{
                right = mid - 1;
                mid = (right + left)/2;
            }
        }
        if (target == nums[right])
        {
            return right;
        }else{
            return -1;
        }
    }
};