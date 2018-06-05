// 101ms 44.51%
class Solution {
public:
    string intToRoman(int num) {
        static const char* symbols[][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        string s;
        s += symbols[3][num / 1000];  // num范围是1~3999，所以num/1000为0~9
        s += symbols[2][(num / 100) % 10];
        s += symbols[1][(num / 10) % 10];
        s += symbols[0][num % 10];
        return s;
    }
};

// 104ms 36.09%  没利用冗余字符构成的字符串数组，直接一步步做
class Solution {
public:
    void intToRoman(string& s, int digit, const char* p) {
        char one = *p;
        if (digit >= 5) {
            ++p;
			s += *p;
            digit -= 5;
        }
        if (digit < 4) {
            for (int i = 0; i < digit; ++i)
                s += one;
        } else {
			if (*p != one)  // digit == 9
				s.back() = one;
			else  // digit == 4
				s += one;
            s += *(p + 1);
        }
    }

    string intToRoman(int num) {  // num: 1~3999
        const int power_10[] = {1, 10, 100, 1000};
        const char* symbols = "IVXLCDM";
        
        string s;
        const int* pi = power_10 + 3;
        const char* ps = symbols + 6;

        while (num > 0) {
            intToRoman(s, num / *pi, ps);
            num %= *pi;
            --pi;
            ps -= 2;
        }
        return s;
    }
};