/**
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
 * 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
 */
class Solution {
public:
    // 令f(i,j)=a[i]*a[i+1]*...*a[j-1]，其中i<j；f(i,i)=1
    // b[i]=f(0,i)*f(i,n-1)，因此求出g(i)=f(0,i),h(i)=f(i,n-1)即可
    // g(i+1)=g(i)*A[i]  h(i-1)=h(i)*A[i]
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        if (n == 0)
            return {};
        vector<int> B(n);
        vector<int> g(n);
        vector<int> h(n);
        g[0] = 1;
        h[n - 1] = 1;
        for (int i = 1; i < n; ++i) {
            g[i] = g[i - 1] * A[i - 1];
            h[n - i - 1] = h[n - i] * A[n - i];
        }
        for (int i = 0; i < n; ++i)
            B[i] = g[i] * h[i];
        return B;
    }
};