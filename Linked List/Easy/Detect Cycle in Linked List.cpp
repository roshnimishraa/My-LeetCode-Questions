Naive Approach : Hashing 

Time Complexity: O(N)
Reason: Entire list is iterated once.

Space Complexity: O(N)
Reason: All nodes present in the list are stored in a hash table.

  
bool cycleDetect(node* head) {
    unordered_set<node*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()) return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------

  Efficient Approach : slow and fast pointer 
TC : O(N) 
SC : O(1) 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next== NULL){
            return false;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
    
    while(fast != NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }    
        return false;
}
};
