class SmallestInfiniteSet {
public:
    vector<bool>nums;
    int i;
    SmallestInfiniteSet() {
        // It initializes the SmallestInfiniteObject set to contain 
        // all positive integers 
    nums=vector<bool>(1001,true);
    i=1;
    }
    
    int popSmallest() {
        // Removes and returns the smallest positive integer.
        int result =i;
        nums[i]=false;
        // Don't do i++ instead
        for(int j=i+1;j<=1000;j++){
            if(nums[j]==true){
                i=j;
                break;
            }
        }
        return result;
    }
    
    void addBack(int num) {
        // Adds a positive integer num back into the infinite set
        nums[num]=true;
        if(num<i){
           i=num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */