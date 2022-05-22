/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxcnt = 0;
        unordered_map<char, int> hash;

        int cnt = 0;
        int minidx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (hash.count(s[i]))
            {
                if ( hash[s[i]] < minidx)
                {
                    cnt++;
                    hash[s[i]] = i;
                    continue;
                }
 
                if (cnt  > maxcnt)
                {
                    maxcnt = cnt;
                }
                minidx = hash[s[i]];
                hash[s[i]] = i;
                cnt = i - minidx;
            }else{
                cnt++;
                hash.insert(make_pair(s[i], i ));
            }
        }
        if (cnt > maxcnt)
        {
            maxcnt = cnt;
        }

        return maxcnt;
    }
};