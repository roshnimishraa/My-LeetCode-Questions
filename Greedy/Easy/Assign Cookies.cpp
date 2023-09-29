TC : O(N LOG N) 
SC : O(1) 
  
Algorithm : Two Pointer 
1. Sort in increasing order both no of children(g) and no. of cookies
2. Use two pointer i=0 and j=0
3. Initialize count=0 
4. Iterate till i<n1 and j<n2 
a) if(s[i] >= g[i]) that means number of cookies are greater than number of children, In this case answer is found,
      Find next cookie by doing count++ and i++
b) else if (s[i] < g[i])  if number of children are less than number of cookie 
c) do j++ every time 

5. return count 


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int count =0;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(s[j] >= g[i]){
                count++;
                i++;
            
            }
            j++;
          
          
        }
  return count;
    }
};
