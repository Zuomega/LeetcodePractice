/*
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hash;

        int len = s.size();

        for (int i = 0; i < len; i++)
        {
            if (hash.count(s[i]))
            {
               hash[s[i]] = -1;
            }else{
               hash.insert(make_pair(s[i],i));
            }
        }

        int idx = -1;
        for (auto j = hash.begin(); j != hash.end(); j++)
        {
           if (j->second != -1)
           {
               if (idx == -1)
                {
                    idx = j->second;
                }else if (j->second < idx)
                {
                    idx = j->second;
                }

           }
        }
        return idx;
    }
};