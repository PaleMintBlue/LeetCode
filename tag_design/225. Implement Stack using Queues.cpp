class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue.push(x);
        for(int i = 0; i < queue.size()-1;i++)
        {
            queue.push(queue.front());
            queue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto val = queue.front();
        queue.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue.empty();
    }
private:
    std::queue<int> queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */