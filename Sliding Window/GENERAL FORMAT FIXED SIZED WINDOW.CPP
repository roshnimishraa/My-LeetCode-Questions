
Given Window Size (K)
Window == k 

 Approach :
1. Find out calculations
2. ans <- calculation
3. slide the window 

  
int i=0,j=0
while(j<size) {
  calculations 
  if(j-i+1 < k)
  { j++  
  } 
    else if (j-i+1 == k) {
calculation -> ans 
  calculation remove for i
 Window size maintain 
 slide the window 
    }
return ans 
    
        }
          
