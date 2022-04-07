#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode *slow = start, *fast = start;
        while(n--) {
            fast = fast->next;
        }
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};