class Solution {
public:
    // 注意，这里不能采用传递string&然后swap后复位的方法，因为交换破坏了顺序
    // 比如"abc"，a和c交换后变成"cba"，然后递归"ba"，"ba"未排序
    // 如果每次递归对剩下的字符重新排序，那么后面的顺序变了，无法复位
    void permutation_imp(vector<string>& v, string s, int k) {
        int n = s.size();  // 这里必须n>0
        if (k + 1 == n) {
            v.push_back(s);
            return;
        }
        unordered_set<char> us;  // 已经交换过的字符
        for (int i = k; i < n; ++i) {
            if (us.count(s[i]) == 0) {
                us.emplace(s[i]);  // 注意是s[i]而非s[k]
                std::swap(s[k], s[i]);
                permutation_imp(v, s, k + 1);
            }
        }
    }
    
    vector<string> Permutation(string str) {
        sort(str.begin(), str.end());
        vector<string> res;
        if (str.size() == 0)
            return res;
        
        permutation_imp(res, str, 0);  // str.size()>0
        return res;
    }
};