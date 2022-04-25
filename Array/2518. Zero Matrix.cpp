/*
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size())
        {
            return;
        }
        int height = matrix.size();
        int width = matrix[0].size();
        std::unordered_set<int> row;
        std::unordered_set<int> col;

        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                if (matrix[h][w] == 0)
                {
                    row.emplace(h);
                    col.emplace(w);
                }
            }
        }

        for (auto r : row)
        {
            for (int w = 0; w < width; w++)
            {
                matrix[r][w] = 0;
            }
        }
        for (auto c : col)
        {
            for (int h = 0; h < height; h++)
            {
                matrix[h][c] = 0;
            }
        }
    }
};