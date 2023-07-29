Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

Approach: We can traverse through every element that is present in the matrix and return true if we found any element in the matrix is equal to the target integer. If the traversal is finished we can directly return false as we did not find any element in the matrix to be equal to the target integer.

Time complexity: O(m*n)
Space complexity: O(1)
-----------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Binary Search
Time complexity: O(log(m*n))
Space complexity: O(1)


Given : Matrix is Linearly Sorted
Approach : Consider the 2D matrix as a 1D matrix having indices from 0 to (m*n)-1 and apply binary search.
low = 0 high = n*m -1
Corner Case : Matrix is Empty    

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
		// if matrix have 0 rows or 0 colums
        if(n == 0 || m == 0)
            return false;
        
	
        int start = 0, end = m*n - 1;
        
        while(start <= end)
        {
     int mid = start + (end - start) / 2;
			// a[x] : matrix[x / m][x % m] formulae
            int indexValue = matrix[mid/m][mid%m];
            if (target == indexValue)
                return true;
			// left half
            else if(target < indexValue)
                end = mid - 1;
            else
			// right half
                start = mid + 1;       
        }
        return false;
    }
	
};

