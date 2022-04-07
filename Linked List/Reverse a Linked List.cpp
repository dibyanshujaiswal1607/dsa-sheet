#include <bits/stdc++.h>
using namespace std;

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
};