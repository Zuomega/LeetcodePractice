/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> outstr;
        if (digits.length() < 1)
        {
            return outstr;
        }
        
        if (digits.length() <= 1)
        {
            for(auto s: dic[std::stoi(digits)-2])
            {
                outstr.push_back(s);
            }
            return outstr;
        }
        string chars(1,digits[0]);
        for (auto s: dic[std::stoi(chars)-2])
        {
            
            string newdigit = digits.substr(1,string::npos);
            for (auto ss : letterCombinations(newdigit))
            {
                string news = s;
                news += ss;
                outstr.push_back(news);
            }
        }
        return outstr;
    }
    vector<vector<string>> dic= {{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
};