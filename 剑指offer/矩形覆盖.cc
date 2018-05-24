class Solution {
public:
    // 扩展到k*1的小矩形填充k*n的大矩形
    // 1.第一个小矩形竖着放，后续问题为f(n-1)
    // 2.第一个小矩形横着放，那么第1~k列都只能由横着的矩形填充，后续问题为f(n-k)
    // f(n) = f(n-1) + f(n-k)
    int rectCover(int n, int k) {
        vector<int> v(k + 1, 1);  // v[0]无意义
        v[k] = 2;
        if (n <= k) return v[n];
        n -= k;
        vector<int> temp(k + 1, 1);
        for (; n >= k; n -= k) {
            temp[0] = v[k];  // 方便后续操作
            for (int i = 1; i <= k; ++i)
                temp[i] = v[i] + temp[i - 1];
            v.swap(temp);
        }
        if (n == 0) return v[k];
        temp[0] = v[k];
        for (int i = 1; i <= n; ++i)
            temp[i] = v[i] + temp[i - 1];
        return temp[n];
    }
    
    int rectCover(int n) {  // 测试用例n>0
        if (n == 0) return 0;
        return rectCover(n, 2);
    }
};