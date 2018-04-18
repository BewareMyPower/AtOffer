// a[2n+1]中位数为a[n]，a[2n]中位数为(a[n-1]+a[n])/2
// 用1个最大堆h1和1个最小堆h2来完成，两个堆的元素数量相差不超过1且最大堆顶<=最小堆顶
// 设h1的size为n1，h2的size为n2，则n1-1个元素<=最大堆顶<=最小堆顶<=n2-1个元素
class Solution {
public:
    priority_queue<int, vector<int>, less<int>> qmax;  // 最大堆
    priority_queue<int, vector<int>, greater<int>> qmin;  // 最小堆
    
    template <typename QUEUE>
    void SwapTop(QUEUE& q, int& num) {
        int temp = q.top();
        q.pop();
        q.push(num);
        num = temp;
    }
    
    void Insert(int num) {
        if (qmax.empty()) { // 第1个元素给最大堆
            qmax.push(num);
            return;
        }
        
        if (qmax.size() >= qmin.size()) {
            if (qmax.top() >= num)
                SwapTop(qmax, num);
            qmin.push(num);
        } else {
            if (num > qmin.top())
                SwapTop(qmin, num);
            qmax.push(num);
        }
    }
    
    double GetMedian() {
        if (qmax.empty())
            return 0;

        if (qmax.size() == qmin.size())
            return (qmax.top() + qmin.top()) / 2.0;
        else if (qmax.size() > qmin.size())
            return qmax.top();
        else
            return qmin.top();
    }
};