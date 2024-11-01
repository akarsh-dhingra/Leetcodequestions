class Solution {
public:
static string str;
static bool compare(char chara,char charb){
return (str.find(chara)<str.find(charb));
}
    string customSortString(string order, string s) {
      str=order;
      sort(s.begin(),s.end(),compare);
      return s;
    }
};
string Solution::str;