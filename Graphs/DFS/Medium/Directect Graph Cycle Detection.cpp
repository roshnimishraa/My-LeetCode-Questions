Approach 2 : Using DFS 

Logic : 
two arrays : vis and pathVis
recursive DFS calls

Corner Case : Cycle does not exists then return false  and mark path vis as 0


bool dfs(int node,int vis[],int pathVis[],vector<int> adj[])
{
    vis[node]=1;
    pathVis[node]=1;

    // traverse neighbours
    for(auto it : adj[node]){
        if(vis[it] != 1)
        {
 if(dfs(it,vis,pathVis,adj) == true) {
     return true;
 }
        }
       
else if(pathVis[it] == 1) {
    return true;
}
    }
pathVis[node]=0;
return false;

}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  vector<int> adj[n+1];
  int vis[n+1] = {0};
 int pathVis[n+1] = {0};

  // make adj list
  for(auto i : edges){
adj[i.first].push_back(i.second);
  }

  for(int i=0;i<n;i++){
      if(!vis[i]){
          if(dfs(i,vis,pathVis,adj) == true) {
              return 1;
          }
      }
  }

  return 0;
}
