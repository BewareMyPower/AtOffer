class Solution {
public:
    // 定义中间若干个相同字符看成回文串的中心，比如"abcxxxcba"的中心是xxx
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) return s;
        int max_left = 0, max_right = 0, maxlen = 0;
        // 判断start + maxlen / 2 < len的原因在于，先通过start求得中心，然后分别向左和向右扩展相同多的字符
        // 所以start左边和右边至少有maxlen/2个字符，才可能最后构造的回文子串长度大于maxlen
        for (int start = 0; start < len && start + maxlen / 2 < len; ++start) {
            int left = start;
            int right = start;
            while (right + 1 < len && s[right] == s[right + 1])
                ++right;  // 此时s[left..right]为相同字符组成的子串
            // 分别向左和向右扩展
            while (left > 0 && right + 1 < len && s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            }
            if (maxlen < right - left + 1) {
                maxlen = right - left + 1;
                max_left = left;
                max_right = right;
            }
        }
        return s.substr(max_left, maxlen);
    }
};