/**
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 * 而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 */
class Solution {
    bool equal(char ch_str, char ch_pattern) {
        return ch_str == ch_pattern || ch_pattern == '.';
    }
public:
    // 关键是对'*'的匹配，假设s[i]匹配p[j]，其中p[j+1]=='*'则有3种情况:
    // 1. p[j]出现0次，接下来匹配s[i]和p[j+2];
    // 2. p[j]==s[i]，s继续和'*'匹配，接下来匹配s[i+1]和p[j+1]
    // 3. p[j]==s[i]，s和'*'之后的进行匹配，接下来匹配s[i+1]和p[j+2]
    // 递归这3种情况得到的结果求AND即可
    bool match(char* str, char* pattern)
    {
        if (!str || !pattern)
            return false;
        if (*pattern == '\0')
            return *str == '\0';
        if (*str == '\0')
            return *pattern != '\0' && *(pattern + 1) == '*' && *(pattern + 2) == '\0';
        
        if (*(pattern + 1) == '*') {
            // 处理模式串的'*'时有3种可能匹配方法
            if (equal(*str, *pattern)) {
                return match(str, pattern + 2)  // 1.匹配0次
                    || match(str + 1, pattern)  // 2.匹配1次后*继续匹配
                    || match(str + 1, pattern + 2);  // 3.匹配1次后*不继续匹配
            } else {  // *只能匹配0次
                return match(str, pattern + 2);
            }
        }
        if (equal(*str, *pattern))
            return match(str + 1, pattern + 1);
        return false;
    }
	
	// 迭代结合递归的方法
/*    bool match(char* str, char* pattern)
    {
        if (!str || !pattern)
            return false;
        while (*str != '\0' && *pattern != '\0') {
            if (*(pattern + 1) == '*') {
                // 处理模式串的'*'时有3种可能匹配方法
                if (equal(*str, *pattern)) {
                    return match(str, pattern + 2)  // 1.匹配0次
                        || match(str + 1, pattern)  // 2.匹配1次后*继续匹配
                        || match(str + 1, pattern + 2);  // 3.匹配1次后*不继续匹配
                } else {  // *只能匹配0次
                    pattern += 2;
                }
            } else {
                if (!equal(*str, *pattern))
                    return false;
                ++str;
                ++pattern;
            }
        }
        if (*str == '\0') {
            return *pattern == '\0' || 
                (*(pattern + 1) == '*' && *(pattern + 2) == '\0');
        }
        return false;
    }*/
};