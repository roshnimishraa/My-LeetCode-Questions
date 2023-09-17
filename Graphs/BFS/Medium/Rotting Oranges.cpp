 TC : O(N * M) 
 SC : O(N * M) 

The algorithm steps are as follows 

1. For BFS traversal, we need a queue data structure and a visited array. Create a replica of the given array, i.e.,
 create another array of the same size and call it a visited array. We can use the same matrix, but we will avoid alteration of the original data. 
2. The pairs of cell number and initial time, i.e., <<row, column>, time> will be pushed in the queue and marked as visited (represents rotten) 
in the visited array. For example, ((2,0), 0) represents cell (2, 0) and initial time 0.  
3. While BFS traversal, pop out an element from the queue and travel to all its neighbours. In a graph, we store the list of neighbours in an adjacency
list but here we know the neighbours are in 4 directions. 
4. We go in all 4 directions and check for valid unvisited fresh orange neighbours. To travel 4 directions we will use nested loops,
you can find the implementation details in the code. 
5. BFS function call will make sure that it starts the BFS call from each rotten orange cell, and rotten all the valid fresh orange 
neighbours and puts them in the queue with an increase in time by 1 unit. Make sure to mark it as rotten in the visited array.  
6. Pop-out another rotten orange from the queue and repeat the same steps until the queue becomes empty.
7. Add a counter variable to store the maximum time and return it. If any of the fresh was not rotten in the visited array then return -1.


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntfresh =0;
int vis[n][m];
queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0}); // initially time = 0
                vis[i][j]=2;
            }
            else{
        //empty cell
                vis[i][j]=0;
            }
    //count fresh orange
if(grid[i][j] == 1) cntfresh++;
        }
    }

    int time =0;
int drow[] = {-1,0,1,0};
int dcol[] = {0,1,0,-1};
 int count =0;
while(!q.empty()){
    int r = q.front().first.first;
    int c = q.front().first.second;
    int t = q.front().second;
    time = max(time,t);
    q.pop();

// iterate through neighbours 
for(int i=0;i<4;i++){
    //update neighbour row and col val 
int nrow = r + drow[i];
int ncol = c + dcol[i];

//check for valid cell 
if(nrow >=0 && nrow < n  && ncol >=0 && ncol< m &&
vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
    q.push({{nrow,ncol},t+1});
    vis[nrow][ncol] = 2;
    count++;
}
}
}
//compare count and count fresh all fresh oranges should
// be rottened 
if(count != cntfresh) return -1;
return time;
    }
};

-------------------------------------------------------------------------------------------------------------------------------
 Another way 
 class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
    
// in q store {{row,col},time}
queue<pair<pair<int,int>,int>> q;
int vis[n][m];

// push rotten oranges in q with time =0 
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==2){
            q.push({{i,j},0});
            vis[i][j]=2;
        }
        else {
            vis[i][j]=0;
        }
    } 
}

// compute time 
int time =0;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
while(!q.empty()){
    int row = q.front().first.first;
    int col = q.front().first.second;
    int tm = q.front().second;
    time = max(time,tm);
    q.pop();

    //visit neighbour nodes in 4 directions 
for(int i=0;i<4;i++)
{
    int nrow=row+dx[i];
    int ncol = col+dy[i];

if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] ==0 && grid[nrow][ncol]==1)
{
 q.push({{nrow,ncol},tm+1});
 vis[nrow][ncol]=2;

}
}
}

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(vis[i][j] != 2 && grid[i][j]==1)
        return -1;
    }
}

return time;
    }
};
