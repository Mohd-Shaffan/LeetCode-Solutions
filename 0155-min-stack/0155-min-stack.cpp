class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {}
    
    void push(int val) {
        long long x = val;
        if (st.empty()) {
            mini = x;
            st.push(x);
        } else if (x >= mini) {
            st.push(x);
        } else {
            // Encoded value push karo
            st.push(2 * x - mini);
            mini = x; // Update minimum
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        long long topVal = st.top();
        st.pop();
        
        // Agar popped element current mini se chhota tha, 
        // toh matlab ye encoded val thi -> purana mini restore karo
        if (topVal < mini) {
            mini = 2 * mini - topVal;
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        
        long long topVal = st.top();
        if (topVal < mini) {
            return mini;
        }
        return topVal;
    }
    
    int getMin() {
        return mini;
    }
};