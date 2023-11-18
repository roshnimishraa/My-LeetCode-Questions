Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.

class Solution {
public:
bool isValid(vector<vector<char>>& board,int row,int col,char c)
{
    for(int i=0;i<9;i++)
    {
// check entire row for filling correct number
if(board[row][i] == c){
    return false;
}
// check entire col 
if(board[i][col] == c){
    return false;
}

if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c)
{
    return false;
}
    }
    return true;
}
bool helper(vector<vector<char>>& board)
{
    int n= board.size();
    int m = board[0].size();
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(board[i][j]=='.')
        {
for(char c = '1'; c<='9';c++)
{
if(isValid(board,i,j,c)==true)
{
    board[i][j] = c;

    if(helper(board)==true)

        return true;

    else
        board[i][j] = '.';

}
}
return false;
}
}
}
return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};
