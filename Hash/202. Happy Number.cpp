/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

 

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xh1k9i/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        
        while(!hash.count(n))
        {
            hash.insert(n);
            int newn = 0;
            while(n > 0)
            {
                int current = n % 10;
                newn += current * current;
                n = n/10;
            }
            if (newn == 1)
            {
                return true;
            }
           
            n = newn;
        }
        return false;
    }
};