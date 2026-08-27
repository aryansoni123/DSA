class MinStack {
    stack<long long> st;
    long long mini = INT_MAX;
    // queue<int> q;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        } else{
            if(value>=mini) st.push(value);
            else{
                long long val = 2*(long long)value - mini;
                mini = value;
                st.push(val);
            }
        }
    }
    
    void pop() {
        long long x = st.top();
        st.pop();

        if(x<mini){
            mini = 2*mini - x;
        }
    }
    
    int top() {
        long long x = st.top();

        if(x<mini){
            return mini;
        }
        if(x>INT_MAX) return INT_MAX;
        if(x<INT_MIN) return INT_MIN;

        return x;
    }
    
    int getMin() {
        long long x = mini;
        
        if(x>INT_MAX) return INT_MAX;
        if(x<INT_MIN) return INT_MIN;

        return mini;
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