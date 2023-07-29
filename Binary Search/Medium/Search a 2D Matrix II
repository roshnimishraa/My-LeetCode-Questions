Given : Matrix is row-wise and column-wise sorted 

Time Complexity : O(m+n) 
Space Complexity : O(1)  

Corner Case :  array out of bound return false

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int n=matrix.size();
        int m=matrix[0].size();
    
    int i=0;
        int j=m-1;
    while(i<n && j>=0){
        if(matrix[i][j]==target){
            return true;
        }
        else if(matrix[i][j] > target){
            j--;
        }
        else{
            i++;
        }
    }
        return false;
    }
};
