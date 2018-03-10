/**
 * 每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
 * HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
 * 首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
 * 每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
 * 从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
 * 可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
 * 请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
 */
class Solution {
public:
    // 假设从0..n-1中剔除k, 那么新ID到旧ID的映射关系如下
    // 0:k+1 1:k+2 ... n-k-2:k-1
    // n-k-1:0 n-k:1 ... k-1:n-1
    // 可以看出oldid = (newid + k + 1) % n
    // 因此设f(n,m)为n个数字的序列中最后剩下的数字，则
    // f(n-1,m)可以看成0..n-1中剔除k后的新ID，因此有
    // f(n,m) = oldid = (f(n-1,m) + k + 1) % n，f(1,m)=0
    int LastRemaining_Solution(int n, int m)  // n>1,m>=1
    {
        if (n <= 0 || m <= 0)
            return -1;
        int res = 0;  // f(1,m)
        for (int i = 2; i <= n; ++i)
            res = (res + m) % i;
        return res;
    }

    // 用数组来模拟循环链表，next[i]即下个小朋友的编号
/*    int LastRemaining_Solution(int n, int m)  // n>1,m>=1
    {
        if (n <= 0 || m <= 0)
            return -1;
        vector<int> next(n);
        iota(next.begin(), next.end() - 1, 1);
        next[n - 1] = 0;
        vector<int> prev(n);
        iota(prev.begin() + 1, prev.end(), 0);
        prev[0] = n - 1;
        
        int nFirst = 0;  // 第1个报数的小朋友编号
        int nLeft = n;  // 剩余小朋友的数量
        while (n > 1) {
            int nPos = (m - 1) % n;
            for (int i = 0; i < nPos; i++) {
                nFirst = next[nFirst];
            }
            // 从链表中删除当前结点
            int i_prev = prev[nFirst];
            int i_next = next[nFirst];
            next[i_prev] = i_next;
            prev[i_next] = i_prev;
            nFirst = i_next;
            n--;
        }
        return nFirst;
    }*/
};