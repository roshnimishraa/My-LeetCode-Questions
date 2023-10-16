Eg. Input: rowIndex = 3
Output: [1,3,3,1]

>>>>>>>>> Approach 1 : Using Type 1 (Using Extra space) 

  class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);
        
     for(int i =0;i<rowIndex+1;i++){
result[i] = vector<int> (i+1,1);
         
    for(int j=1;j<i;j++){
        result[i][j] = result[i-1][j] + result[i-1][j-1];
    }
  }
        return result[rowIndex];
    }
};

----------------------------------------------------------------------------------------------------------------------

Approach 2 : Removing Extra space (Instead of 2 D Array use 1 D Array) 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> prev;;
     for(int i =0;i<rowIndex+1;i++){
vector<int>curr (i+1,1);
         
    for(int j=1;j<i;j++){
    curr[j] = prev[j]+prev[j-1];
        }
             prev = curr;
  }
 
        return prev;
    }
};







  
