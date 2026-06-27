class MinStack {

public:
    stack<long long >st;
    long long mini;
    
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            mini=value;
            st.push(value);
        }
        else{
            if(value>=mini){
                st.push(value);
            }
            else{
                // value=10
                // mini=12
                // push 8
                st.push(2LL*value-mini);
                mini=value;
            }
        }
    }
    
    void pop() {
        // x=12
        // value=10
        if(st.empty()){
            return;
        }
        long long x=st.top();
        st.pop();
        if(x<mini){
            // x=8 
            // mini=10
            mini=2*mini-x;
        }
        
    }
    
    int top() {
        long long x=st.top();
        if(x>=mini){
            return x;
        }
        else return mini;
    }
    
    int getMin() {
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