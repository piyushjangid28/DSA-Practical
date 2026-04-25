#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
};

// Linked List Class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Display list
    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search element
    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Element not found" << endl;
    }

    // Delete node by value
    void delete_node(int key) {
        Node* temp = head;
        Node* prev = NULL;

        // If head node itself holds the key
        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << "Node deleted" << endl;
            return;
        }

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Element not found" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Node deleted" << endl;
    }

    // Reverse linked list
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        cout << "List reversed" << endl;
    }
};

// Main function
int main() {
    LinkedList list;

    list.insert_at_beginning(10);
    list.insert_at_beginning(20);
    list.insert_at_beginning(30);

    cout << "Original List: ";
    list.display();

    list.search(20);

    list.delete_node(20);
    cout << "After Deletion: ";
    list.display();

    list.reverse();
    cout << "After Reversal: ";
    list.display();

    return 0;
}