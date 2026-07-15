class Solution {
public: 
  int GCDcal(int a, int b) {
   while(b!=0){
    int temp=a%b;
    a=b;
    b=temp;
   }
   return a;
}
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;
        int i=1;
        int temp=n;
        while(n!=0){
            if(i%2==1){
                sumOdd+=i;
                n--;
            }
            i++;
        }
        int j=2;
        while(temp!=0){
            if(i%2==0){
                sumEven+=j;
                temp--;
            }
            j+=2;
        }
        return GCDcal(sumOdd,sumEven);
    }
};