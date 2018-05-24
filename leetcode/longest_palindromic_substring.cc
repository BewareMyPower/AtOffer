class Solution {
public:
    // 先求s和reverse(s)的最长公共子串，若两个子串所处的位置刚好匹配则为最长回文串
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        string rs = s;
        reverse(rs.begin(), rs.end());
        vector<vector<int>> dp(n, vector<int>(n));  // dp[i][j]分别为s1[0..i]和s2[0..j]的最长公共后缀长度
        for (int i = 0; i < n; ++i) {
            dp[0][i] = (s[0] == rs[i]) ? 1 : 0;
            dp[i][0] = (s[i] == rs[0]) ? 1 : 0;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = (s[i] == rs[j]) ? (dp[i - 1][j - 1] + 1) : 0;
            }
        }
        int xi = 0, xj = 0, maxlen = 0;  // dp[xi][xj]为最大值maxlen
        // rs[j-maxlen+1]对应s[(n-1)-(j-maxlen+1)]，即i + j - maxlen + 1 == n - 1时两子串位置对应
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maxlen < dp[i][j] && (i + j - dp[i][j] + 2 == n)) {
                    maxlen = dp[i][j];
                    xi = i;
                    xj = j;
                }
            }
        }
        return s.substr(xi + 1 - maxlen, maxlen);  // 注意计算子串左边界时要加1
    }
};