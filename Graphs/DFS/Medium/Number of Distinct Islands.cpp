Approach : DFS
TC : N * M * log(N * M) + O(N * M * 4)  
SC : O(N * M)  

Algorithm 
1. consider start node of 1's as Base point now 
    coordinates of 1's - base coordinates -> store in a vector of pair(list) 
2. store list in set unique elements will store 
3. return st.size()
  
Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Consider (0,3) (0,4) = 1,1 and (3,0) (3,1) = (1,1) 
now for (0,3) and (0,4) 
 (0,3) - (0,3) = (0,0) 
 (0,4) - (0,3) = (0,1) 
list {(0,0),(0,1)} 

now for  (3,0) and (3,1) 
(3,0) - (3,0) = (0,0) 
(3,1) - (3,0) = (0,1) 
list {(0,0),(0,1)} 

both are same to set count them as 1 


class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& grid,
    vector<vector<int>> &vis,vector<pair<int,int>> &vec,
    int row0,int col0)
    {
 vis[row][col]=1;
vec.push_back({row-row0,col-col0});
    int n=grid.size();
    int m=grid[0].size();

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

    for(int k=0;k<4;k++)
    {
        int nrow=row+dx[k];
        int ncol=col+dy[k];
        
    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]
    && grid[nrow][ncol]==1)
    {
        dfs(nrow,ncol,grid,vis,vec,row0,col0);
    }
    }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> st;
    


for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(!vis[i][j] && grid[i][j]==1)
        {
            vector<pair<int,int>> vec;
        dfs(i,j,grid,vis,vec,i,j);  
            st.insert(vec);
        }
    }
}
return st.size();
    }
};
