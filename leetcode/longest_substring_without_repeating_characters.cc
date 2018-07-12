#include "common.h"

// 34ms 74.89%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxlen = 0;
        vector<int> hash(256, -1);  // 用数组模拟hashmap，使用带符号int表示下标从而方便判断是否下标在内
        for (int i = 0; i < s.size(); ++i) {  // s[start..i)为子串
            char ch = s[i];
            if (hash[ch] >= start) {  // ch在子串中出现过
                maxlen = max(maxlen, i - start);
                start = hash[ch] + 1;
            }
            hash[ch] = i;
        }  // 子串s[start..s.size())还未比较
        return max(maxlen, static_cast<int>(s.size() - start));
    }
};