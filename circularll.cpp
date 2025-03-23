#include<iostream>
using namespace std;

// ===========================================
// 3. Circular Singly Linked List
// ===========================================
struct CSNode {
    int data;
    CSNode* next;
    CSNode(int val) : data(val), next(nullptr) {}
};

class CircularSinglyLinkedList {
    CSNode* head;
public:
    CircularSinglyLinkedList() : head(nullptr) {}

    void append(int val) {
        CSNode* newNode = new CSNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CSNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (!head) return;
        CSNode* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)\n";
    }

    ~CircularSinglyLinkedList() {
        if (!head) return;
        CSNode* current = head;
        CSNode* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        head = nullptr;
    }
};

// ===========================================
// 4. Circular Doubly Linked List
// ===========================================
struct CDNode {
    int data;
    CDNode* prev;
    CDNode* next;
    CDNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class CircularDoublyLinkedList {
    CDNode* head;
public:
    CircularDoublyLinkedList() : head(nullptr) {}

    void append(int val) {
        CDNode* newNode = new CDNode(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        CDNode* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void display() {
        if (!head) return;
        CDNode* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)\n";
    }

    ~CircularDoublyLinkedList() {
        if (!head) return;
        CDNode* current = head;
        CDNode* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        head = nullptr;
    }
};