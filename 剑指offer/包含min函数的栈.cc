/**
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
 */
class Solution {
public:
    void push(int value) {
        _data.push(value);
        
        // 注意判断空栈
        if (_min.empty() || value < _min.top())
            _min.push(value);
        else
            _min.push(_min.top());
    }
    void pop() {
        _data.pop();
        _min.pop();
    }
    int top() {
        return _data.top();
    }
    int min() {
        return _min.top();
    }
    
    std::stack<int> _data;
    std::stack<int> _min;  // _min[i]为_data[0..i]的最小值
};