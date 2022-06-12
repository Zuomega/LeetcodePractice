/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return;
        }
        int l = 0;
        int r = 1;

        while (r < nums.size() && l < nums.size())
        {
            if (nums[l] != 0)
            {
                l++;
            }else{
                if (nums[r] != 0)
                {
                    nums[l] = nums[r];
                    nums[r] = 0;
                    l++;
                    r++;
                }else{
                    r++;
                }
            }
            if (r < l)
            {
                r = l;
            }
        }

    }
};