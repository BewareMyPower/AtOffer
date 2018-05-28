// 15ms 69.76%
class Solution {
public:
    // 判断匹配串字符c1和模式串字符c2是否相等
    bool isEqual(char c1, char c2) {
        return c1 == c2 || '.' == c2;
    }
    
    bool isMatch(string s, string p) {
        size_t m = s.size();
        size_t n = p.size();
        /**
         * dp[i][j]对应s[0..i)是否匹配p[0..j)
         * if p[j - 1] != '*'
         *     dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1])
         * if p[j - 1] == '*'，设x为p[j - 2]
         *     只有满足下列2个条件之一时dp[i][j]才为真
         *     1. dp[i][j - 2]为真："x*"匹配0次
         *     2. dp[i - 1][j]为真："x*"匹配1次以上(隐含条件: x == s[i - 1])
         */
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;  // dp[i][0] = false, i > 0
        for (int j = 1; j <= n; ++j)
            dp[0][j] = (j > 1) && p[j - 1] == '*' && dp[0][j - 2];

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && isEqual(s[i - 1], p[j - 1]);
                } else {  // p[0]不可能为'*'，因此无需检查j > 1
                    dp[i][j] = dp[i][j - 2] || (isEqual(s[i - 1], p[j - 2]) && dp[i - 1][j]);
                }
            }
        }
        
        return dp[m][n];
    }
};

// 492ms 4.83% 剑指offer的递归做法，效率低下
bool isMatch(char* s, char* p) {
    if (!p) return !s;
    if (p[0] == '\0') return s[0] == '\0';
    if (p[1] == '*') {
        if (s[0] != '\0' && (p[0] == '.' || p[0] == s[0])) {
            return isMatch(s, p + 2)  // 匹配0次
                || isMatch(s + 1, p + 2)  // 匹配1次
                || isMatch(s + 1, p);  // 匹配1次后继续匹配   
            
        } else {  // 当前字符不匹配或者s已经匹配完毕，只能匹配0次
            return isMatch(s, p + 2);
        }
    } else {
        if (s[0] != '\0' && (p[0] == '.' || p[0] == s[0]))
            return isMatch(s + 1,  p + 1);
        else
            return false;
    }
}