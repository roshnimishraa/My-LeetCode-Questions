class Solution {
    private:
      void dfs(int node,int vis[],vector<int> adj[], 
    vector<int> &ans)
    {
        vis[node]=1;
    ans.push_back(node);
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,ans);
        }
    }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
 int vis[V] = {0};
 vector<int> ans;
 for(int i=0;i<V;i++)
 {
     if(!vis[i])
     {
         dfs(i,vis,adj,ans);
     }
 }
 return ans;
    }
};
