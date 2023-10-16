Important Interview question
3 types of questions 
1 Given the Row no and Column number find the element at that place
2. Print any Nth Row of Pascal triangle 
3. Given N,print the entire pascal triangle 

https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

Type 3 
  TC : O(N)^2 
  
class Solution {
    vector<int> generateRow(int row){
      vector<int> ansRow;
        long long ans = 1;
        ansRow.push_back(1);
        
    for(int col=1;col<row;col++){
        ans = ans* (row - col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
        return ansRow;
    }
    
    public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRow(i));
            
        }
        return ans;
    }
};
