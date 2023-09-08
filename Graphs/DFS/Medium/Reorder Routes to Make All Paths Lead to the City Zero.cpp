Approach : DFS 

Time complexity:
O(n + e)
Space complexity:
O(n)

Algorithm 
dfs(int currNode,int parent,int count,vector<bool> &vis,vector<vector<pair<int,int>>> &adj)
1. mark currNode as visited = 1
2. Iterate throgh its neighbour nodes or adjacent nodes
i) adjList for orgininal path ({dest,1}) or for modified path adj store ({dest,0})
  so vertex = it.first
     check = it.second
ii) if(parent != v) no self loop then 
a) if node from source is reachable to destination then do count++ 
b)  else recursive call for unreachable nodes 

fun
1. take a adj list of pair to store ({dest,0/1}) 0 for modified verted those are unreachable from source 
                                                1 for original graph those are reachable from source
-> take a visited array of bool type 
2. make a adj list for a->b original edges
  for b->a modified edges
3. recursive call for dfs traversal 
4. return count
  
  
  class Solution {
    private:
    void dfs(int node,int parent,int &count,vector<bool> &vis,  vector<vector<pair<int,int>>> &adj)
    {
  if( vis[node] == true ) return;

         vis[node] = true;
          
          for(auto child:adj[node])
          {  
              int v = child.first;
            int check = child.second;
              if(parent != v)
              {
                // u->v original edge do count++
                   if(check == 1){
                   count=count+1;
                   }
                     dfs(child.first,node,count,vis,adj);
              }
          }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
     vector<vector<pair<int,int>>> adj(n);
    vector<bool> vis(n,false);
    int count=0;
for(auto it : connections)
{
    adj[it[0]].push_back({it[1],1});
    adj[it[1]].push_back({it[0],0});
}   

dfs(0,-1,count,vis,adj);
return count;
    }
};
