Approach : Insert elements of a[i] and b[i] and then return size 

Eg. 
Input : arr[] = {-1, 2, -1, 3, 2}
Output : 3
Explanation:
-1 and 2 are repeating whereas 3 is 
the only number occuring once.
Hence, the output is 3

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> s;
        
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        
        for(int i=0;i<m;i++){
            s.insert(b[i]);
        }
        return s.size();
    }
};

