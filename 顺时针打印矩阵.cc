/**
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
 * 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int h = matrix.size();
        if (h == 0)
            return {};
        int w = matrix[0].size();
        int h0 = 0;
        int w0 = 0;
        
        vector<int> res;
        res.reserve(h * w);
        auto& m = matrix;
        while (true) {
            // 注意每走一行都要判断1次边界条件!
            for (int i = w0; i < w; ++i)
                res.push_back(m[h0][i]);
            if (++h0 >= h)
                break;
            for (int i = h0; i < h; ++i)
                res.push_back(m[i][w - 1]);
            if (w0 >= --w)
                break;
            for (int i = w - 1; i >= w0; --i)
                res.push_back(m[h - 1][i]);
            if (h0 >= --h)
                break;
            for (int i = h - 1; i >= h0; --i)
                res.push_back(m[i][w0]);
            if (++w0 >= w)
                break;
        }
        return res;
    }
};