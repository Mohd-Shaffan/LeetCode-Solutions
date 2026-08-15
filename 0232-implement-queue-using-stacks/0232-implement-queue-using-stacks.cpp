class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    
    MyQueue() {
        
        
    }
    
    void push(int x) {
        st.push(x);
        
    }
    
    int pop() {
        if(st.size()==0) return -1;
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        helper.pop();
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() {
        if(st.size()==0) return -1;
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st.size()==0) return true;
        return false;
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