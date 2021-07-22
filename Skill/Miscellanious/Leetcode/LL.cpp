typedef struct {
    int val;
    Node * next;
} Node;
class MyLinkedList {
    Node *head;
    int sz;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        sz = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < sz) {
            Node *cur = head;
            while(cur and index) {
                index--;
                cur = cur->next;
            }
            return cur->val;
        } else {
            return -1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *node = new Node();
        node->val = val;
        node->next = head;
        head = node;
        sz++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *node = new Node();
        node->val = val;
        Node *cur = head;
        while(cur) {
            cur = cur->next;
        }
        cur->next = node;
        sz++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node *node = new Node();
        node->val = val;
        Node *cur = head;
        --index;
        while(cur and index) {
            --index;
            cur = cur->next;
        }
        if(index) {
            
        } else {
           if(cur) {
               Node *tmp = cur->next;
               cur->next = node;  
               node->next = tmp;
           } else {
               //Not possible
           }
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= sz)return;
        Node *cur = head;
        Node *prev = NULL;
        while(cur and index) {
            prev = cur;
            cur = cur->next;
            --index;
        }
        prev->next = cur->next;
        delete cur;
        sz--;
        
    }
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