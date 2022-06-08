/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tmp, out;
        out = {1};
        if (rowIndex == 0)
        {
            return out;
        }
        out = {1,1};
        if (rowIndex == 1)
        {
            return out;
        }
        for (int i = 2; i <= rowIndex; i++)
        {
            tmp = out;
            out.clear();
            out.push_back(1);
            for (int j = 0; j < tmp.size() - 1; j++)
            {
                out.push_back(tmp[j]+tmp[j+1]);
            }
            out.push_back(1);
        }
        return out;
    }
};