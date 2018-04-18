/**
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 */
class Solution {
public:
    // 扫描p开始的整数部分，若1位数字也没有则返回false
    bool scanInteger(char*& p) {
        if (!isdigit(*p))
            return false;
        while (isdigit(*p))
            ++p;
        return true;
    }
    
    bool isNumeric(char* string)  // 假设首尾空格已经去掉
    {
        // 判断是否有正负号
        if (*string == '+' || *string == '-')
            ++string;
		// 后面的组成方式
        if (scanInteger(string)) {
            if (*string == '.')
                scanInteger(++string);
        } else {
            if (*string != '.' || !scanInteger(++string))
                return false;
        }
        if (*string == '\0')
            return true;
        if (*string == 'e' || *string == 'E') {
            ++string;
            if (*string == '+' || *string == '-')
                ++string;
            if (!scanInteger(string))
                return false;
            return *string == '\0';
        }
        return false;
    }
};