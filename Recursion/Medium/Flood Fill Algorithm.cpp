Approach: Recursion 

Time Complexity:  O(N * M) 
Space Complexity: O(N * M)

  
class Solution {
    void floodHelper(int i,int j,int oldColor,int newColor,
    vector<vector<int>> &image,int n,int m)
    {
        if(i<0 || i==n || j<0 || j==m || image[i][j] != oldColor){
            return;
        }
    image[i][j]=newColor;
    //down
floodHelper(i+1,j,oldColor,newColor,image,n,m);
    //up
floodHelper(i-1,j,oldColor,newColor,image,n,m);
    //right
floodHelper(i,j+1,oldColor,newColor,image,n,m);
    //left
floodHelper(i,j-1,oldColor,newColor,image,n,m);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int oldColor = image[sr][sc];
        
        if(oldColor == color)  return image;
        int n=image.size(); //row size
        int m=image[0].size(); //col size 
    
     floodHelper(sr,sc,oldColor,color,image,n,m);
        return image;
    }
};
