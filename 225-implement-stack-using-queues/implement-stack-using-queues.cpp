class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        int n = q.size();

        q.push(x);

        while(n>0){
            int y = q.front();
            q.pop();
            q.push(y);
            n--;
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */