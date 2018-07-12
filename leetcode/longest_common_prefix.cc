#include "common.h"

// 4ms 99.85
class Solution {
public:
    bool isEqualAtChar(size_t pos, vector<string>& strs) {
        if (strs.size() == 0 || pos >= strs[0].size())
            return false;
        for (size_t i = 0; i + 1 < strs.size(); ++i) {
            if (pos >= strs[i + 1].size() || strs[i][pos] != strs[i + 1][pos])
                return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() > 0) {
            size_t pos = 0;
            while (isEqualAtChar(pos, strs))
                ++pos;
            return strs[0].substr(0, pos);
        }
        return "";
    }
};