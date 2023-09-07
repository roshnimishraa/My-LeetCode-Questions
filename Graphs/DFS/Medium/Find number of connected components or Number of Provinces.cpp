Approach : DFS 

TC : O(N) + O(V + 2 * E)
sc : O(N)

class Solution {
    private:
    void dfs(int node,vector<int> &vis,vector<int> adj[])
    {
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it] == 0){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n];
vector<int> vis(n,0);
       for(int i =0;i<n;i++)
       {
           for(int j=0;j<n;j++){
        if(isConnected[i][j]==1 && i != j){
            adjLs[i].push_back(j);
            adjLs[j].push_back(i);
        }
           }
       }
 int count=0;
 for(int i=0;i<n;i++)
 {
     if(!vis[i]){
         count++;
         dfs(i,vis,adjLs);
     }
 }
 return count;
    }
};
