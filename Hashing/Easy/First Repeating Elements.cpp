Problem Link : https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1
Naive Approach : 
Run two nested loops, the outer loop picks an element one by one, and the inner loop checks whether the element is repeated or not. Once a repeating element is found, break the loops and print the element.
Time Complexity: O(N2) 
Auxiliary Space: O(1)


Efficient Approach :  hashing (unordered_map)
The idea is to use Hash array to store the occurrence of elements. Then traverse the array from left to right and return the first element with occurrence more than 1.

Time Complexity: O(N).
Auxiliary Space: O(N).


class Solution {
  public:
   
    int firstRepeated(int arr[], int n) {
        unordered_map<int,int> umap;
        
    for(int i=0;i<n;i++){
        umap[arr[i]]++;
    }
    
    //logic
    for(int i=0;i<n;i++){
        int key = arr[i];
        auto temp = umap.find(key);
        if(temp->second > 1){
            return i+1;
        }
    }
    return -1;
    }
};
