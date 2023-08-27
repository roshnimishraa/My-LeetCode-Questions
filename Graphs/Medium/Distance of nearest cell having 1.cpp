TC : O(N * M * 4) 

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
         int n = grid.size();
         int m = grid[0].size();
         
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //consider 1
        if(grid[i][j] == 1) 
        {
             vis[i][j] = 1;
        q.push({{i,j},0});
        }
  else{
             vis[i][j] = 0;
  }
 
        }
        
    }
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        
    // calculate distance 
    dist[row][col] = steps;
        for(int i=0;i<4;i++){
        // explore neighbours 
    int nrow = row + delrow[i];
    int ncol = col + delcol[i];
    
//check valid 
if(nrow>=0 && nrow < n && ncol>=0 && ncol<m 
&& vis[nrow][ncol] == 0){
    vis[nrow][ncol] = 1;
    q.push({{nrow,ncol},steps+1});
}
        }
    }
    return dist;
	}
};
