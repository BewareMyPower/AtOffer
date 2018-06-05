// 9ms 51.87
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        
        vector<decltype(strs[0].cbegin())> iters(n);
        for (int i = 0; i < n; ++i)
            iters[i] = strs[i].cbegin();
        
        string prefix = "";
        while (true) {
            if (iters[0] == strs[0].cend())
                return prefix;
            for (int i = 1; i < n; ++i) {
                if (iters[i] == strs[i].cend() || *(iters[i]) != *(iters[i - 1]))
                    return prefix;
                ++iters[i - 1];
            }
            prefix += *iters.back();
            ++iters.back();
        }
        return prefix;
    }
};