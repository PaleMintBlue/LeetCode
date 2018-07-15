class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push(x);
        if(minStack.empty())
            minStack.push(x);
        else
        {
            if(x<minStack.top())
                minStack.push(x);
            else
                minStack.push(minStack.top());
        }
    }
    
    void pop() {
        if(stack.empty()||minStack.empty())
            return;
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    std::stack<int> stack;
    std::stack<int> minStack;
};

class MinStack
{
public:
    MinStack()
    {

    }
    void push(int x) {
        if(stack.empty())
        {
            stack.push(0L);
            min = x;
        }else
        {
            stack.push(x-min); //Could be negative if min value needs to change
            if(x<min)
                min = x;
        }
    }
    
    void pop() {
        if(stack.empty())
            return;
        long top = stack.top();
        stack.pop();
        if(pop<0)
            min = min - pop;
    }
    
    int top() {
        long top = stack.top();
        if(top>0)
            return static_cast<int>(top+min);
        else
            return static_cast<int>(min);
    }
    
    int getMin() {
        return static_cast<int>(min);
    }

private:
    std::stack<long> stack;
    long min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */