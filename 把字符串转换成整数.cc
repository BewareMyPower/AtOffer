/**
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
 * 数值为0或者字符串不是一个合法的数值则返回0
 */
class Solution {
public:
    int StrToInt(string str) {
        int n = str.size();
        // 剔除开始的空格字符
        int k = 0;
        while (k < n && isspace(str[k]))
            ++k;
        if (k == n)
            return 0;
        // 判断是否有正负号，默认为正
        bool is_neg = false;
        if (str[k] == '+')
            k++;
        else if (str[k] == '-') {
            k++;
            is_neg = true;
        }
        // 转换结果的绝对值上界除以10，因为不能直接和INT_MAX或INT_MIN比较
        // 比如当实际值超过INT_MAX时会产生溢出，导致int变量仍然小于INT_MAX
        // 所以需要先比较int变量是否超过INT_MAX/10，若超过则不能接受更多位
        int max_res = is_neg ? -(INT_MIN / 10) : INT_MAX / 10;
        int max_lowdigit = is_neg ? -(INT_MIN % 10) : INT_MAX % 10;
        int res = 0;
        for (; k < n; ) {
            int digit = str[k++] - '0';
            if (digit < 0 || digit > 9)
                return 0;  // 字符串不合法
            if (res < max_res)
                res = res * 10 + digit;
            else if (res > max_res)
                return 0;  // 溢出错误
            else {
                if (digit > max_lowdigit)
                    return 0;  // 溢出错误
                res = res * 10 + digit;  
                break;
            }
        }
        // 尾部若包含空格则仍然视为正确的
        for (; k < n; ++k) {
            if (!isspace(str[k]))
                return 0;  // 溢出错误或者字符串不合法
        }
        return is_neg ? -res : res;
    }
};