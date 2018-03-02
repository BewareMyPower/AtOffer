/**
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
 * 序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
 * 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
 */
 
class Solution {
public:
    // 思路: 建立辅助栈stk模拟真实的出栈情况
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 假设序列不包含重复元素!!!
        int n = pushV.size();
        if (n == 0 || n != (int)popV.size())
            return false;
        
        vector<int> stk;
        for (int i = 0, j = 0; i < n; ) {  // popV[j]为当前弹出元素
            stk.push_back(pushV[i++]);
            // 按照popV的顺序依次出栈
            while (j < n && !stk.empty() && stk.back() == popV[j]) {
                j++;
                stk.pop_back();
            }
        }
        
        return stk.empty();
    }

	/*
    int findVal(int x, const vector<int>& v, int n) {
        for (int i = 0; i < n; ++i) {
            if (v[i] == x)
                return i;
        }
        return -1;
    }
    
	// 思路: 对pushV={1,2,3,4,5}和popV={4,5,3,2,1}的输入而言
	// 第一步: 先找到4在pushV的下标(3)，因此4在弹出时，1,2,3均已入栈
	// 因此1,2,3在popV中的先后顺序必须是3->2->1
	// 第二步: 到5在pushV的下标(4)，注意，由于4比5先出栈，所以5出栈时4不在栈中
	// 所以第一步中必须设置4已经被访问过来排除。
	// 同理，刚才1,2,3的相对顺序已经确认过，所以也无需重新确认。
	// 重复第二步直到遍历完popV即可。
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 假设序列不包含重复元素!!!
        int n = pushV.size();
        std::unordered_set<int> vis_set;  // 已访问的元素集合
        auto visited = [&](int x) { return vis_set.count(x) > 0; };
        auto set_vis = [&](int x) { vis_set.emplace(x); };
        
        for (int i = 0; i < n; ++i) {
            if (visited(popV[i]))
                continue;
            int k = findVal(popV[i], pushV, n);
            if (k == -1)
                return false;
            set_vis(pushV[k]);
            
            int nEnd = n;
            for (int j = 0; j < k; ++j) {
                int x = pushV[j];
                if (visited(x))
                    continue;
                
                int nEndTemp = findVal(x, popV, nEnd);
                if (nEndTemp == -1 && !visited(popV[nEndTemp]))
                    return false;
                
                set_vis(x);
                nEnd = nEndTemp;
            }
        }
        
        return true;
    }
	*/
};