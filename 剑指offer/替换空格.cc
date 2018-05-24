/**
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.
 * 则经过替换之后的字符串为We%20Are%20Happy。
 */
class Solution {
public:
	// 就地改变，由于字符串变长，所以采用copy_backward的方式(从后到前)
	void replaceSpace(char *str,int length) {
        int nBlank = 0;
        for (int i = 0; i < length; ++i)
            if (str[i] == ' ')
                ++nBlank;
        int newlength = length + nBlank * 2;
        char* p = str + newlength;
        for (char* q = str + length; p >= str; --q) {
            if (*q != ' ') {
                *p-- = *q;
            } else {
                *p-- = '0';
                *p-- = '2';
                *p-- = '%';
            }
        }
	}
	
/*	void replaceSpace(char *str,int length) {
        // 计算空格数
        int nSpace = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ')
                nSpace++;
        }
        // 构造临时字符串
        std::string strcopy(str, length);
        int j = 0;
        for (int i = 0; i < length; i++) {
            if (strcopy[i] != ' ') {
                str[j] = strcopy[i];
                j++;
            } else {
                str[j] = '%';
                str[j + 1] = '2';
                str[j + 2] = '0';
                j += 3;
            }
        }
	}*/
};