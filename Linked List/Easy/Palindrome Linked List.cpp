Naive Approach : Using the extra data structure

Time Complexity: O(N)
Reason: Iterating through the list to store elements in the array.
Space Complexity: O(N)
Reason: Using an array to store list elements for further computations.

LOGIC :  
1. We can store elements in an array. Then check if the given array is a palindrome. 
2. Iterate through the given list to store it in an array.
3. Iterate through the array.
4. For each index in range of n/2 where n is the size of the array
5. Check if the number in it is the same as the number in the n-index-1 of the array.

  bool isPalindrome(node* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->num);
        head = head->next;
    }
    for(int i=0;i<arr.size()/2;i++) 
      //cOMPARING LEFT AND RIGHT(n-i-1) HALF OF AN ARRAY
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach : 
1. Find the middle element of the linked list.
2. Reverse a linked list from the next element of the middle element. 
3. Iterate through the new list until the middle element reaches the end of the list.
4. Use a dummy node to check if the same element exists in the linked list from the middle element.

TC : O(n/2) + O(n/2) + O(n/2) 
SC : O(1) 
  
class Solution {
  ListNode *reverseList(ListNode *head){
 
      ListNode *prev=NULL;
      ListNode *curr = head;
     ListNode *next = NULL;
      while(curr != NULL){
          next = curr->next;
          curr->next=prev;
          prev = curr;
          curr =next;
      }
     return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow =head;
        ListNode *fast=head;
        
        if(head == NULL || head->next == NULL){
            return true;
        }
//till fast reaches last and second last
    while(fast->next != NULL && fast->next->next != NULL)
    {
slow = slow->next;
fast = fast->next->next;
    }

    slow ->next = reverseList(slow->next);
        //move slow by one 
     slow = slow->next;
        
    while(slow != NULL){
        //comparing left half and right half 
    if(head->val != slow->val)
    {
        return false; 
    }

        head = head->next;
        slow = slow->next;
 
    }
                return true;
    }
};
