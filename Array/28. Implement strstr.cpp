/*
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/cm5e2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
        {
            return -1;
        }

        int n = haystack.size();
        int m = needle.size();
        if (m > n)
        {
            return -1;
        }
        int * dp = new int[m];

        int i = dp[0] = -1;
        int j = 0;
        while (j < m - 1)
        {
            if ( i < 0 || needle[i] == needle[j])
            {
                i++; 
                j++;         
                dp[j] = i;
            }else{
                i = dp[i];
            }
        }

        i = 0;
        j = 0;
        int out = -1;
        while ( j < n  && i < m)
        {
            if (i < 0 || haystack[j] == needle[i])
            {
                out = j;
                i++;
                j++;
            }else{
                i = dp[i];
            }
        }

        if( j >= n - m + 1 && i != m )
        {
            return -1;
        }

        return out - m + 1;
    }
};