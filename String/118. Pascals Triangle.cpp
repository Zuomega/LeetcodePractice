/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) return {{}};

        vector<vector<int>> t = {{1}};

        for (int i = 1; i < numRows; i++)
        {
            vector<int> temp = {1};
            for (int j=1;j < i;j++)
            {
                temp.push_back(t[i-1][j-1]+t[i-1][j]);
            }
            temp.push_back(1);
            t.push_back(temp);
        }

        return t;
    }
};