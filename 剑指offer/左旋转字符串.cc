/**
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
 */
class Solution {
public:
    // 考点是STL的rotate算法，O(1)空间复杂度
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if (len == 0)
            return "";
        if (n >= 0)
            n %= len;
        else
            n = (n % len) + len;
        // 下列3种方法任选其一
        //rotate(str.begin(), str.begin() + n, str.end());
        //rotate_forward_iter(&str[0], &str[0] + n, &str[0] + len);
        rotate_bid_iter(&str[0], &str[0] + n, &str[0] + len);
        return str;
    }
    
    // 双向迭代器的rotate算法: 对"01234abc"变成"abc01234"步骤如下
    // 逆置"01234"和"abc"得到"43210cba"，然后整个逆置即可
    void rotate_bid_iter(char* s_beg, char* s_mid, char* s_end) {
        reverse(s_beg, s_mid);
        reverse(s_mid, s_end);
        reverse(s_beg, s_end);
    }
    
    // 前向迭代器的rotate算法: 对"01234abc"变成"abc01234"步骤如下
    // 交换"012"和"abc"得到"abc34012"，此时相当于对"34012"进行同样的
    // rotate操作，把34移动到012后面，因此可以递归完成
    void rotate_forward_iter(char* s_beg, char* s_mid, char* s_end) {
        if (s_beg == s_mid || s_mid == s_end)
            return;
        char* p1 = s_beg;
        char* p2 = s_mid;
        while (p1 != s_mid && p2 != s_end) {
            iter_swap(p1++, p2++);
        }
        if (p1 != s_mid)
            rotate_forward_iter(p1, s_mid, s_end);
        else if (p2 != s_end)
            rotate_forward_iter(s_mid, p2, s_end);
    }
};