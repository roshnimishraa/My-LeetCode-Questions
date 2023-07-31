Efficient Approach : Generate all the rows that taken O(N) and Print it O(N) 
Time Complexity: O(n2), where n = number of rows(given).
Reason: We are generating a row for each single row. The number of rows is n. And generating an entire row takes O(n) time complexity.
Space Complexity: In this case, we are only using space to store the answer. That is why space complexity can still be considered as O(1).

Approach:
The steps are as follows:
1.	First, we will run a loop(say row) from 1 to n.
2.	Inside the loop, we will call a generateRow() function and add the returned list to our final answer. Inside the function we will do the following:
1.	First, we will store the 1st element i.e. 1 manually.
2.	After that, we will use a loop(say col) that runs from 1 to n-1. It will store the rest of the elements.
3.	Inside the loop, we will use the specified formula to print the element. We will multiply the previous answer by (row-col) and then divide it by col itself.
4.	Thus, the entire row will be stored and returned.
3.	Finally, we will return the answer list.


class Solution {
vector<int>generateRow(int numRows){
    vector<int> ansRow;
        long long ans=1; //1 element of a row always 1
      //pushing 1st element 
        ansRow.push_back(1);
        for(int col=1;col<numRows;col++){
            ans = ans*(numRows - col);
            ans = ans/col;
             ansRow.push_back(ans);
        }
       return ansRow;
}
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
