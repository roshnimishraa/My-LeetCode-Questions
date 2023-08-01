Brute Force : Linear search 
 TC : O(log N) 

int floorSqrt(int n) {
    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

-----------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Binary Search 

1. First Approach(Using in-built sqrt() function): 
  Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using the Binary Search algorithm.

Space Complexity: O(1) as we are not using any extra space.

int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}

-----------------------------------------------------------------------------------------------------------------------------------

2. Optimal Approach(Using binary search): 
 TC : O(log N) 

n= 28 
a) 1 .............14................28
b) 1.......7....13
c) 1...3..6
d) 4 5 6
e) 6 
f) 5 6  low > high -> stop 
ans = 5
always high will be the answer 

int floorSqrt(int n)
{
 long long low = 1;
 long long high = n;
 
    while(low <= high){
       long long mid = low + (high-low)/2;
       long long val = mid * mid;
     if(val <= n){
         low = mid+1;
     }
     else {
         high = mid -1;
     }
    }
    return high;
}


