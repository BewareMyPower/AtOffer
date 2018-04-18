class Solution {
public:
    // f(1)=1 f(2)=2
    // f(n) = f(n-1)+f(n-2)
    // 1. 竖着放1个，还剩n-1列
    // 2. 横着放2个，还剩n-2列
    int rectCover(int number) {
        int n = number;
        if (n <= 0)  // 边界检查
            return 0;
        std::vector<int> v(n);  // 对空间要求不大时使用
        v[0] = 1;
        v[1] = 2;
        for (int i = 2; i < n; i++)
            v[i] = v[i - 1] + v[i - 2];
        return v[n - 1];
    }
};