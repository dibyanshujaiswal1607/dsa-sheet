Node* mergeTwoLists(Node* list1, Node* list2) {
    if(list1 == nullptr)    return list2;
    if(list2 == nullptr)    return list1;
    if(list1->data > list2->data) {
        swap(list1, list2);
    }
    Node* head = list1;
    while(list1 != nullptr and list2 != nullptr) {
        Node* temp = nullptr;
        while(list1 != nullptr and list1->data <= list2->data) {
            temp = list1;
            list1 = list1->bottom;
        }
        temp->bottom = list2;
        swap(list1, list2);
    }
    return head;
}
Node *flatten(Node *root) {
   Node *temp = root;
   while(temp->next != NULL) {
       temp = temp->next;
       root = mergeTwoLists(root, temp);
   }
   return root;
}