class Solution {
public:
    // 手动实现STL的next_permutation
    bool NextPermutation(string& s) {
            size_t n = s.size();
        if (n < 2)
            return false;
        size_t i = n - 1;
        while (i > 0 && s[i - 1] >= s[i])
            i--;
        // a[i..n)为右边最大递减序列
        if (i == 0) {
                reverse(s.begin(), s.end());
            return false;
        }
        size_t j = n - 1;
        while (j >= i && s[j] <= s[i - 1])
            j--;
        swap(s[i - 1], s[j]);
        reverse(s.begin() + i, s.end());
        return true;
    }

    vector<string> Permutation(string str) {
        if (str.empty())
            return {};
        sort(str.begin(), str.end());
        vector<string> v;
        do {
            v.push_back(str);
        } while (NextPermutation(str));
        return v;
    }
};
