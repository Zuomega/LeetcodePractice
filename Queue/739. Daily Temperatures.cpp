/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/genw3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stack;
        vector<int> out;

        for (int i = 0; i < temperatures.size(); i++)
        {
            if (stack.empty() || temperatures[stack.back()] > temperatures[i])
            {
                stack.push_back(i);
                out.push_back(0);
                continue;
            }else{
                while(!stack.empty() && temperatures[stack.back()] < temperatures[i])
                {
                    out[stack.back()] = i - stack.back();
                    stack.pop_back();
                    
                }
                stack.push_back(i);
                out.push_back(0);
            }
        }

        return out;
    }
};