class Stack {
private:
    // Nodes for a singly-linked list
    class StackNode {
    public:
        int data;
        StackNode *next;
        
        // Constructor
        StackNode(int n) : data(n), next(nullptr) {}
    };

    StackNode *head;
    StackNode *tail;

public:
    // Constructor to initialize the stack
    Stack() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up memory
    ~Stack() {
        while (head != nullptr) {
            StackNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Push operation to insert element at the top of the stack
    bool push(int data) {
        StackNode *new_node = new StackNode(data);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        return true;  
    }

    int pop() {
    int element; // Default value if stack is empty
    if (head != nullptr) {
        // If there's only one node in the list
        if (head == tail) {
            StackNode *temp = head;
            element = temp->data;
            head = nullptr;
            tail = nullptr;
            delete temp;
        } 
        else {
            // If there are more than one node in the list
            StackNode *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            StackNode *temp = tail;
            element = temp->data;
            tail = current;
            tail->next = nullptr;
            delete temp;
        }
    }
    return element; 
}

    void traverse() {
        StackNode *current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};