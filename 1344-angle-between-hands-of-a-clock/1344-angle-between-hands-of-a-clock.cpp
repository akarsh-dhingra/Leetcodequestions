class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle=(hour %12)*30 +minutes*0.5;
        double minAngle=6*minutes;

        double diff=abs(hourAngle-minAngle);
        return min(diff,360-diff);
    }
};