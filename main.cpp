#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>
using namespace std;

struct Node {
    string customer_name;
    string drink_order;
    Node * next;
};

struct Customer {
    string customer_name;
    string order;
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

// Muffin Booth Functions
void displayDeque(deque<Customer>, int size);

// Bracelet Booth Functions
void displayVec(vector<Customer>, int size);

// Ice Cream Booth Functions
void displayList(list<Customer>);

int main () {
    // Constants to store number of each data arrays
    int NAMES = 20;
    int DRINKS = 20;
    int MUFFINS = 10;
    int COLORS = 20;
    int ICECREAM = 20;


    int ROUNDS = 10;
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
    // array of random muffin flavors
    string muffins[10] = {
        "Blueberry", "Chocolate Chip", "Banana Nut", 
        "Lemon Poppy Seed", "Cranberry Orange", 
        "Pumpkin Spice", "Apple Cinnamon", 
        "Double Chocolate", "Vanilla Bean", "Strawberry"
    };
    // array of random bracelet colors for order
    string braceletColors[20] = {
        "Red", "Blue", "Green", "Yellow", "Purple",
        "Orange", "Pink", "Brown", "Black", "White",
        "Gray", "Cyan", "Magenta", "Teal", "Maroon",
        "Navy", "Gold", "Silver", "Olive", "Beige"
    };
    // array of Ice Cream flavors
    string iceCreamFlavors[20] = {
        "Vanilla", "Chocolate", "Strawberry", "Mint Chocolate Chip", "Cookie Dough",
        "Rocky Road", "Butter Pecan", "Cookies and Cream", "Pistachio", "Caramel",
        "Mango", "Coffee", "Lemon", "Raspberry", "Peach",
        "Blackberry Cheesecake", "Coconut", "Salted Caramel", "Tiramisu", "Chocolate Fudge Brownie"
    };

    // initializes linked list to store coffee shop
    Node *head = nullptr;
    // initialize deque to store muffin shop
    deque<Customer> muffinsDeque;
    // initialize vector to store bracelets
    vector<Customer> braceletsVec;
    // Initialize list (std::list) to store ice cream flavors
    list<Customer> iceCreamList;

    // Populate queue with 3 customers
    for (int i = 0; i < 3; i++) {
        // Populate Coffee Shop
        int randNamesArrIndexCoffee = (rand() % NAMES);
        int randDrinksArrIndexCoffee = (rand() % DRINKS);

        Node *newCustomer = new Node;
        newCustomer->customer_name = names[randNamesArrIndexCoffee];
        newCustomer->drink_order = drinks[randDrinksArrIndexCoffee];
        newCustomer->next = nullptr;
        // enter new coffee customer into linked list
        insertNodeTail(head, newCustomer);

        // Populate Deque with muffin information
        int randNamesArrIndexMuffin = (rand() % NAMES);
        int randDrinksArrIndexMuffin = (rand() % MUFFINS);
        Customer tempMuffin;
        tempMuffin.customer_name = names[randNamesArrIndexMuffin];
        tempMuffin.order = muffins[randDrinksArrIndexMuffin];
        // enter the new customer into deque
        muffinsDeque.push_back(tempMuffin);

        // Populate Vector with bracelet information
        int randNamesArrIndexBracelet = (rand() % NAMES);
        int randColorArrIndexBracelet = (rand() % COLORS);
        Customer tempBracelet;
        tempBracelet.customer_name = names[randNamesArrIndexBracelet];
        tempBracelet.order = braceletColors[randColorArrIndexBracelet];
        // enter new bracelet customer into vector
        braceletsVec.push_back(tempBracelet);

        // Populate List with Ice Cream info
        int randNamesArrIndexIceCream = (rand() % NAMES);
        int randFlavorArrIndexIceCream = (rand() % ICECREAM);
        Customer tempIceCream;
        tempIceCream.customer_name = names[randNamesArrIndexIceCream];
        tempIceCream.order = iceCreamFlavors[randFlavorArrIndexIceCream];
        // enter ice cream customer information into List object
        iceCreamList.push_back(tempIceCream);
    }

    // Simulation of 10 rounds
    for (int k = 0; k < ROUNDS; k++) {

        cout << "\nRound # " << k + 1 << ": " << endl;

        // get a random probability between 0 and 100
        int prob = rand() % 100 + 1;

        // If probability less or equal to 50 - customer at front leaves AND new customer joins the end of line
        if (prob <= 50) {
            //// COFFEE /////
            // remove the first person in line
            deleteNodeHead(head);
            // somebody joined the queue
            int randNamesArrIndex = (rand() % NAMES);
            int randDrinksArrIndex = (rand() % DRINKS);

            Node *newCustomer = new Node;
            newCustomer->customer_name = names[randNamesArrIndex];
            newCustomer->drink_order = drinks[randDrinksArrIndex];
            newCustomer->next = nullptr;

            insertNodeTail(head, newCustomer);

            //// Muffin /////
            // remove first person in line
            if (!muffinsDeque.empty()) {
                muffinsDeque.pop_front();
            }

            // Populate Deque with muffin information
            int randNamesArrIndexMuffin = (rand() % NAMES);
            int randDrinksArrIndexMuffin = (rand() % MUFFINS);
            Customer tempMuffin;
            tempMuffin.customer_name = names[randNamesArrIndexMuffin];
            tempMuffin.order = muffins[randDrinksArrIndexMuffin];

            muffinsDeque.push_back(tempMuffin);

            //// Bracelet ////
            // remove first person in bracelet line
            if (!braceletsVec.empty()) {
                braceletsVec.erase(braceletsVec.begin());
            }

            // Populate Vector with new bracelet customer
            int randNamesArrIndexBracelet = (rand() % NAMES);
            int randColorArrIndexBracelet = (rand() % COLORS);
            Customer tempBracelet;
            tempBracelet.customer_name = names[randNamesArrIndexBracelet];
            tempBracelet.order = braceletColors[randColorArrIndexBracelet];
            // enter new bracelet customer into vector
            braceletsVec.push_back(tempBracelet);

            //// Ice Cream //// 
            if (!iceCreamList.empty()) {
                iceCreamList.pop_front();
            }

             // Populate List with Ice Cream info
            int randNamesArrIndexIceCream = (rand() % NAMES);
            int randFlavorArrIndexIceCream = (rand() % ICECREAM);
            Customer tempIceCream;
            tempIceCream.customer_name = names[randNamesArrIndexIceCream];
            tempIceCream.order = iceCreamFlavors[randFlavorArrIndexIceCream];
            // enter ice cream customer information into List object
            iceCreamList.push_back(tempIceCream);

        }
        // else customer at start of line leaves ONLY
        else {
            ////// Coffee ////
            // remove the first person in line
            deleteNodeHead(head);

            //// Muffin ////
            muffinsDeque.pop_front();

            //// Bracelet ////
            braceletsVec.erase(braceletsVec.begin());

            //// Ice Cream ///
            iceCreamList.pop_front();
        }

        cout << "Coffee Line: " << endl;
        outputCoffeeLine(head);
        cout << "Muffin Line: " << endl;
        displayDeque(muffinsDeque, muffinsDeque.size());
        cout << "Bracelets Line: " << endl;
        displayVec(braceletsVec, braceletsVec.size());
        cout << "Ice Cream Line: " << endl;
        displayList(iceCreamList);

        cout << endl;

    }


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
        cout << "   >Name: " << curr->customer_name << "  |  Order: " << curr->drink_order << endl;

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


void displayDeque(deque<Customer> customerDeque, int size){
    // if the deque is empty - print out empty
    if (customerDeque.empty() == true) {
        cout << "No customer in muffin line!";
        
    }
    else {
        // for each element in deque - display information
        for (int i = 0; i < size; i++) {
            cout << "   >Name: " << customerDeque[i].customer_name << "  |  Order: " << customerDeque[i].order << endl;
        }
    }
}

void displayVec(vector<Customer> braceletsVec, int size) {
    // if vector is empty - print out that it is
    if (braceletsVec.empty() == true) {
        cout << "No customer in bracelets line!" << endl;
    }

    else {
        // for each element in the vector - print out the information
        for (int i = 0; i < size; i++) {
            cout << "   >Name: " << braceletsVec[i].customer_name <<  "  |  Order: " << braceletsVec[i].order << endl;
        }
    }
}

void displayList(list<Customer> customerList){
    // if list is empty display that to the user
    if (customerList.empty() == true) {
        cout << "No customer in ice cream line!" << endl;
    }
    else {

        // for each element display customer information
        for (auto customer : customerList ) {
            cout << "   >Name: " << customer.customer_name << "  |  Order: " << customer.order << endl;
        }

    }


}