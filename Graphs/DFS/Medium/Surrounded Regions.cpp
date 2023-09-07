Approach : DFS 

Time Complexity: O(N) + O(M) + O(NxMx4) ~ O(N x M), For the worst case, every element will be marked as ‘O’ in the matrix,
  and the DFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time.
Also, we are running loops for boundary elements so it will take O(N) + O(M).
Space Complexity ~ O(N x M), O(N x M) for the visited array, and auxiliary stack space takes up N x M locations at max. 

Algorithm 
1. Create a corresponding visited matrix and initialize it to 0.
2. Start with boundary elements, once ‘O’ is found, call the DFS function for that element and mark it as visited. In order to traverse for boundary
elements, you can traversethrough the first row, last row, first column, and last column. 
3. DFS function call will run through all the unvisited neighboring ‘O’s in all 4 directions and mark them as visited so that they are not converted to ‘X’ 
  in the future. The DFS function will not be called for the already visited elements to save time, as they have already been traversed. 
4. When all the boundaries are traversed and corresponding sets of ‘O’s are marked as visited, they cannot be replaced with ‘X’. 
  All the other remaining unvisited ‘O’s are replaced with ‘X’. This can be done in the same input matrix as the problem talks about replacing the values,
  otherwise tampering with data is not advised. 

class Solution {
    private : 
    void dfs(int row,int col,vector<vector<int>> &vis,
    vector<vector<char>>& board,int dx[],int dy[])
    {
        int n = board.size();
        int m = board[0].size();
        vis[row][col]=1;

//while dfs calls check out of boundary 
//check valid condition && traverse all 4 neighbours
for(int i=0;i<4;i++)
{
    int nrow = row + dx[i];
    int ncol = col + dy[i];

    if( nrow>= 0 && nrow<n && ncol>=0 && ncol < m && !vis[nrow][ncol]
    && board[nrow][ncol] == 'O')
    {
 dfs(nrow,ncol,vis,board,dx,dy);

    }

}

    }

public:
    void solve(vector<vector<char>>& board) {
     int n = board.size();
     int m = board[0].size();
vector<vector<int>> vis(n,vector<int>(m,0));

int dx[] = {-1,0,+1,0};
int dy[] = {0,+1,0,-1};

//traverse 1st row and last column 
for(int row=0; row<m; row++){
    // first row 
    if(!vis[0][row] && board[0][row] == 'O'){
dfs(0,row,vis,board,dx,dy);
    }

    // last row 
    if(!vis[n-1][row] && board[n-1][row]=='O'){
dfs(n-1,row,vis,board,dx,dy);
    }
}   

// traverse 1st col and last col
for(int col=0;col<n;col++)
{
    // 1st col
    if(!vis[col][0] && board[col][0] == 'O')
    {
dfs(col,0,vis,board,dx,dy);
    }

 // last col 
 if(!vis[col][m-1] && board[col][m-1] == 'O')
 {
     dfs(col,m-1,vis,board,dx,dy);

 }
}

// traverse all the rows
for(int row=0;row<n;row++){
    for(int col=0;col<m;col++){
        if(!vis[row][col] && board[row][col]=='O')
        {
            board[row][col]='X';
        }
    }
}
//return board;
    }
};
