Efficient Approach : Using Priority Queue 
How to find Median 
1. Element should be in sorted order
2. If n = even  
  take two middle element find the average of these two elements
3. If n = odd 
   take middle element as answer 

Eg. arr[] = {3, 4, 5, 8, 9, 10} n=6
1. Take two middle element for that 
Divide the array into first half and second half 
first half = 3 4 5
second half = 8 9 10 
a) Consider first half -> Max heap (because of 5) -> 5 4 3 
b) Consider second half -> Min Heap (because of 8) -> 8 9 10 

2. take two top elements (5 + 8)/2 = 6.5

Eg. arr[] = {3, 4 , 5, 8, 9}  n=5
  left_Max_Heap = 5 4 3 
  right_Max_Heap = 8 9 
ans = left_Max_Heap top = 5 

class MedianFinder {
public:
    priority_queue<int> left_max_heap; // max heap 
  priority_queue<int,vector<int>,greater<int>> right_min_heap; // min heap
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top())
        {
            left_max_heap.push(num);
        }
    else{
        right_min_heap.push(num);
    }
        
//always maintain left_max_heap size is one greater than right_min_heap
// or both heap size should be equal 
    
if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1)
{
    right_min_heap.push(left_max_heap.top());
    left_max_heap.pop();
}
else if(left_max_heap.size() < right_min_heap.size())
{
    left_max_heap.push(right_min_heap.top());
    right_min_heap.pop();
}
        
    }
    
    double findMedian() {
       if(left_max_heap.size() == right_min_heap.size())
       {
           //if n = even 
   double mean = ((double)left_max_heap.top() + (double)right_min_heap.top())/2;
           return mean;
 }
        else{
            // n = odd 
    return left_max_heap.top();
        }
    }
};



