Time Complexity: O(V + E)
Auxiliary Space: O(V)

Approach : 
If there exists a mother vertex (or vertices), then one of the mother vertices is the last finished vertex in DFS.
  (Or a mother vertex has the maximum finish time in DFS traversal). A vertex is said to be finished in DFS if a recursive call
for its DFS is over, i.e., all descendants of the vertex have been visited. 


Algorithm 
1. Do DFS traversal of the given graph. While doing traversal keep track of the last finished vertex ‘v’. This step takes O(V+E) time.
  
2. If there exists a mother vertex (or vertices), then v must be one (or one of them). Check if v is a mother vertex by doing DFS/BFS from v.
  This step also takes O(V+E) time.

  
class Solution 
{
    private:
    void dfs(int node,vector<int> &vis,vector<int> adj[])
    {
        
        vis[node]=1;
     for(auto it : adj[node])
     {
         if(!vis[it])
         {
             dfs(it,vis,adj);
         }
     }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
vector<int> vis(V,0);
int lastNode=0;

for(int i=0;i<V;i++)
{
    if(!vis[i]){
dfs(i,vis,adj);  
lastNode =i;
    }
}
for(int i=0;i<V;i++)
{
    vis[i]=0;
}
   dfs(lastNode,vis,adj);
for(int i=0;i<V;i++){
    if(vis[i]==0)
    {
          return -1;
    }
  
}
return lastNode;
	}

};
