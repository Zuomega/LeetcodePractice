/*
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        int block_w = length/2 + length%2;
        int block_h = length/2;
        
        for (int i = 0; i < block_h; i++)
        {
            for (int j = 0; j < block_w; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[length - j - 1][i];
                matrix[length - j - 1][i] = matrix[length - i - 1][length - j - 1];
                matrix[length - i - 1][length - j - 1] = matrix[j][length - i - 1];
                matrix[j][length - i - 1] = tmp;
            }
        }
    }
};