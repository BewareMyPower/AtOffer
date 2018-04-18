/**
 * 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
 */
class Solution {
public:
	// 手动实现hashmap的做法
    int FirstNotRepeatingChar(string str) {
        int len = (int)str.size();
        if (len == 0)
            return -1;
        // v[0]~v[25]对应a-z的值，v[26]-v[51]对应A-Z的值。值的定义如下
        // 字母出现0次: -1
        // 字母只出现1次: 字母对应字符串中的下标
        // 字母出现2次以上: len
        vector<int> v(52, -1);  
        for (int i = 0; i < len; ++i) {
            char c = str[i];
            if (!isalpha(c))
                throw runtime_error("字符串包含字母以外的字符");
            int idx = islower(c) ? c - 'a' : c - 'A' + 26;
            if (v[idx] == -1) {  // 之前未出现
                v[idx] = i;
            } else {  // 之前出现过
                v[idx] = len;
            }
        }
        int k = len;
        for (int i : v) {
            if (i != -1 && i < k)
                k = i;
        }
        return k;
    }
	
/*    int FirstNotRepeatingChar(string str) {
        int len = (int)str.size();
        if (len == 0)
            return -1;
        // um为字符和下标的映射，若字符出现2次以上，映射为-1
        unordered_map<char, int> um;
        int idx = 0;
        for (int i = 0; i < len; ++i) {
            char c = str[i];
            if (um.count(c) == 0) {
                um[c] = i;
            } else {
                um[c] = -1;
            }
        }
        // 寻找除了-1以外的最小下标
        int k = len;
        for (auto& x : um) {
            if (x.second != -1 && x.second < k)
                k = x.second;
        }
        return k;
    }*/
};