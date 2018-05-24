// 33ms 80.20%
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = s.size();
        string res;
        res.reserve(len);
        // 把从上到下，再向右上称作一组字符，numGroup即一组字符的数量
        int numGroup = numRows + numRows - 2;
        // 第1行，每一组字符只包含1个字符
        for (int i = 0; i < len; i += numGroup)
            res.push_back(s[i]);
        // 中间numRows-2行，每一组字符包含2个字符
        for (int row = 1; row + 1 < numRows; ++row) {
            int diff = numGroup - row - row;
            for (int i = row; i < len; i += numGroup) {
                res.push_back(s[i]);
                if (i + diff >= len)
                    break;
                res.push_back(s[i + diff]);
            }
        }
        // 最后1行，每一组字符只包含1个字符
        for (int i = numRows - 1; i < len; i += numGroup)
            res.push_back(s[i]);
        return res;
    }
};