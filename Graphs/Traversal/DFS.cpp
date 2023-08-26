class Solution {
    private:
    void dfs(int node, vector<int> adj[],int vis[],vector<int> &ls)
    {
        vis[node]=1;
        ls.push_back(node); 
        
        
    //traverse all the neighbours of node 
    for(auto it : adj[node])
    {
        if(vis[it] !=1){
            dfs(it,vis,adj,ls);
        }
    }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ls; // to store dfs traversal
    int vis[V] = {0}; // mark every node as 0 in an array
    int start = 0; //starting index is 0th index
    
    dfs (start,adj,vis,ls);
    return ls;
    }
};
