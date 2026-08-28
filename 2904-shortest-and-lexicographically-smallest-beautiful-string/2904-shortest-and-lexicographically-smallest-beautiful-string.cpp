class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();

        for(int len=k;len<=n;len++){
            string result="";
            for(int i=0;i<=n-len;i++){
                string temp=s.substr(i,len);
                if(ranges::count(temp,'1')==k){
                    if(result.empty() || temp<result){
                        result=temp;
                    }
                }
            }
            if(!result.empty()) return result;
        }
        return "";
    }
};