class Solution {
public:
   static bool mycomp(string&a,string&b){
    return a<b;
   }
    vector<int> lexicalOrder(int n) {
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i+1;
        }
        vector<string>an(n);
        for(int i=0;i<n;i++){
            an[i]=to_string(ans[i]);
        }
        sort(an.begin(),an.end(),mycomp);
         for(int i=0;i<n;i++){
            ans[i]=stoi(an[i]);
        }    
        return ans;
    }
};