/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 2)
        {
            return strs[0];
        }
        int length = strs.size();
        int curptr = 0;

        while (true)
        {
            for(int l = 0; l < length - 1; l++)
            {
                if (!strs[l][curptr] )
                {
                    return strs[0].substr(0,curptr);
                }
                if (strs[l][curptr] != strs[l+1][curptr])
                {
                    return strs[0].substr(0,curptr);
                }
               
                if (l == length - 2)
                {
                    curptr++;
                }
            }
        }

        return strs[0].substr(0,curptr);
        
    }
};