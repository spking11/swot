class MyLinkedList {
  public:
    MyLinkedList() {}

    int get(int index) {
        if (index < 0)
            return -1;
        if (_head == nullptr)
            return -1;
        auto node = _head;
        while (index--) {
            if (node == nullptr || node->next == nullptr)
                return -1;
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val) { _head = new ListNode(val, _head); }

    void addAtTail(int val) {
        if (_head == nullptr) {
            addAtHead(val);
            return;
        }
        auto node = _head;
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = new ListNode(val, nullptr);
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (_head == nullptr)
            return;
        auto node = _head;
        while ((index--) - 1) {
            if (node == nullptr || node->next == nullptr) {
                return;
            }
            node = node->next;
        }
        node->next = new ListNode(val, node->next);
    }

    void deleteAtIndex(int index) {
        if (index < 0 || _head == nullptr)
            return;
        if (index == 0) {
            auto temp = _head;
            _head = _head->next;
            delete temp;
            return;
        }
        auto node = _head;
        while ((index--) - 1) {
            if (node == nullptr || node->next == nullptr) {
                return;
            }
            node = node->next;
        }
        if (node->next == nullptr)
            return;
        auto temp = node->next;
        node->next = node->next->next;
        delete temp;
    }

  private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    } *_head = nullptr;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    MyLinkedList linkedList = *new MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2); //链表变为1-> 2-> 3
    linkedList.get(1);           //返回2
    linkedList.deleteAtIndex(1); //现在链表是1-> 3
    linkedList.get(1);           //返回3
    return 0;
}