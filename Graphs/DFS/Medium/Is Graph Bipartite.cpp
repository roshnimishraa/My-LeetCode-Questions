Approach : DFS 

NOTE :
1. Bipartite Graph :- Color the graph with 2 colors such that NO Adjacent nodes have same color. 
2. Linear Grpahs with NO CYCLE are always Bipartite Graph 
3. Any graph with even cycle length can also be Bipartite Graph
4. Any graph with odd length cycle can never be Bipartite Graph

Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one 
and a node in the other.


  class Solution {
    bool dfs(int node,int currentColor,vector<int> &color,vector<vector<int>> &adj)
    {
        color[node]=currentColor;
for(auto it : adj[node])
{
    if(color[it] == -1){
        //if not colored color with opposite color 
     if(dfs(it,!currentColor,color,adj)==false) return false;
    }
// if adjNode is previously colored 
// and it is having same color 
else if(color[it]== currentColor){
    return false;
}
}
return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
    vector<int> color(V,-1);

for(int i=0;i<V;i++)
{
    if(color[i] == -1){
        if(dfs(i,0,color,graph) == false)
        return false;
    }
}
return true;
    }
};
  
  
