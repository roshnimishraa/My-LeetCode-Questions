Approach : backtracking 
  for direction short method using for loop 
up = 0,1
down = 0,-1,
left = -1,0
right = 1,0

Time Complexity:  O(m*n*4^k), where “K” is the length of the word. And we are searching for the letter m*n times in the worst case. Here 4 in 4^k is because at each level of our decision tree we are making 4 recursive calls which equal 4^k in the worst case.

Space Complexity: O(K), Where k is the length of the given words.

class Solution {
public:
    bool helper(vector<vector<char>>& board,string word,int i,int j,int n,int m,int k){
        if(k >= word.size())return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.' || word[k]!=board[i][j]) return false;
        if(word.size() == 1 && word[k]==board[i][j]) return true;
        board[i][j] = '.';

    //checking in all directions 
        bool temp = false;
        int x[4] = {0,0,-1,1};
        int y[4] = {-1,1,0,0};
        for(int index=0;index<4;index++){
            temp = temp || helper(board,word,i+x[index],j+y[index],n,m,k+1);
        }
        board[i][j] = word[k];
        return temp;
    }
    
    bool exist(vector<vector<char>>& board,string word) {
        int n=board.size();
        if(n==0) return false;
        int m=board[0].size();
        if(word.size()==0) return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                     if(helper(board,word,i,j,n,m,0))return true;
                }
            }
        }
        return false;
    }
};
