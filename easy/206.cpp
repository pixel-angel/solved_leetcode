class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* p = curr->next;
            curr->next = prev;
            prev = curr;
            curr = p;
        }
        
        return prev;
    }
};