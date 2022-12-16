class MyQueue {
public:
    stack<int>s, st; // s me seedha st me ulta
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s.empty())
        {
            int top = s.top();
            st.push(top);
            s.pop();
        }
        st.push(x);
        while(!st.empty())
        {
            int top = st.top();
            s.push(top);
            st.pop();
        }
    }
    
    int pop() {
        int top = s.top();
        s.pop();
        return top;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */