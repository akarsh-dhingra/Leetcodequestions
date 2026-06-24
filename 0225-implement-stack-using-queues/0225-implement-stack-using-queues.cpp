class MyStack {
    private:
    int topIndx;
    int *arr;
    int capacity;
public:
    MyStack(int size=1000) {
        this->capacity=size;
        this->topIndx=-1;
        arr=new int[capacity];
    }
    
    void push(int x) {
        if(topIndx>999){
            cout<<"Stack Overflow";
            return;
        }
        topIndx++;
        arr[topIndx]=x;
    }
    
    int pop() {
        if(empty()) return -1;
        return arr[topIndx--];
    }
    
    int top() {
        return arr[topIndx];
    }
    
    bool empty() {
        if(topIndx==-1) return true;
        else return false;
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