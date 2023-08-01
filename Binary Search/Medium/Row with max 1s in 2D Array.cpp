Naive Appraoch :
TC: O(N*M) 
SC : O(1) 
1. Use two loop i & j for row and col 
2. if mat[i][j] == 1 then row++
3. seach for max 1 in row 

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int ans = 0, res = -1;
    for(int i =0;i<n;i++)
    { 
int row = 0;
        for(int j =0;j<m;j++)
        {
            if(matrix[i][j]==1)
             row ++; 
        }
        if(row>ans) res = i;      
       ans = max(ans, row);
}
    return res;
}

-------------------------------------------------------------------------------------------------------------------------------
Approach : Binary Seach 
Given : Row-wise sorted 
TC : N*log M
SC : O(1) 

int binarySearch(vector<vector<int>> &matrix,int row){
  int m = matrix[0].size();   
int low = 0 ;
int high = m-1;
int firstIndexOfOne = m;
    while(low <= high){
        int mid = (low + high)/2;
    
    if(matrix[row][mid] == 1){
        firstIndexOfOne = mid;
//left me dekho aur 1 h kya
    high = mid -1 ;
    }
    else{
        // == 0 go in right search for 1 
        low = mid+1;
    } 
    }
     int count = m-firstIndexOfOne;
     return count;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxCount = 0;
//Row which is containing overall max count
int row = 0;
 n=matrix.size();
m=matrix[0].size();
   for(int i=0;i<n;i++){
       int countOfOneInIthRow = binarySearch(matrix,i);
  
  if(countOfOneInIthRow > maxCount){
      maxCount = countOfOneInIthRow;
      //max row of 1's is ith row 
       row = i ;
  }
   }
   return row;
}
