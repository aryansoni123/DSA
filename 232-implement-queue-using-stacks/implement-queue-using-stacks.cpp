class MyQueue {
    stack <int> st1;
    stack <int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {

        int n = st1.size(); 
        
        while(n){
            st2.push(st1.top());
            st1.pop();
            n--;
        }

        st1.push(x);

        n = st2.size();

        while(n){
            st1.push(st2.top());
            st2.pop();
            n--;
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();

        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.size() == 0;
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