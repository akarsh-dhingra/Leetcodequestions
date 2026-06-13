/*
Array of strings -> words
weights 26 
weight[i]=> ith 

weight[0]-> a
weight[25]-> z

weight of word represent sum of weights

weight %26 =34%26=8-> 
weight[25]-> a

weight[0]-> z 
r s t u v w x y z
*/
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string s:words){
            string x=s;
            int totalW=0;
            for(int i=0;i<x.length();i++){
                int a=x[i]-'a';
                totalW+=weights[a];
            }
            int val=totalW%26;
            char character = static_cast<char>('z'-val);
            ans+=character;
        }
        return ans;
    }
};