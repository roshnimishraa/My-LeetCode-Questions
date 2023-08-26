TC : O(N) + O(V + 2 * E)
sc : O(N)

void dfs(int node,vector<int> adjLs[],int vis[])
{
    vis[node]=1;
  //  adjLs.push_back(node);

    for(auto it: adjLs[node])
    {
        if(vis[it]==0){
            dfs(it,adjLs,vis);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
vector<int> adjLs[n];
// make adjacency list
 for(int i=0;i<n;i++){
     for(int j=0;j<n;j++)
     {
    // ifadj[i][j]== 1 mean there is a node i!=j and it should not 
// self node
         if(roads[i][j] == 1 && i !=j){
             adjLs[i].push_back(j);
             adjLs[j].push_back(i);
         }
     }
 }

 int vis[n] = {0};
 int count=0;
for(int i= 0;i<n;i++){
if(vis[i] == 0){
    count++;
    dfs(i,adjLs,vis);
}
}
return count;
}
