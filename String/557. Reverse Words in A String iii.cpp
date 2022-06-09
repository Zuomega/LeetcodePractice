/*
给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。


*/

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;

        for (int i = 0; i <s.size();i++)
        {
            if (s[i] == ' ')
            {
                if (s[start] != ' ')
                {
                    string rs = reversesubword(s.substr(start, i-start));
                    s.replace(start,i-start,rs);
                }
                start = i + 1;
            }
        }
        if (start < s.size())
        {
            string rs = reversesubword(s.substr(start, s.size()-start));
            s.replace(start,s.size()-start,rs);
        }
        return s;

    }

    string reversesubword(string s)
    {
        int l = 0;
        int r = s.size()-1;
        while (r > l)
        {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
        return s;
    }
};