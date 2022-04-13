class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        
        Node* cur = head;
        // inserting duplicate nodes in between
        while(cur != nullptr) {
            Node* temp = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = temp;
            cur = temp;
        }
        cur = head;
        // setting random pointers of new nodes
        while(cur != nullptr) {
            if(cur->next != nullptr) {
                cur->next->random = cur->random != nullptr ? cur->random->next : nullptr;
            }
            cur = cur->next->next;
        }
        Node *orig = head, *copy = head->next;
        Node* temp = copy;
        // seperating both linked lists
        while(copy->next != nullptr) {
            orig->next = orig->next->next;
            copy->next = copy->next->next;
            orig = orig->next;
            copy = copy->next;
        }
        orig->next = nullptr;
        return temp;
    }
};