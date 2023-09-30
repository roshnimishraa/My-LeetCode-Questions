TC : O(N) 
SC : O(1) 

Algorithm : TWO POINTER APPROACH 
1. Take two pointer slow and fast initially pointing to head
2. Take a pointer prev assigned NULL
3. Handle Corner case if head == NULL || head-> next == NULL then return NULL
4. Move fast pointer by 2 step and mark prev = slow and  slow pointer by one step 
5. slow is pointing to middle element remove link by 
    prev->next = prev->next->next 
6. return head 

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast = head;
        ListNode *prev = NULL;
//         corner case 
    if(head == NULL || head->next == NULL) return NULL;
    while(fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;        
        slow = slow->next;      
    }
    //slow mid ko point kr rha h 
        prev -> next = prev->next->next;
        return head;
        
        }
};
