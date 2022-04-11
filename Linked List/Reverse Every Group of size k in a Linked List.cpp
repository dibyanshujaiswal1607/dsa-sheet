class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr or k == 1)   return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *cur = dummy, *next = dummy, *prev = dummy;
        int count = 0;
        while(cur->next != nullptr) {
            count++;
            cur = cur->next;
        }
        
        while(count >= k) {
            cur = prev->next;
            next = cur->next;
            for(int i = 1; i < k; i++) {
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = cur->next;
            }
            prev = cur;
            count -= k;
        }
        return dummy->next;
    }
};