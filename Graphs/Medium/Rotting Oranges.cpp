 TC : O(N * M) 
 SC : O(N * M) 

The algorithm steps are as follows:

1. For BFS traversal, we need a queue data structure and a visited array. Create a replica of the given array, i.e., create another array of the same size and call it a visited array. We can use the same matrix, but we will avoid alteration of the original data. 
2. The pairs of cell number and initial time, i.e., <<row, column>, time> will be pushed in the queue and marked as visited (represents rotten) in the visited array. For example, ((2,0), 0) represents cell (2, 0) and initial time 0.  
3. While BFS traversal, pop out an element from the queue and travel to all its neighbours. In a graph, we store the list of neighbours in an adjacency list but here we know the neighbours are in 4 directions. 
4. We go in all 4 directions and check for valid unvisited fresh orange neighbours. To travel 4 directions we will use nested loops, you can find the implementation details in the code. 
5. BFS function call will make sure that it starts the BFS call from each rotten orange cell, and rotten all the valid fresh orange neighbours and puts them in the queue with an increase in time by 1 unit. Make sure to mark it as rotten in the visited array.  
6. Pop-out another rotten orange from the queue and repeat the same steps until the queue becomes empty.
7. Add a counter variable to store the maximum time and return it. If any of the fresh was not rotten in the visited array then return -1.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // figure out the grid size
      int n = grid.size();
      int m = grid[0].size();

      // store {{row, column}, time}
      queue < pair < pair < int, int > , int >> q;
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if cell contains rotten orange
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
            // mark as visited (rotten) in visited array
            vis[i][j] = 2;
          }
          // if not rotten
          else {
            vis[i][j] = 0;
          }
          // count fresh oranges
          if (grid[i][j] == 1) cntFresh++;
        }
      }

      int tm = 0;
      // delta row and delta column
      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
      int cnt = 0;

      // bfs traversal (until the queue becomes empty)
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        // exactly 4 neighbours 
        for (int i = 0; i < 4; i++) {
          // neighbouring row and column
          int nrow = r + drow[i];
          int ncol = c + dcol[i];
          // check for valid cell and 
          // then for unvisited fresh orange
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
            // push in queue with timer increased
             q.push({{nrow, ncol}, t + 1}); 
            // mark as rotten
            vis[nrow][ncol] = 2;
            cnt++;
          }
        }
      }

      // if all oranges are not rotten
      if (cnt != cntFresh) return -1;

      return tm;

    }
};
