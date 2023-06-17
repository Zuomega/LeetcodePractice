
/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

 

示例 1：

输入：x = 4
输出：2

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
        {
            return x;
        }
        int left = 0; int right = 46341; int mid = min((right + left)/2, 46340);
        int power;
        while(left < right - 1)
        {
            power = mid * mid ;
            if (power== x) {return mid;}
            else if (power < x)
            {
                left = mid;
                mid =  (right + left)/2;
            }else if (power > x)
            {
                right = mid;
                mid =  (right + left)/2;
            }
        }
        return mid;
    }
};