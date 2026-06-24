class MedianFinder {
    private:
        priority_queue<int> maxHeap;

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > minHeap;
    double median=0;
public:

int signum(int a,int b){
      if(a==b) return 0;
      else if (a>b) return 1;
      else return -1;
  }
  
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int element=num;
              switch(signum(maxHeap.size(),minHeap.size())){
        case 0: if(element>median){
                    minHeap.push(element);
                    median=minHeap.top();
                }
                else{
                    maxHeap.push(element);
                    median=maxHeap.top();
                }
                break;
        case 1: if(element>median){
                    minHeap.push(element);
                    median=(minHeap.top()+maxHeap.top())/ 2.0;
                }
                else{
                    // maxHeap-> n , minHeap ->n
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(element);
                    median=(maxHeap.top()+minHeap.top())/ 2.0;
                }
                break;
                
        case -1: if(element>median){
                    // n-1 n+1
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(element);
                    median=(maxHeap.top()+minHeap.top())/ 2.0;
                    }
                  else{
                        maxHeap.push(element);
                        median=(maxHeap.top()+minHeap.top())/ 2.0;
                    }
                break;
  }

    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */