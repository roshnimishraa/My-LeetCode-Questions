Approach : backtracking 
  for direction short method using for loop 
up = 0,1
down = 0,-1,
left = -1,0
right = 1,0

Time Complexity:  O(m*n*4^k), where “K” is the length of the word. And we are searching for the letter m*n times in the worst case. Here 4 in 4^k is because at each level of our decision tree we are making 4 recursive calls which equal 4^k in the worst case.

Space Complexity: O(K), Where k is the length of the given words.


class Solution {
    private :
bool helper(int row,int col,int index,vector<vector<char>> &board,string &word)
{
 int m = board.size();
    int n = board[0].size();
 
    if(index == word.length())
    {
        return true;
    }

    //base condition 
if(row<0 || col<0 || row>=m || col>=n || board[row][col]=='$')
{
    return false;
}
    
 if(board[row][col] != word[index])
    {
        return false;
    }
    
    char temp = board[row][col];
    board[row][col] = '$';
    
    int dx[] = {-1,1,0,0};
    int dy[]  = {0,0,1,-1};
    
for(int i=0;i<4;i++){
    int nrow= row + dx[i];
    int ncol = col+dy[i];
    
if(helper(nrow,ncol,index+1,board,word)==true)
    return true;
}

    //if found found word
  board[row][col]=temp;
    return false;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
     int m = board.size();
        int n = board[0].size();
 
        int index=0;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++){
         //search first letter of the word
          if(board[i][j] == word[0])
          {
             if(helper(i,j,index,board,word)==true)
                 return true;
          }
      }
     }
        return false;
    }
};

