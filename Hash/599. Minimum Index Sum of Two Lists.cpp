/*
假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/hash-table/xhfact/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> out;
        int len1 = list1.size();
        int len2 = list2.size();

        unordered_map<string, int> hash;
        for (int i = 0; i < list1.size(); i++)
        {
            hash.insert(make_pair(list1[i], i));
        }

        int minsum = len1 + len2;
        for (int j = 0; j < list2.size(); j++ )
        {
            if (hash.count(list2[j]))
            {
                if (hash[list2[j]] + j < minsum)
                {
                    minsum = hash[list2[j]] + j;
                    out = {list2[j]};
                }else if (hash[list2[j]] + j == minsum)
                {
                    out.push_back(list2[j]);
                }
            }
        }

        return out;

    }
};