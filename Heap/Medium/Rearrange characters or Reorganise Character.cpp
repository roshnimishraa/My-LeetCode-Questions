Approach : priority queue and unordered map
TC : O(|S| log |S|)    string S 
SC : O(N)  

  Logic : 
1. Push in unordered map <char,int> 
2. Store in pair in priority queue(max heap) , frequencies with chars <int,char>
3. Pick the top most frequency element and pop it
4. Add both chars into our resultant string
5. Reduce their frequencies by 1
6. if their frequency is still positive push to the priority queue
7. if the top chars frequency is still greater than 1, it's impossible to create , else add to the resultant string

 string rearrangeString(string str)
    {
    string ans = "";
    unordered_map<char,int> umap;
    priority_queue<pair<int,char>> pq;
    
    for(auto ch : str){
        umap[ch]++;
    }
    
    for(auto itr : umap){
        pq.push({itr.second,itr.first});
  //     pq.push(make_pair(itr.second,itr.first));
        
    }
    
    while(pq.size() > 1){
        auto top1 = pq.top();
        pq.pop();
        auto top2 = pq.top();
        pq.pop();
        
        ans += top1.second;
        ans += top2.second;
        
        top1.first -= 1;
        top2.first -= 1;
        
        if(top1.first > 0){
            pq.push(top1);
        }
        
    if(top2.first > 0 ){
        pq.push(top2);
        
    }
    }
      
   if(!pq.empty()){
         if(pq.top().first > 1) return "";
         
         else 
            ans += pq.top().second;
        }
        return ans;
    }
