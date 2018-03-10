class Solution {
public:
    // S = x+(x+1)+...+(x+n-1)=n(x + (n-1)/2)
    // x = (2*S/n - (n-1)) / 2，其中x为开始数字，n为序列大小
    // 1. 判断2*S是否能被n整除；
    // 2. 判断2*S/n是否大于n-1;
    // 3. 求解x是否为正整数
    // 细节: 序列间按开始数字从小到大排序，等价于按n从大到小排序
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum <= 0)
            return res;
        for (int n = 2; ; n++) {  // n为序列数量
            int diff = 2 * sum / n - (n - 1);
            if (diff <= 0)  // n越大diff越小，不必继续判断
                break;
            if ((2 * sum) % n != 0 || diff % 2 != 0)
                continue;
            int x = diff / 2;
            vector<int> v(n);
            iota(v.begin(), v.end(), x);
            res.push_back(v);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};