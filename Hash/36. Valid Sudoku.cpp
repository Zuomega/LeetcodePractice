/*
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。
 

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xxpit5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> hashc[board.size()];
        unordered_set<char> hashr[board[0].size()];
        unordered_set<char> hashb[3][3];

        int b1, b2;
        for (int r = 0 ; r < board.size(); r++)
        {
            for (int c = 0 ; c < board[r].size(); c++)
            {
                if (board[r][c] == '.')
                {
                    continue;
                }
                b1 = (r)/3  ;
                b2 = (c)/3 ;
                if (hashc[c].count(board[r][c]) || hashr[r].count(board[r][c]) || hashb[b1][b2].count(board[r][c])  )
                {
                    return false;
                }else{
                    hashc[c].insert(board[r][c]);
                    hashr[r].insert(board[r][c]);
                    hashb[b1][b2].insert(board[r][c]);
                }
            }
        }
        return true;
    }
};