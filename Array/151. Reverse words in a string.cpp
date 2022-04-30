/*
给你一个字符串 s ，颠倒字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/crmp5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    string reverseWords(string s) {
        string out;
        bool is_hit = false;
        int length = s.size();
        int last_tail = length;
        for (int i = length - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (is_hit)
                {
                    out  += s.substr(i+1, (last_tail - i - 1));
                    out.push_back(' ');
                }
                is_hit = false;
                last_tail = i;
            }else{
                is_hit = true;
            }
        }
        if (is_hit)
        {
            out  += s.substr(0, last_tail );
        }

        if (*(out.end()-1) == ' ')
        {
            out.pop_back();
        }
        return out;

    }
};