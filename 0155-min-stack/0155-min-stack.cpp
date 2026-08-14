class MinStack {
public:
    stack<int> st;
    stack<int> helper;
    MinStack() {
        
    }
    
    void push(int value) {
        if(!helper.empty() && value>helper.top()) helper.push(helper.top());
        else{
            helper.push(value);
        }
        st.push(value);
        

        
    }
    
    void pop() {
        st.pop();
        helper.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */