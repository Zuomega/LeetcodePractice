/*
根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> numlist;
        int a,b;
        int tmpnum;
        for (auto t: tokens)
        {
            if (isNum(t))
            {
                tmpnum = std::stoi(t);
                numlist.push_back(tmpnum);
            }else{
                
                switch(t[0])
                {
                    case '+':
                        a = numlist.back();
                        numlist.pop_back();
                        b = numlist.back();
                        numlist.pop_back();
                        numlist.push_back(b+a);
                        break;
                     case '-':
                        a = numlist.back();
                        numlist.pop_back();
                        b = numlist.back();
                        numlist.pop_back();
                        numlist.push_back(b-a);
                        break;
                    case '*':
                        a = numlist.back();
                        numlist.pop_back();
                        b = numlist.back();
                        numlist.pop_back();
                        numlist.push_back(b*a);
                        break;
                    case '/':
                        a = numlist.back();
                        numlist.pop_back();
                        b = numlist.back();
                        numlist.pop_back();
                        numlist.push_back(b/a);
                        break;  
                }

            }
        }
        return numlist.back();
    }

    bool isNum(string innum)
    {
        if (innum[0] > 47 && innum[0] < 58)
        {
            return true;
        }else{
            if (innum.size() > 1 && innum[1] > 47 && innum[1] < 58)
            {
                return true;
            }else{
                return false;
            }
        }
    }
};