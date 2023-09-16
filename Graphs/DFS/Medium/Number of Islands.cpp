class Solution {
    private:
    void dfs(int i,int j,int n,int m,vector<vector<char>> &grid,vector<vector<int>> &vis,int dx[],int dy[])
    {
        vis[i][j]=1;
for(int k=0;k<4;k++)
{
    int nrow=i+dx[k];
    int ncol=j+dy[k];

if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
    dfs(nrow,ncol,n,m,grid,vis,dx,dy);
}
}
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
    int count=0;
vector<vector<int>> vis(n,vector<int>(m,0));

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
    if(!vis[i][j] && grid[i][j]=='1'){
   dfs(i,j,n,m,grid,vis,dx,dy);
   count++;  
  
    }
    }
}
return count;
    }
};
