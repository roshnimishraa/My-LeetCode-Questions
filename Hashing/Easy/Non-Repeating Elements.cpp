Problem Link: https://practice.geeksforgeeks.org/problems/non-repeating-element3958/1

Naive Approach 
 The idea is to use two nested loops, The outer loop picks elements one by one and the inner loop checks if the element is present more than once or not..
Time Complexity: O(N2), Where N is the length of the given array
Auxiliary Space: O(1)

-------------------------------------------------------------------------------------------------------------------------
Efficient Approach: Hashing 

1. The idea is to store the frequency of every element in the hashmap.
2. Then check the first element whose frequency is 1 in the hashmap.
3. This can be achieved using hashing

->Traverse array and insert elements and their counts in the hash table.
->Traverse array again and print the first element with a count equal to 1.

Time Complexity: O(2n), Traverse over the array to map the frequency and again traverse over the array to check for frequency.
Auxiliary Space: O(n), Create a hash table for storing frequency

class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        unordered_map<int,int> umap;
  //Traverse array and insert elements and their 
  //counts in the hash table.
  for(int i=0;i<n;i++){
      umap[arr[i]]++;
      
  }


//Traverse array again and print the first
//element with a count equal to 1.
for(int i=0;i<n;i++){
    int key = arr[i];
    auto temp = umap.find(key);
    if(temp->second ==1){
        return key;
    }
}
   return 0;  
    } 
  
};
