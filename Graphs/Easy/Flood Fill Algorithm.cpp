TC : O(N * M) 
SC : O(N * M)


//short way of checking 
class Solution {
    void helper(int row,int col,vector<vector<int>> &image,vector<vector<int>> &ans,int newColor,int deltaRow[],int deltaCol[],int initialColor)
    {
ans[row][col]=newColor;
int n= image.size();
int m = image[0].size();
for(int i=0;i<4;i++)
{
    //neighbour row and row 
    int nRow = row + deltaRow[i];
    int nCol = col + deltaCol[i];
 if(nRow>=0 && nRow<n && nCol >=0 && nCol < m && 
 image[nRow][nCol] == initialColor && ans[nRow][nCol] != newColor)
 {
    helper(nRow,nCol,image,ans,newColor,deltaRow,deltaCol,initialColor);
 }

}
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1}; 
    helper(sr,sc,image,ans,color,deltaRow,deltaCol,initialColor);
    return ans;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------
  Recusive traversal check

  class Solution {
    private:
void helper(vector<vector<int>>& image,int row,int col,int newColor,int oldColor)
{
    int n=image.size();
int m =image[0].size();
    //corner case 
    if(row>=n || row<0 || col>=m || col<0 || image[row][col] != oldColor)

    {
        return;
    }
    image[row][col]=newColor;
 //down
 helper(image,row+1,col,newColor,oldColor);
 //up
  helper(image,row-1,col,newColor,oldColor);
  //right
 helper(image,row,col+1,newColor,oldColor);
 // left
 helper(image,row,col-1,newColor,oldColor);
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
int n=image.size();
int m =image[0].size();
  int oldColor = image[sr][sc];
  if(oldColor == color) return image;

  helper(image,sr,sc,color,oldColor);
  return image;      
    }
};
