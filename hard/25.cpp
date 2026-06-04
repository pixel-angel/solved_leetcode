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

    ListNode* reverse(ListNode* head, ListNode* stop) {
        ListNode* prev = stop;
        ListNode* curr = head;
        while(curr != stop) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode temp(0);
        temp.next = head;

        ListNode* prevTail = &temp;
        ListNode* temp_head = head;

        while(temp_head) {
            // check if k nodes exist
            ListNode* curr = temp_head;
            for(int i = 0; i < k; i++) {
                if(curr==NULL)
                    return temp.next;
                curr = curr->next;
            }
            // reverse current k-group
            ListNode* newHead = reverse(temp_head, curr);
            // connect previous list
            prevTail->next = newHead;
            // move prevTail
            prevTail = temp_head;
            // next group starts from curr
            temp_head = curr;
        }

        return temp.next;
    }
};