/**
 * 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 */
class Solution {
	// PS: 可以使用静态变量和构造函数去做，但是静态变量必须定义在源文件中
public:
	// 利用or运算短路特性
	int Sum_Solution(int n) {
        int res = 0;
        (n == 0) || (res = res + n + Sum_Solution(n - 1));
        return res;
    }

/*    using Func = int(Solution::*)(int);
    int Sum_Term(int n) { return 0; }
    
    // 对非0整数n，!n为0，而!0为1，因此!!n对非0整数为0，对0为1
    int Sum_Solution(int n) {
        static Func f[2] = {&Solution::Sum_Term, &Solution::Sum_Solution};
        static Solution sol;
        return n + (sol.*f[!!n])(n - 1);
    }*/
};