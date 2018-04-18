/**
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 * 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
 * 例如下列矩阵
 * a b c e
 * s f c s
 * a d e e 
 * 中包含一条字符串"bcced"的路径，但是不包含"abcb"路径，
 * 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
 */
class Solution {
    const char* matrix;
    int rows;
    int cols;
    vector<vector<int>> flags;  // flags[i][j]为0则代表未走过(i,j)，否则代表走过
public:
    // 从4个方向递归求解, (r,c)为当前点的坐标
    bool hasPath(int r, int c, char* str) {
        if (*str == '\0')  // 注意这句必须放在开头，因为可能当前点越界了但是已经匹配完毕了
            return true;
        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return false;
        if (flags[r][c] != 0 || matrix[r * cols + c] != *str)
            return false;
        // 当前点未访问过，且和str匹配，从4个方向继续寻找
        flags[r][c] = 1;  // 设置标记已访问
        if (hasPath(r + 1, c, str + 1) ||
            hasPath(r - 1, c, str + 1) ||
            hasPath(r, c + 1, str + 1) ||
            hasPath(r, c - 1, str + 1))
            return true;
        else {
            flags[r][c] = 0;
            return false;   
        }
    }
    
    bool hasPath(char* _matrix, int _rows, int _cols, char* str)
    {
        matrix = _matrix;  rows = _rows;  cols = _cols;
        if (!matrix || rows < 1 || cols < 1 || !str)
            return false;
        
        // 从所有点分别出发，查看是否有路径
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                flags.resize(rows, vector<int>(cols, 0));
                if (hasPath(r, c, str))
                    return true;
            }
        }
        return false;
    }
};