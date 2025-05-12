#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // Insert at specific index
    void insertAtIndex(int index, int val) {
        if (index < 0) {
            std::cerr << "Invalid index\n";
            return;
        }

        if (index == 0) {
            insertAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* curr = head;
        int i = 0;

        while (curr && i < index - 1) {
            curr = curr->next;
            ++i;
        }

        if (!curr) {
            std::cerr << "Index out of bounds\n";
            delete newNode;
            return;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    // Print the list
    void print() {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "null\n";
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtIndex(1, 15); // Insert 15 at index 1

    list.print(); // Expected output: 10 -> 15 -> 20 -> 30 -> null

    return 0;
}