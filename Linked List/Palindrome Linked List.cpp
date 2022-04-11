class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = nullptr;
        while(head != nullptr) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr and fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow != nullptr) {
            if(head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};