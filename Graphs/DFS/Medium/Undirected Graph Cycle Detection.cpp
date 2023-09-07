  Using DFS (Depth First Search) 
TC : o(N + 2*E) 
sc : O(N) 

class Graph {
private : 
 bool detect(int node,int parent,int vis[],vector<int> adj[])
 {
     vis[node] = 1;
     
    for(auto adjacentNode : adj[node]){
    if(!vis[adjacentNode])
   {
         if(detect(adjacentNode,node,vis,adj)==true)
  return true;
  
   }
   else if(adjacentNode != parent){
       return true;
   } 
  }
   
    return false;
 }
public:
    bool detectCycle(int V, vector<int> adj[]) {
       int vis[V]={0};
    //for multiple graph
for(int i=0;i<V;i++)
{
    if(!vis[i]){
        if(detect(i,-1,vis,adj)==true)
        return true;
        
    }
}
      return false;
    }
};
