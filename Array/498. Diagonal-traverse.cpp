/*
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int height = mat.size();
        int width = mat[0].size();
        int amount = height * width;

        vector<int> out;

        int h = 0;
        int w = 0;
        bool up = true;
        for (int i = 0; i < amount; i++ )
        {
            out.push_back(mat[h][w]);
            if (up)
            {
                h--;
                w++;
                if (h < 0 && w != width)
                {
                    h = 0;
                    up = false;
                }
                if (w == width)
                {
                    h+=2;
                    w = width - 1;
                    up = false;
                }
            }else{
                h++;
                w--;
                if (w < 0 && h != height)
                {
                    w = 0;
                    up = true;
                }
                if (h == height)
                {
                    w+=2;
                    h = height - 1;
                    up = true;
                }
            }
        }
        return out;

    }
};