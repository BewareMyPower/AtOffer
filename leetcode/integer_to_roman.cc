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
        } else {  // digit == 4
			if (*p != one)
				s.back() = one;
			else
				s += one;
            s += *(p + 1);
        }
    }

	// 101ms 44.51% 该方法适应性更好，修改power_10和symbols就能适应更高位数
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

class Solution {
    // 101ms 44.51% 该方法简洁紧凑，但是需要更多冗余的额外空间
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
}