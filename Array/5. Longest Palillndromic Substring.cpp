/*
给你一个字符串 s，找到 s 中最长的回文子串。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int start = 0;
        int end = 0;
        int len1, len2, len;

        for (int n = 0; n < length - 1; n++)
        {
            len1 = palindromeForCurrentCore(s, n, n);
            len2 = palindromeForCurrentCore(s, n, n+1);
            len = max(len1, len2);
            if (len > (end - start +1))
            {
                start = n - len/2 + 1;
                if (len%2) start -= 1;
                end = start + len - 1;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int palindromeForCurrentCore(const string & s, int left, int right)
    {
        int L = left;
        int R = right;
        int locall = s.size();
        if (s[L] != s[R])
        {
            return 1;
        }

        while(L> 0 && R < locall - 1 && s[L] == s[R])
        {
            L--;
            R++;
        }
        if (s[L] != s[R])
        {
            L++;
            R--;
        }
        return R - L + 1;
    }
};