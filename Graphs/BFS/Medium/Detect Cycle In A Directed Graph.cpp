// Using Kahn's BFS Approach 

Logic : if there is cycle the count < N and is there is no cycle then count == N 

  TC : O(V + E)
SC : O(N ) 

#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
 int indegree[n+1] = {0};
 vector<int> adj[n+1];
 queue<int> q;
 
//  adj list 
for(auto i: edges)
  {
    adj[i.first].push_back(i.second);
  }
  
 //push nodes indegree 
      for(int i=0;i<n+1;i++){
    for(auto it : adj[i]){
        indegree[it]++;
    }
 }

      for(int i=0;i<n+1;i++){
if(indegree[i] == 0){
    q.push(i);
}
}

 int count=0;
 while(!q.empty())
 {
     int node = q.front();
     q.pop();
     
    count++;
    
    // traverse its adjacent nodes
    for(auto it : adj[node])
    {
        indegree[it]--;
        if(indegree[it] == 0)
        q.push(it);
    }
 }

       if(count !=n+1){

           return true;

       }

       return false;
}


----------------------------------------------------------------------------------------------------------------------------------------------------------

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
