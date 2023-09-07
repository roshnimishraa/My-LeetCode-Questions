Approach : DIJKSTRA ALGO 

ALGORITHM : 
1. Create a Priority Queue of pair store dis,row,col {dis,{row,col}} 
like for diff store dis,{row,col}
2. make 2D vector dis initially assign INT_MAX
3. array of possible 4 direction 
4. mark src at dis[0][0] as 0 and push it pq
5. Traverse through priority queue till it gets empty 
i) pop diff,row and col from pq 
ii)Iterate through adjacent Node in 4 possible direction and new_row and new_col 
check safeToMove condition 
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m) then 
iii) find absDiff between old coordinate value to new coordinates value 
     absDiff = abs(arr[row][col] - arr[nrow][ncol]) 
iv) Find maxDiff 
    maxDiff = max(absDiff,diff) 
v) Check if maxDiff < dis[nrow][ncol] then update 
 dis[nrow][ncol]=maxDiff
and push ({maxDiff,{nrow,ncol}} into pq 
vi) return dis[m-1][n-1] 


TC : O(E LOG V) 
SC : O(V) 

class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
    int n=heights.size();
    int m=heights[0].size();
    priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;


    vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

dis[0][0]=0;
pq.push({0,{0,0}});

// traverse through pq
while(!pq.empty())
{
   
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;


if(row==n-1 && col==m-1) return diff;

// iterate through neighbour node
for(int i=0;i<4;i++)
{
    int nrow = row+dx[i];
    int ncol = col+dy[i];

//validity
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
{
    int absDiff = abs(heights[row][col]-heights[nrow][ncol]);
    int maxDiff = max(diff,absDiff);

if(dis[nrow][ncol] > maxDiff){
    dis[nrow][ncol] = maxDiff;
    pq.push({maxDiff,{nrow,ncol}});
}
}

}

}
return dis[m-1][n-1];
    }
}; 
