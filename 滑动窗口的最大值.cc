/**
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
 * 他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 * {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， 
 * {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 */
class Solution {
public:
    typedef unsigned int uint;
    // 使用一个双向队列存放当前窗口可能的最大值的下标，保证队首下标对应的元素最大
    // 比如[2,5,3],1,4中存放的是[5,3]的下标，移动到1时剔除存放[5,3,1]的下标，
    // 而移动到4时，5的下标已经不在窗口范围内，剔除5，然后4比[3,1]都大，剔除3,1加入4
	// 思路类似于习题《包含min函数的栈》
    vector<int> maxInWindows(const vector<int>& num, uint size) {
        if (num.empty() || size == 0 || size > num.size())
            return {};
        vector<int> v;
        v.reserve(num.size() - size + 1);
        
        deque<uint> idx;
        for (uint i = 0; i < size; ++i) {
            while (!idx.empty() && num[i] >= num[idx.back()])
                idx.pop_back();

            idx.push_back(i);
        }
        v.push_back(num[idx.front()]);

        for (uint i = size; i < num.size(); ++i) {
            if (idx.front() + size < i + 1)  // 窗口[i - size + 1, i]
                idx.pop_front();
            
            while (!idx.empty() && num[i] >= num[idx.back()])
                idx.pop_back();
            
            idx.push_back(i);
            v.push_back(num[idx.front()]);
        }
        return v;
    }
};