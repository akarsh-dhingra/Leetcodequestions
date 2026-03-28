class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result=(a|b)^c;
        int result2=(a&b);
        return __builtin_popcount(result)+__builtin_popcount(result2);
    }w
};