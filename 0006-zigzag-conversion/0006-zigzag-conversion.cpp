class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string>ans(numRows);
        int i=0;
        int row=0; // Check help in changing of row while going from bottom to top 
        // and again from top to bottom
        bool direction=true; // top to Bottom
        while(true){
            if(direction){
                while(row<numRows&&i<s.length()){
                    ans[row].push_back(s[i]);
                    row++;
                    i++;
                }
                // if row ==numrows
                row=numRows-2;
            }
            else{
                while(row>=0&&i<s.length()){
                    ans[row].push_back(s[i]);
                    row--;
                    i++;                   
                }
                row=1;
            }
            if(i>=s.length()) break;
            direction=!direction;
        }
        string res="";
        for(int i=0;i<ans.size();i++){
            res+=ans[i];
        }
        return res;
    }
};