class Solution {
public:
    // 相等于对数组按照某种方法进行排序，比如3和32就是32<3，因为323<332
    string PrintMinNumber(vector<int> numbers) {
        vector<string> v(numbers.size());
        transform(numbers.cbegin(), numbers.cend(), v.begin(),
                 [](int n) { return to_string(n); });
        auto comp = [](const string& s1, const string& s2) {
            string sum1 = s1 + s2;
            string sum2 = s2 + s1;
            return strcmp(sum1.c_str(), sum2.c_str()) < 0;
        };
        sort(v.begin(), v.end(), comp);
        string res;
        for (auto& s : v)
            res += s;
        return res;
    }
};