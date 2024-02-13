class Stack {
  private:
    // Nodes for a singly-linked list
    class StackNode {
      public: int data;
      StackNode * next;

      // Constructor
      StackNode(int n): data(n),
      next(nullptr) {}
    };

  StackNode * head;

  public:
    // Constructor to initialize the stack
    Stack(): head(nullptr) {}

    // Destructor to clean up memory
    ~Stack() {
      while (head != nullptr) {
        StackNode * temp = head;
        head = head -> next;
        delete temp;
      }
    }

  // Check if the stack is empty
  bool isEmpty() {
    return head == nullptr;
  }

  // Push operation to insert element at the top of the stack
  bool push(int data) {
    StackNode * new_node = new StackNode(data);
    StackNode * current = head;
    //if the stack is empty 
    if (head == nullptr) {
      head = new_node;
    }
    //stack is not empty, traverse the LL and insert the new node at the last element;
    else {
      while (current -> next != nullptr) {
        current = current -> next;
      }
      current -> next = new_node;
    }
    return true; 
  }

bool pop() {
  if (head == nullptr) {
    return false;
  } else if (head -> next == nullptr) {
    delete head;
    head = nullptr;
  } else {
    StackNode * current = head;
    while (current -> next -> next != nullptr) {
      current = current -> next;
    }
    delete current -> next;
    current -> next = nullptr;
  }
  return true;
}

int peek() {
  int element;
  StackNode * current = head;
  if (head == nullptr) {
    return 999;
  } else {
    while (current -> next != nullptr) {
      current = current -> next;
    }
    element = current -> data;
  }
  return element;
}
//TRAVERSE ISNT REAL
void traverse() {
  StackNode * current = head;
  while (current != nullptr) {
    std::cout << current -> data << " -> ";
    current = current -> next;
  }
  std::cout << "nullptr" << std::endl;
}
};
