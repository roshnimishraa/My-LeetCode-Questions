Better Approach : Using extra time complexity 

TC : O(N! * N) 
SC : O(N^2)

class Solution {
public:
bool isSafe(int row,int col,vector<string> &board,int n)
{
int x = row;
int y = col;
// check for same row 
while(y >= 0){
    if(board[x][y] =='Q')
    {
        return false;
    }
    y--;
}

x = row;
y = col;
// check for diagonal 
// row-1,col-1 diagonal
while(x>=0 && y>=0)
{
    if(board[x][y] == 'Q')
    {
  return false;
    }
y--;
x--;
}

  //  not checking for column because this condition covered in helper function 
x=row;
y = col;
// row+1,col-1 diagonal 
while(x<n && y>=0)
{
    if(board[x][y] == 'Q')
    {
        return false;
    }
    x++;
   y--;
  
}
return true;
}
void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans)
{
// base 
if(col == n){
    ans.push_back(board);
    return;
}
// check for every row from 0 to n-1
for(int row=0;row<n;row++)
{
    if(isSafe(row,col,board,n)==true)
    {
    board[row][col]='Q';
// recursively check for next col
solve(col+1,n,board,ans);
// backtrack
board[row][col]='.';
    }
}  
}
    vector<vector<string>> solveNQueens(int n) {
 vector<vector<string>> ans;
 vector<string> board(n);
 string s(n,'.');
for(int i =0;i<n;i++){
    board[i] = s;
}
solve(0,n,board,ans);
return ans;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Optimization of time complexity 
Intuition: This is the optimization of the issafe function. In the previous issafe function, we need o(N) for a row, o(N) for the column, 
and o(N) for the diagonal. Here, we will use hashing to maintain a list to check whether that position can be the right one or not.

>> Use Hash array to check Queen is placed or not  
>> Hash array size = 2*n - 1
>> Place Queen in Hash array for lower diagonal = row+col
>> Place Queen in Hash array for upper diagonal = n - 1 + col - row

/* 
Time Complexity:  O(N!)
Space Complexity: O(N) {For Recursive Stack and For the 3 vectors col[] , topLeft[] , topRight[] we are using in place of isSafe() function } & O(N^2) {For our ans[][] vector}
*/
class Solution {
public:
void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int n)
{
    // base case 
if(col ==n)
{
    ans.push_back(board);
    return;
}

for(int row=0;row<n;row++)
{
if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 
&& upperDiagonal[n-1 + col-row] == 0)
{
board[row][col] = 'Q';
leftRow[row] = 1;
lowerDiagonal[row+col] = 1;
upperDiagonal[n-1 + col-row]=1;
solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
board[row][col] = '.';
leftRow[row] = 0;
lowerDiagonal[row+col] = 0;
upperDiagonal[n-1 + col-row] = 0;
}
}
}
vector<vector<string>> solveNQueens(int n) {
 vector<vector<string>> ans;
 vector<string> board(n);
 string s(n,'.');
 for(int i=0;i<n;i++){
     board[i] = s;
 }
vector<int> leftRow(n,0);
vector<int> upperDiagonal(2*n-1,0);
vector<int> lowerDiagonal(2*n-1,0);

solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);

return ans;
    }
};
