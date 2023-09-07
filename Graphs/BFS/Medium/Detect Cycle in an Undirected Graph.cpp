Using BFS : 
TC : O(N + 2 * E) 

  class Graph {
private :
bool detect(int src,vector<int> adj[],int vis[])
{
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

    //traverse all its adjacent node 
for(auto adjacentNode : adj[node])
{
    if(vis[adjacentNode] != 1){
        vis[adjacentNode] = 1; //visit this node
        q.push({adjacentNode,node});

    }
    //give any other node visited that node 

    else if(parent != adjacentNode){
        return true;
    }
}
}
// visited all the node does not get the cycle 
return false;

}
public:
    bool detectCycle(int V, vector<int> adj[]) {
//for multiple graph (connected components)
int vis[V]={0};
      // 0 based indexing 
for(int i=0;i<V;i++){
    if(vis[i] == 0) // not visited 
    {
        if(detect(i,adj,vis)) return true;

    }
}
return false;
    }
};



-------------------------------------------------------------------------------------------------------------------------------------------------------------

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
