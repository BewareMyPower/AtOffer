#include "common.h"

/**
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 * Return all such possible sentences.
 * For example, given
 * s ="catsanddog",
 * dict =["cat", "cats", "and", "sand", "dog"].
 * A solution is["cats and dog", "cat sand dog"].
 */
class Solution {
public:
    // 比如s="catsanddog", path={0,3,7,10}, 返回"cat sand dog"
    string getPath(const string& s, const vector<int>& path) {
        string res;
        res.reserve(s.size() + path.size() - 2);  // path.size()>=2
        for (int i = 0; i + 2 < (int)path.size(); ++i) {
            res.append(s.substr(path[i], path[i + 1] - path[i]));
            res.append(" ");
        }
        res.append(s.substr(path[path.size() - 2]));
        return res;
    }
    
    void dfs(const string& s, const vector<vector<int>>& dp,
             vector<string>& res, vector<int>& path) {
        int i = path.back();
        if (i == s.size()) {  // 完成一条路径
            res.emplace_back(getPath(s, path));
        } else {  // 找到下一个分割点
            for (int inext : dp[i]) {
                path.emplace_back(inext);
                dfs(s, dp, res, path);
                path.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<int> wordlen;  // 字典中单词的所有可能长度
        for (auto& word : dict)
            wordlen.emplace(word.size());
        
        int n = s.size();
        vector<vector<int>> dp(n + 1);
        dp[n].emplace_back(0);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int len : wordlen) {
                if (i + len <= n
                    && !dp[i + len].empty()
                    && dict.find(s.substr(i, len)) != dict.end()) {
                    dp[i].emplace_back(i + len);
                }
            }
        }
        
        // DFS寻找所有路径
        vector<string> res;
        vector<int> path = {0};
        dfs(s, dp, res, path);
        return res;
    }
};