/**题目描述
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
// 思路，对于元素a(i,j)，其左上角的一定是小于它的，右下角的一定是大于它的
// 但是对左下角和右上角的元素则无法判断次序，因此可以将a(i,j)置于右上角来判断
// 这样比a(i,j)小的一定在左边，比a(i,j)大的一定在下面
// 每次判断之后移动a(i,j)，所属行或所属列删去(因为肯定小于或大于它)，重新回到右上角
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0)
            return false;
        int rows = array.size();
        int cols = array[0].size();
        int i = 0;  // 行号
        int j = cols - 1;  // 列号
        
        while (true) {
            if (i >= rows || j >= cols || i < 0 || j < 0)
                return false;
            
            int x = array[i][j];
            if (x == target)
                return true;
            else if (x > target) {
                j--;
            }
            else { // x < target
                i++;
            }
        }
    }
};