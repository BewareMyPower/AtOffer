/**
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
 * 每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
 * 因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 */
class Solution {
    int threshold;
    int rows;
    int cols;
    vector<vector<int>> visited;  // visited[i][j]为0代表未访问过
public:
    // 计算x的数位之和，比如35的数位之和为3+5=8
    int getDigitSum(int x) {
        int res = 0;
        while (x > 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    
    // 判断(r,c)的数位之和是否能到达(即不大于threshold)
    bool canReach(int r, int c) {
        return getDigitSum(r) + getDigitSum(c) <= threshold;
    }
    
    // 当前位置(r,c)，若可访问则尝试往四个方向移动
    void movingCount(int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return;
        if (visited[r][c] == 0 && canReach(r, c)) {
            visited[r][c] = 1;
            movingCount(r + 1, c);
            movingCount(r - 1, c);
            movingCount(r, c + 1);
            movingCount(r, c - 1);
        }
    }
    
    int movingCount(int _threshold, int _rows, int _cols)
    {
        threshold = _threshold;  rows = _rows;  cols = _cols;
        visited.resize(rows, vector<int>(cols, 0));
        
        movingCount(0, 0);
        return accumulate(visited.cbegin(), visited.cend(), 0,
            [](int x, const vector<int>& v) {
                return x + count_if(v.cbegin(), v.cend(), [](int x) { return x > 0; });
            });
    }
};