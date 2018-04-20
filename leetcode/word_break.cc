/**
 * Given a string s and a dictionary of words dict,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s ="leetcode",
 * dict =["leet", "code"].
 *
 * Return true because"leetcode"can be segmented as"leet code"
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<int> wordlen;  // 字典中单词的所有可能长度
        for (auto& word : dict)
            wordlen.emplace(word.size());
        
        int n = s.size();
        vector<bool> dp(n + 1, false);  // dp[i]即s.substr(i)作为第一参数的结果
        dp[n] = true;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int len : wordlen) {
                if (i + len <= n && dp[i + len] &&
                    dict.find(s.substr(i, len)) != dict.end()) {
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};