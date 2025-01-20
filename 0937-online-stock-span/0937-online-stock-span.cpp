class StockSpanner {
    vector<int>ans;
public:
    StockSpanner() {

    }
    
    int next(int price) {
    // i have to keep a track of all elements passing
    // stack<int>st;
    // st.push(price);
    ans.push_back(price);
    int cnt=1;
    for(int i=ans.size()-2;i>=0;i--){
    if(ans[i]<=price){
    cnt+=1;
    }
    else break;
    }
return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */