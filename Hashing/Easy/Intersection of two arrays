Problem link : https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1
Input:
n = 5, m = 3
a[] = {89, 24, 75, 11, 23}
b[] = {89, 2, 4}

Output: 1

Explanation: 
89 is the only element 
in the intersection of two arrays.
-----------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach : Hashing (unordered_set) 
Expected Time Complexity: O(n + m).
Expected Auxiliary Space: O(min(n,m)).

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_set<int> st;
        for(int i=0;i<n;i++){
         //   st[a[i]]++;
         st.insert(a[i]);
        }
        
        int count= 0;
        for(int i=0;i<m;i++){
            int key = b[i];
            if(st.find(key) != st.end()){
                count++;
                
                //if in a[i] there is duplicate elements
                st.erase(key);
            }
            
        }
        return count;
    }
};
