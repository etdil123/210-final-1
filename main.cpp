#include <iostream>
#include <string>
using namespace std;

struct Node {
    string customer_name;
    string drink_order;
    Node * next;
};

// Coffee Booth Functions
// function to insert a Node at the tail - customer joins line
void insertNodeTail(Node * &head, Node * &newCustomer);

// function to delete a customer from head - customer leaves line
void deleteNodeHead(Node * &head);
// function to output each customer
void outputCoffeeLine(Node * &head);
// function to delete the entire linked list
void deleteLinkedList(Node * &head);

int main () {
    // array of random names
    string names[20] = {
        "Alice", "Bob", "Charlie", "Diana", "Evan",
        "Fiona", "George", "Hannah", "Ian", "Julia",
        "Kevin", "Luna", "Mason", "Nora", "Oliver",
        "Penelope", "Quentin", "Ruby", "Sam", "Tina"
    };
    // array of random drinks
    string drinks[20] = {
        "Espresso", "Latte", "Cappuccino", "Americano", "Mocha",
        "Macchiato", "Flat White", "Cold Brew", "Iced Latte", "Frappuccino",
        "Affogato", "Cortado", "Ristretto", "Irish Coffee", "Turkish Coffee",
        "Cafe au Lait", "Long Black", "Doppio", "Vienna Coffee", "Red Eye"
    };



    return 0;
}

// insertNodeTail returns no value - enters a new node at the tail of linked list to simulate a customer entering the line
void insertNodeTail(Node * &head, Node * &newCustomer) {
    Node * curr = head;
    Node * prev = head;

    // if linked list is empty --> make this newCustomer the head 
    if (!head) {
        head = newCustomer;
        // since only 1 item in linked list - need to make it point to nullptr
        newCustomer = nullptr;
    }
    else {
        // traverse the linked list
        while (curr) {
            prev = curr;
            curr = curr->next;
        }
        // at end - now insert between prev and curr
        newCustomer->next = curr;
        prev->next = newCustomer;
    }
}

void deleteNodeHead(Node * &head) {
    // just return the function if there are no elements in linked list
    if (head == nullptr) {
        return;
    }
    // set current to the head
    Node * curr = head;
    // advance the head to the next pointer 
    head = head->next;
    // delete what current points to - the old 
    delete curr;
}


void outputCoffeeLine(Node * &head) {
    
    if (!head) {
        cout << "No customers in coffee line!" << endl;
        return;
    }

    Node * curr = head;
    while (curr) {

        // display curr Node data
        cout << "Customer Name: " << curr->customer_name << " Drink Order: " << curr->drink_order << endl;

        // move curr to next Node to advance through line
        curr = curr->next;
    }

}

void deleteLinkedList(Node * &head) {
    Node * curr = head;

    // while curr is not null
    while(curr) {
        // move head to next and delete curr Node
        head = curr->next;
        delete curr;
        curr = head;
    }
    // make head point to nullptr
    head = nullptr;
}