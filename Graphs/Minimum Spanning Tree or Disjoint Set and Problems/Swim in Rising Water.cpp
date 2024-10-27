### Approach : BFS + Binary Search

Time Complexity: O(n^2⋅log(n))
Space Complexity: O(n^2)

class Solution {
    bool bfs(vector<vector<int>> &grid, int time)
    {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));

        vis[0][0] = 1;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && 
        grid[nrow][ncol] <= time && !vis[nrow][ncol])
        {
            vis[nrow][ncol] = 1;
            q.push({nrow,ncol});
        }
            }
        }
        if(vis[n-1][n-1] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
          int n = grid.size();

        int start = grid[0][0];

        int end =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                end = max(end,grid[i][j]);
            }
        }

        // applying binary search 
        int ans=0;
        while(start <= end)
        {
         int mid = end - (end-start)/2;
         if(dfs(grid,mid))
         {
            ans = mid;
            end = mid-1;
         }
         else{
            start = mid+1;
         }
        }
        return ans;
    }
};
