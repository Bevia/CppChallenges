#include <iostream>

class Node {
public:
    std::string data;
    Node* next;

    Node(std::string value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert_front(std::string value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void insert_back(std::string value) {
        Node* node = new Node(value);
        if (!head) {
            head = node;
            return;
        }
        Node* current_node = head;
        while (current_node->next) {
            current_node = current_node->next;
        }
        current_node->next = node;
    }

    void insert_at_index(std::string value, int index) {
        Node* node = new Node(value);
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }

        Node* current_node = head;
        int count = 0;

        while (current_node->next && count < index - 1) {
            current_node = current_node->next;
            count++;
        }

        node->next = current_node->next;
        current_node->next = node;
    }

    void print_list() {
        if (!head) {
            std::cout << "Head -> None" << std::endl;
            return;
        }

        Node* current_node = head;
        std::cout << "Head -> ";
        while (current_node) {
            std::cout << current_node->data << " -> ";
            current_node = current_node->next;
        }
        std::cout << "None" << std::endl;
    }

    //This is our destructor for the LinkedList class. 
    //It ensures that all dynamically allocated Node objects are 
    //properly deleted when a LinkedList object is destroyed.
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList ll;
    ll.insert_front("A");
    ll.insert_front("B");
    ll.insert_back("C");
    ll.insert_front("D");
    ll.insert_back("E");
    ll.insert_at_index("H", 2);
    ll.print_list();

    return 0;
}
