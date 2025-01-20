class StockSpanner {
  stack<pair<int,int>>st;
  int indx;
  vector<int>ans;
public:
    StockSpanner() {
indx=-1;
    }
    
    int next(int price) {
    // i have to keep a track of all elements passing
    // stack<int>st;
    // st.push(price);
//     ans.push_back(price);
//     int cnt=1;
//     for(int i=ans.size()-2;i>=0;i--){
//     if(ans[i]<=price){
//     cnt+=1;
//     }
//     else break;
//     }
indx=indx+1;
int actualans=0;
while(!st.empty()&&st.top().first<=price){
    st.pop();
}
int answ=indx-(st.empty()?-1:st.top().second);
ans.push_back(answ);
st.push({price,indx});
return answ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */