// ===========================================
// 2. Doubly Linked List
// ===========================================

#include<iostream>
using namespace std;
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void append(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void prepend(int val) {
        DNode* newNode = new DNode(val);
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        while (head) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
