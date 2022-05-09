/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xhjvbj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashs, hasht;
        int length = s.size();

        for (int i = 0; i < length; i++)
        {
            if (!hashs.count(s[i]))
            {
                if (!hasht.count(t[i]))
                {
                    hashs[s[i]] = t[i];
                    hasht[t[i]] = s[i];
                }else{
                    return false;
                }
                
            }else{
                if (hashs[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};