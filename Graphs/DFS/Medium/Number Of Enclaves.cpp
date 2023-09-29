Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)


class Solution {
    void dfs(int row,int col,vector<vector<int>> &vis,
    vector<vector<int>> &adj)
    {
           int n =adj.size();
        int m= adj[0].size();
        vis[row][col]=1;
    int dx[] = {-1,0,1,0};
    int dy[]=  {0,-1,0,1};
    
for(int i=0;i<4;i++)
{
    int nrow=row+dx[i];
    int ncol = col+dy[i];
    
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
adj[nrow][ncol]==1 && vis[nrow][ncol]==0)
{
    dfs(nrow,ncol,vis,adj);
}
}
}
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n =grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
 
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         if(grid[i][j]==1 && vis[i][j]==0 && (i==0 || i==n-1 || j==0 || j==m-1))
         {
             dfs(i,j,vis,grid);
         }
     }
 }
  
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
               count++; 
            } 
        }
    }
        return count;
    }
};
