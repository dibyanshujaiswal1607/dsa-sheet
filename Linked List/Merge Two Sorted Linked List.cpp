#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)    return list2;
        if(list2 == nullptr)    return list1;
        if(list1->val > list2->val) {
            swap(list1, list2);
        }
        ListNode* head = list1;
        while(list1 != nullptr and list2 != nullptr) {
            ListNode* temp = nullptr;
            while(list1 != nullptr and list1->val <= list2->val) {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return head;
    }
};