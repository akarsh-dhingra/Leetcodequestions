class Solution {
public:
    string smallestSubsequence(string s) {
        string res="";
        int n=s.size();
        vector<bool>seen(26,false);
        vector<int>mpp(26,0);
        for(int i=0;i<s.size();i++){
            mpp[s[i]-'a']=i;
        }
        stack<int>st;
        for(int i=0;i<n;i++){
            char curr=s[i];
            if(seen[curr-'a']) continue;
           else{
           while(st.size()>0&&st.top()>s[i]&&i<mpp[st.top()-'a']){
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]-'a']=true;
           }
        }
        // duplicate removal can occur only If I know 
        // that there are more occurences of a particular character in front
        // the easiest way for that is if I someHow know last Occurence of each cahar
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};