#include <iostream>
using namespace std;

// ===========================================
// 1. Singly Linked List
// ===========================================
struct SNode {
    int data;
    SNode* next;
    SNode(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    SNode* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void append(int val) {
        SNode* newNode = new SNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        SNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void prepend(int val) {
        SNode* newNode = new SNode(val);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        SNode* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~SinglyLinkedList() {
        while (head) {
            SNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
