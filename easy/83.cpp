/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* nextnode;
        if(curr==NULL) return NULL;
        while(curr->next){
            nextnode=curr->next;
            if(curr->val==nextnode->val){
                if(nextnode->next){
                    curr->next=nextnode->next;
                }
                else curr->next=NULL;
                delete nextnode;
            }
            else curr=curr->next;    
        }
        return head;
        
    }
};