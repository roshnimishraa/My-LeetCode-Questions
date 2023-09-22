TC : O(N * M * 4) 

 class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
      int n = grid.size();
      int m = grid[0].size();
    //   {{row,col},dis}
     queue<pair<pair<int,int>,int>> q;
     vector<vector<int>> vis(n,vector<int> (m,0));
     vector<vector<int>> dist(n,vector<int>(m,0));
     
     // mark vis of grid[i][j]=1
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                vis[i][j]=1;
                q.push({{i,j},0});
            }
              else{
             vis[i][j] = 0;
  }
 
        }
    }
    // explore adj nodes in 4 possible directions 
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int row=it.first.first;
        int col = it.first.second;
        int steps = it.second;

	//Calculate distance
    dist[row][col]=steps;
    
for(int i=0;i<4;i++)
{
    int nrow= row + dx[i];
    int ncol = col + dy[i];

// valid check 
if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && 
vis[nrow][ncol]==0)
{
    vis[nrow][ncol]=1;
    q.push({{nrow,ncol},steps+1});
}
}
    }
    
 return dist;     
	}
};
