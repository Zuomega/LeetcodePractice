/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/c5tv3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        {
            return intervals;
        }
        vector<vector<int>> outvec;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i< intervals.size(); i++)
        {
            int L = intervals[i][0];
            int R = intervals[i][1];
            if (!outvec.size() || outvec.back()[1] < L)
            {
                outvec.push_back({L,R});
            }else{
                outvec.back()[1] = max(outvec.back()[1], R);
            }
        }
        return outvec;

    }
};