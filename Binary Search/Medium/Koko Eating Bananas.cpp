Problem link : https://leetcode.com/problems/koko-eating-bananas/

Koko Eating Bananas -> Return the minimum integer K such that Koko can eat all bananas in h ours.
k-> bananas/hr
take ceil of hours

Naive Approach(Brute-force): Linear Search 
The extremely naive approach is to check all possible answers from 1 to max(a[]). The minimum number for which the required time <= h, is our answer.

Time Complexity: O(max(a[]) * N), where max(a[]) is the maximum element in the array and N = size of the array.
Space Complexity: O(1) 

Algorithm:
1.	First, we will find the maximum value i.e. max(a[]) in the given array.
2.	We will run a loop(say i) from 1 to max(a[]), to check all possible answers.
3.	For each number i, we will calculate the hours required to consume all the bananas from the pile. We will do this using the function calculateTotalHours(), discussed below.
4.	The first i, for which the required hours <= h, we will return that value of i.


calculateTotalHours(a[], hourly):
•	a[] -> the given array
•	Hourly -> the possible number of bananas, Koko will eat in an hour.
1.	We will iterate every pile of the given array using a loop(say i).
2.	For every pile i, we will calculate the hour i.e. ceil(v[i] / hourly), and add it to the total hours.
3.	Finally, we will return the total hours.


---------------------------------------------------------------------------------------------------------------------------------------------------------------


Efficient Approach : Binary Search 

Time Complexity: O(N * log(max(a[]))) 

Space Complexity: O(1
 
for arr[] = [3 6 7 11] h = 8 
so, the maximum possible answer(answer will always point to low) can be from 1 to 11 max(arr)

#include<bits/stdc++.h>

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
//It is given that I need to find min. integer such that koko can eat 
// all bananas within an hour therefore we have to go LEFT for min. 
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

