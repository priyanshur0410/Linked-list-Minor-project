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

// ===========================================
// 2. Doubly Linked List
// ===========================================
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

// ===========================================
// Main Function to Test All Implementations
// ===========================================
int main() {
    cout << "Singly Linked List:\n";
    SinglyLinkedList sll;
    sll.append(1);
    sll.append(2);
    sll.prepend(0);
    sll.display();

    cout << "\nDoubly Linked List:\n";
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.prepend(0);
    dll.display();

    cout << "\nCircular Singly Linked List:\n";
    CircularSinglyLinkedList csll;
    csll.append(1);
    csll.append(2);
    csll.append(3);
    csll.display();

    cout << "\nCircular Doubly Linked List:\n";
    CircularDoublyLinkedList cdll;
    cdll.append(1);
    cdll.append(2);
    cdll.append(3);
    cdll.display();

    return 0;
}