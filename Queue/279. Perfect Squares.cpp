/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/kfgtt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


class Solution {
public:
    int numSquares(int n) {
        int insqrt = static_cast<int>(sqrt(n));
        if (n - pow(insqrt, 2) == 0)
        {
            return 1;
        }

        vector<int> powlist;
        for (int i = 1; i <= insqrt; i++)
        {
            powlist.push_back(pow(i , 2));
        }
        queue<int> q;
        q.push(n);
        int cnt = 0;
        while(q.size())
        {
            cnt++;
            int lenq = q.size();
            for (int i = 0; i < lenq; i++)
            {
                int tmp = q.front();
                q.pop();
                for (auto power : powlist)
                {

                    if (power > tmp)
                    {
                        break;
                    }else{
                        if (tmp - power == 0)
                        {
                            return cnt;
                        }else{
                            q.push(tmp - power);
                        }
                        
                    }
                }
            }
        }
        return cnt;

    }
};