Approach : Variable size Sliding Window 
Time Complexity: O(N)
Auxiliary Space: O(1)

Logic :
1. In 2 basket for one basket there can 1 type of fruits
2. pick the tree fruit in sequence 

int findMaxFruits(vector<int> &arr, int n) 
 int i=0,j=0;
 unordered_map<int,int> umap;
 int ans=0;
 while(j<n){
     umap[arr[j]]++;
     while(umap.size() > 2 ) {
        //window size decrease 
        umap[arr[i]]--;
      if(umap[arr[i]] == 0){
          umap.erase(arr[i]);
      }       
    i++;
    }
    ans=max(ans,j-i+1);
  j++;
 }   
 return ans;
}
