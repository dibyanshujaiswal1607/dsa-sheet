class Solution {
public:
    int length(ListNode* head) {
        int n = 0;
        while(head != nullptr) {
            n++;
            head = head->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = length(head);
        if(n == 0 or k % n == 0)    return head;
        
        k = k % n;
        ListNode* cur = head;
        int cnt = 1;
        while(cnt != n - k) {
            cnt++;
            cur = cur->next;
        }
        ListNode* temp = head;
        head = cur->next;
        cur->next = nullptr;
        cur = head;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = temp;
        return head;
    }
};