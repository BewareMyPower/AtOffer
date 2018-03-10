/**
 * 例如，“student. a am I”。
 * 正确的句子应该是“I am a student.”。
 */
class Solution {
public:
    // 翻转每个单词(被空格分开的字符串)，然后整个翻转
    string ReverseSentence(string str) {
        char* p = &str[0];
        int n = str.size();
        auto word_beg = p;
        while (word_beg != p + n) {
            auto word_end = find(word_beg, p + n, ' ');
            reverse(word_beg, word_end);
			
            word_beg = find_if(word_end, p + n,
                [](char ch) { return ch != ' '; });
        }
        reverse(p, p + n);
        return str;
    }
};