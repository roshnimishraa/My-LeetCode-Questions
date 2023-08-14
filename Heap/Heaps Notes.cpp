Binary Heap is used in 
1. Heap Sort 
2. to implement priority queue 

-> Binary heap is a complete binary tree stored as an array 
Complete binary tree - A binary tree which is completely filled except possibly the last level it is filled from left to right

-> Merge Sort and Quick Sort are faster than heap sort 

Priority queue operations
1. push(val) 
2. pop()
3. empty()
4.size()
5. top()

  Short hand representation of 
priority_queue<int,vector<int>,greater<int>> pq;

typedef pair<int, int> pi;
 priority_queue<pi, vector<pi>, greater<pi> > pq;


Min Heap :  Decreasing order sorting
priority_queue<int,vector<int>,greater<int>> pq;

to sort in descendig order 
 sort(arr.begin(),arr.end(),greater<int>());

Identification of Heap Questions 
1. k 
2. smallest/largest 

  given, 
  k + largest -> use Min Heap 
  k + smallest -> use Max Heap 

