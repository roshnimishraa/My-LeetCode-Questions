Brute Force Approach : 
Approach: 
•	Use a for loop of ‘i’ from 0 to n.
•	Use another for loop of j from ‘i+1’ to n.
•	If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
•	Return maxPro.


Efficient Approach : 
TC :  O(N) 
SC :O(1) 

    Algo : 
1. First find the min price
2. then price[i]-min = maxProfit
3. return maxProfit

    
class Solution {
public:
    int maxProfit(vector<int>& prices) {
 int maxPro = 0;
    int n = prices.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    
    return maxPro;
    }
};
