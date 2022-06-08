/*
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone = 0;
        int l = 0;
        int r = 0;
        int len =  nums.size();

        while (r < len && l < len)
        {
            if (nums[l] != 1)
            {
                l++;
            }else{
                if (nums[r] == 1)
                {
                    r++;
                }else{
                    if (r - l > maxone)
                    {
                        maxone = r - l;
                    }
                    l = r;
                    r++;
                }
            }
            if(r < l)
            {
                r = l;
            } 
        }
        if (r > l)
        {
             if (r - l > maxone)
            {
                maxone = r - l;
            }
        }
return maxone;
    }
};