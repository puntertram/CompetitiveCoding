#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
struct Node{
    int val;
    Node* next; 
};
void push(Node** head_ref, int data) {
    Node* node = new Node;
    node->val = data;
    node->next = *head_ref;
    // (*head_ref) = node;
    head_ref = &node;
    cout << "hello\n";
}
void printList(Node* head) {
    while(head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL\n";
}
void printMiddle(Node *head) {
    Node *ptr1 = head, *ptr2 = head;
    while(ptr2 and ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = (ptr2->next)->next;
    }
    cout << "middle element is " << ptr1->val << endl;
}
int main() {
    Node* head = NULL;
    for(int i = 0 ; i < 10; i++) {
        push(&head, 10 - i);
    }
    printList(head);
    printMiddle(head);
    return 0;
}