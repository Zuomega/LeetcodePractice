
/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/open-the-lock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000")
        {
            return 0;
        }
        queue<string> q;
        unordered_set<string> visited;
        int step = 0;
        string begin = "0000";
       
       unordered_set<string> deadendsdic(deadends.begin(), deadends.end());
       if (deadendsdic.count(begin))
       {
           return -1;
       }
        q.push(begin);
        visited.insert(begin);
        while(q.size())
        {
            step++;
            int qsize = q.size();
            for(int i = 0; i < qsize; i++)
            {
                string cur = q.front();
                q.pop();

                
                     for(int j = 0; j < 4; j++)
                    {
                        string tmpnextf = moveonebackw(cur, j);
                        string tmpnextb = moveoneforw(cur, j);
                        bool isdeadf = false;
                        bool isdeadb = false;
                        if (deadendsdic.count(tmpnextb))
                        {
                            isdeadb = true;
                        }
                        
                        if (deadendsdic.count(tmpnextf))
                        {
                            isdeadf = true;
                        }

                        if (!isdeadb && !visited.count(tmpnextb))
                        {
                            q.push(tmpnextb);
                            visited.insert(tmpnextb);
                            if (tmpnextb == target)
                            {
                                return step ;
                            }
                        }
                        if (!isdeadf && !visited.count(tmpnextf))
                        {
                            q.push(tmpnextf);
                            visited.insert(tmpnextf);
                            if (tmpnextf == target)
                            {
                                return step ;
                            }
                        }   
                    }
                

            }
        }
        return -1;
    }

    string moveonebackw(string cur, int j)
    {
       
        if (cur[j] == '0')
        {
            cur[j] = '9';
        }else{
            cur[j] -= 1;
        }
        return cur;
    }

    string moveoneforw(string cur, int j)
    {
        if (cur[j] == '9')
        {
            cur[j] = '0';
        }else{
            cur[j] += 1;
        }

        return cur; 
    }
};