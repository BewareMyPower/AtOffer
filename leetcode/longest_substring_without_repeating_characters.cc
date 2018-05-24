class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        using size_t = decltype(s.size());
        size_t maxlen = 0;
        size_t iLow = 0;  // 子串左边界
        unordered_map<char, size_t> um;  // 字符 => 字符最近出现的位置
        for (int i = 0; i < s.size(); ++i) {  // s[iLow..i)为子串
            char ch = s[i];
            if (um.find(ch) != um.end() && um[ch] >= iLow) {  // ch在子串中出现过
                maxlen = max(maxlen, i - iLow);
                iLow = um[ch] + 1;
            }
            um[ch] = i;
        }  // 子串s[iLow, s.size())还未比较
        return static_cast<int>(max(maxlen, s.size() - iLow));
    }
};