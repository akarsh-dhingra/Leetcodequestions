class MinStack {
    
public:
vector<pair<int,int>>v;
    MinStack() {

    }
    void push(int val) {
   if(v.empty()){
    // entering the element for the first time.
    pair<int,int>p;
    p.first=val;
    p.second=val;
    v.push_back(p);
   }
else{
    pair<int,int>p2;
p2.first=val;
int puranamin=v.back().second;
p2.second=min(puranamin,val);
v.push_back(p2);
        }
        }
    
    void pop() {
 v.pop_back();
    }
    int top() {
        pair<int,int>rightmostpair=v.back();
        return rightmostpair.first;

    }
    int getMin() {
        pair<int,int>rightmostpair=v.back();
        return rightmostpair.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */