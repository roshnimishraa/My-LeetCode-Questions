
Efficient Approach :Moore's Voting Algorithm (Majority Element in an Array >(N/2) time

Time Complexity : O(N) + O(N) 
SC : O(1) 

Approach: 

1. Initialize 2 variables:
Count –  for tracking the count of element
Element – for which element we are counting

2. Traverse through the given array.
If Count is 0 then store the current element of the array as Element.
If the current element and Element are the same increase the Count by 1.
If they are different decrease the Count by 1.

3.The integer present in Element should be the result we are expecting 
check the majority element occurences in the array is >N/2 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int element;
        
        int n = nums.size();
        
    for(int i=0;i<n;i++){
        if(count == 0){
            count =1;
            element = nums[i];
            
        }
       else if(nums[i] == element){
            count++;
        }
        else{
                 //(nums[i] != element)  
            count--;
        }

    }
        int count1 = 0;
        //got the majority element 
        for(int i=0;i<n;i++){
            if(nums[i] == element) {
                count1++;
            }
            
            if(count1 > n/2){
                return element;
            }
        }
        return -1;
    }
};


--------------------------------------------------------------------------------------------------------------------------------------

Better Approach : Hashing 
Time Complexity: O(N*logN) + O(N), where N = size of the given array.
Space Complexity: O(N) as we are using a map data structure.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        int n=nums.size();
        int count =0;
        for(int i=0;i<n; i++){
            umap[nums[i]]++;
        }
        
//         iterating through map
        for(auto it: umap){
            if(it.second > (n/2)){
                return it.first; //return key
            }
        }
        return -1;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------

Brute force : Two Inner for loops 
TC : O(N)^2
SC : O(1) 
The steps are as follows:

1. We will run a loop that will select the elements of the array one by one.
2. Now, for each element, we will run another loop and count its occurrence in the given array.
3. If any element occurs more than the floor of (N/2), we will simply return it.



