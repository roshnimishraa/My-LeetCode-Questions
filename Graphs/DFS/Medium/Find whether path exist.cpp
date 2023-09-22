Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)


class Solution
{
    private:
    bool dfs(int row,int col,
    vector<vector<int>> &vis,
    vector<vector<int>> &grid)
    {
       int n=grid.size();
 
 
 vis[row][col]=1;
 
 int dx[]={-1,0,1,0};
 int dy[]={0,-1,0,1};
 
for(int i=0;i<4;i++)
{
    int nrow = row+dx[i];
    int ncol = col+dy[i];
    
    if(nrow<0 || nrow>=n || ncol<0 || ncol>=n 
 || grid[nrow][ncol]==0 ) {
    continue;
    }
   
    if(grid[nrow][ncol] ==2 ) return true;
   
  if(grid[nrow][ncol] ==3 && !vis[nrow][ncol])
  {
      if(dfs(nrow,ncol,vis,grid)==true) return true;
  }
}
return false;
    }
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
 // 1-src,2-dest,3-blank,0-wall
 int n=grid.size();

 vector<vector<int>> vis(n,vector<int>(n,0));
 
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         if(grid[i][j]==1)
         {
             if(dfs(i,j,vis,grid)==true)
             {
                 return true;
             }
             
         }
     }
 }
 return false;
    }
};
