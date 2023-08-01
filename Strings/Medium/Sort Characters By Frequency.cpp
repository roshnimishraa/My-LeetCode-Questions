Given 
1. Sort in Descending Order

Better Approach : Priority Queue(Max Heap) 
TC : O(N* log N )
SC : O(N) 

Approach : 
1. push the element into hashmap and consider element frequency. (element,frequency)
2. From hashmap push into priority queue as (frequency,elements) 
3. print elements from priority queue with no. of occurences 

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> umap;
          string ans ="";  
        for(int i=0;i<s.length();i++){
            umap[s[i]]++; 
                  
        }
    priority_queue< pair<int,char> > pq;
        
    //iterate through map to push elements & freq in priority queue
        
    for(auto it : umap){
        pq.push({it.second,it.first});
    }
   
//Till maxHeap gets empty
        while(!pq.empty()){
//      take first element from max heap 
            int n= pq.top().first;
            
            //if n=2 print
          while(n--){
              //(2,e) // print e two times 
              ans +=pq.top().second;
          }
            pq.pop();
        }
        return ans;
        }
};
------------------------------------------------------------------------------------------------------------------------------------------

