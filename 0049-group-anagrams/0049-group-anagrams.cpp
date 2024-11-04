class Solution {
public:
//   bool isAnagram(string s, string t) {
// if(s.size()!=t.size()) return false;
// int hashans[26]={0};
// for(int i=0;i<s.size();i++){
//     hashans[s[i]-'a']++;
// }
// for(int i=0;i<t.size();i++){
//     hashans[t[i]-'a']--;
// }
// for(int i=0;i<26;i++){
//       if(hashans[i]!=0){
//         return false;
//       }
// }
// return true;
//     }
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
                map<string,vector<string>>mp;
                for(auto it:strs){
                    string s=it;
                    sort(s.begin(),s.end());
                    mp[s].push_back(it);
                }
                 vector<vector<string>>ans;
                for(auto it=mp.begin();it!=mp.end();it++){
                   ans.push_back(it->second);
                }
                 return ans;











        // vector<vector<string>> ans;
        // for(int i=0;i<strs.size();i++){
        //     string current=strs[i];
        //     for(int i=0;i<strs.size();i++){
        //         if(strs[i]!=current){
        //      if(isAnagram(current,strs[i])){
        //         ans.push_back(current);
        //         ans.push_back(strs[i]);
        //      }
        //      else ans.push_back([current]);
        //         } 
        //     }
        // }
        // return ans;
    }
};