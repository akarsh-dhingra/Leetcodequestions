class Solution {
public:
    int convertominutes(string&time){
        // calculate hours and minutes
        int hours=stoi(time.substr(0,2));
        int minutes=stoi(time.substr(3,2));
        return hours*60+minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        // Firstly Find Minutes Corresponding to Each TimePoints:
        vector<int>minutes;
        for(auto time:timePoints){
            minutes.push_back(convertominutes(time));
        }
        // Minutes array ready
        // to find min timediff sorting is an easy technique then running O(N^2) loop
        sort(minutes.begin(),minutes.end());
        int n=minutes.size();
        // Findiing min time diff
        int minDiff=INT_MAX;
        for(int i=0;i<minutes.size()-1;i++){
            minDiff=min(minDiff,abs(minutes[i+1]-minutes[i]));
        }
        // handling edge cases: 00:00,04:00,22:00 -> 240 but ans is 1440-1320=120
        int ans=min(minutes[0]+1440-minutes[n-1],minDiff);
        // but for edge case 12:12 and 00:13
        return ans;
    }
};