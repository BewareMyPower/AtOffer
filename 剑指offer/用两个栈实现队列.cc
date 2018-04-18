class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            if (stack1.empty())
                throw std::runtime_error("empty queue!");
            while (!stack1.empty()) {
                int x = stack1.top();
                stack1.pop();
                stack2.push(x);
            }
        }
        
        int x = stack2.top();
        stack2.pop();
        return x;
    }

private:
    stack<int> stack1;  // 临时存储逆序队列(先入在下，后入在上)
    stack<int> stack2;  // 存放队列顺序(先入在上，后入在下)
};