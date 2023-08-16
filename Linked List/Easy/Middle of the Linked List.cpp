Naive Approach:

We can traverse through the Linked List while maintaining a count of nodes let’s say in variable n, and then
traversing for 2nd time for n/2 nodes to get to the middle of the list.

  
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        		temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        		temp = temp->next;
    	}
   	 
    	return temp;
	}
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------

  
Efficient Approach : Tortoise-Hare-Approach
  
Time Complexity: O(N)
Space Complexity: O(1)

  
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
             fast=fast->next->next;
            slow = slow->next;
         
        }
        return slow;
    }
};
