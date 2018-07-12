#include "common.h"

// 123ms 31.26%
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> um = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        // IV、IX是特殊情况，即右边字符大于左边字符
        int res = um[s.back()];  // 输入用例保证了s至少含1个字符
        for (int i = s.size() - 2; i >= 0; --i) {
            if (um[s[i]] < um[s[i + 1]])
                res -= um[s[i]];
            else
                res += um[s[i]];
        }
        return res;
    }
};

// 84ms 17.99%
static inline char* romanToIntImp(char* s, int* pNum, const char* pSym, const int* pPow10) {
    int one = *pPow10 / 10, five = *pPow10 / 2, ten = *pPow10;
    for (; *s == pSym[2]; ++s)
        *pNum += ten;
    if (*s == pSym[1]) {
        *pNum += five;
        ++s;
    }
    for (; *s == pSym[0]; ++s)
        *pNum += one;
    if (*s == pSym[1]) {
        *pNum = *pNum + five - one - one;
        ++s;
    }
    if (*s == pSym[2]) {
        *pNum = *pNum + ten - one - one;
        ++s;
    }
    return s;
}

int romanToInt(char* s) {
    const char* symbols = "IVXLCDM";
    const int power_10[] = {10, 100, 1000};
    int num = 0;
    const char* pSym = symbols + 4;
    const int* pPow10 = power_10 + 2;
    
    while (*s != '\0') {
        s = romanToIntImp(s, &num, pSym, pPow10);
        pSym -= 2;
        --pPow10;
    }
    return num;
}