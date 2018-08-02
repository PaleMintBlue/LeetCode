class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) 
        :buffer(k,0),front(-1),rear(0)
    {
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())
            return false;
        if(front==-1)
        {
            // queue is initially empty
            front = 0;
            rear = 0;
        }else if(front==0)
            front = buffer.size() -1;
        else
            front = front-1;
        buffer[front] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())
            return false;
        if(front==-1)
        {
            front = 0;
            rear = 0;
        }else if(rear==buffer.size()-1)
            rear = 0;
        else
            rear = rear + 1;
        buffer[rear] = value;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
            return false;
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }else
        {
            if(front==buffer.size()-1)
                front = 0;
            else 
                front = front+1;
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }else if(rear==0)
            rear = buffer.size()-1;
        else
            rear = rear-1;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
            return -1;
        return buffer[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()||rear<0)
            return -1;
        return buffer[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front==-1;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return ((front==0&&rear==buffer.size()-1)||front==rear+1);
    }
private:
    std::vector<int> buffer;
    int front;
    int rear;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */