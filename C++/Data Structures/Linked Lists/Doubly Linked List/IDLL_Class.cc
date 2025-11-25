#include <iostream>

// Node structure for doubly linked list
class __DNode__ {
 public:
  int data;
  __DNode__* next;
  __DNode__* prev;

  // Constructor
  __DNode__(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class __Doubly_Linked_List__ {
 private:
  __DNode__* head;
  __DNode__* tail;

 public:
  // Constructor to initialize an empty list
  __Doubly_Linked_List__() : head(nullptr), tail(nullptr) {}

  // Insert node at the beginning
  void __Insert_Beginning__(int value) {
    __DNode__* newNode = new __DNode__(value);
    if (!head) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  // Insert node at the end
  void __Insert_End__(int value) {
    __DNode__* newNode = new __DNode__(value);
    if (!tail) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  // Display the list from head to tail
  void __Display__() const {
    if (!head) {
      std::cout << "\nList is empty.\n";
      return;
    }
    __DNode__* temp = head;
    std::cout << "\nDoubly Linked List: [head]: ";
    while (temp) {
      std::cout << "<--{" << temp->data << "}-->";
      temp = temp->next;
    }
    std::cout << " --> [NULL]\n";
  }

  // Remove Duplicates
  void __Remove_Duplicates__() {
    if (!head) {
      std::cout << "\nList is empty. No duplicates to remove.\n";
      return;
    }
    __DNode__* current = head;
    while (current) {
      __DNode__* runner = current->next;
      while (runner) {
        if (current->data == runner->data) {
          // Remove the duplicate node
          if (runner == tail) {
            tail = runner->prev;  // Update tail if removing the last node
          }
          if (runner->next) {
            runner->next->prev = runner->prev;
          }
          if (runner->prev) {
            runner->prev->next = runner->next;
          }
          __DNode__* temp = runner;
          runner = runner->next;
          delete temp;  // Free the memory of the duplicate node
        } else {
          runner = runner->next;
        }
      }
      current = current->next;
    }
    std::cout << "\nDuplicates removed successfully.\n";
  }

  // Merge another list into the current list
  void __Merge__(__Doubly_Linked_List__& other) {
    if (!other.head) return;  // No nodes to merge

    // If current list is empty, just set the current list's head and tail to
    // the other list
    if (!head) {
      head = other.head;
      tail = other.tail;
      other.head = other.tail = nullptr;
      return;
    }
    // Otherwise, merge lists by connecting the tail of the current list to the
    // head of the other list
    tail->next = other.head;
    other.head->prev = tail;
    tail = other.tail;

    // Clear the other list
    other.head = other.tail = nullptr;

    std::cout << "\nLists merged successfully.\n";
  }

  // Delete the entire list
  void __Delete_List__() {
    while (head) {
      __DNode__* temp = head;
      head = head->next;
      delete temp;  // Free memory of the node
    }
    tail = nullptr;
    std::cout << "\nDoubly linked list deleted successfully.\n";
  }

  // Delete node from the beginning
  void __Delete_Beginning__() {
    if (!head) {
      std::cout << "\nList is empty. Nothing to delete.\n";
      return;
    }
    __DNode__* temp = head;
    if (head == tail) {
      head = tail = nullptr;
    } else {
      head = head->next;
      head->prev = nullptr;
    }
    delete temp;
    std::cout << "\nDeleted from beginning.\n";
  }

  // Delete node from the end
  void __Delete_End__() {
    if (!tail) {
      std::cout << "\nList is empty. Nothing to delete.\n";
      return;
    }
    __DNode__* temp = tail;
    if (head == tail) {
      head = tail = nullptr;
    } else {
      tail = tail->prev;
      tail->next = nullptr;
    }
    delete temp;
    std::cout << "\nDeleted from end.\n";
  }

  // Search for an element (returns index or -1)
  int __Search_Element__(int target) const {
    int index = 0;
    __DNode__* temp = head;
    while (temp) {
      if (temp->data == target) {
        return index;
      }
      temp = temp->next;
      index++;
    }
    return -1;
  }

  // Pairwise swap nodes by swapping their data
  void __Pairwise_Swap__() {
    if (!head || !head->next) return;  // No need to swap if there's 0 or 1 node

    __DNode__* current = head;
    while (current && current->next) {
      // Swap data between the current node and the next node
      int temp = current->data;
      current->data = current->next->data;
      current->next->data = temp;

      // Move to the next pair (skip two nodes)
      current = current->next->next;
    }
    std::cout << "\nPairwise swap of data completed successfully.\n";
  }

  // Reverse the linked list
  void __Reverse_List__() {
    if (!head) return;  // Nothing to reverse if list is empty

    __DNode__* current = head;
    __DNode__* temp = nullptr;

    while (current != nullptr) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
    if (temp != nullptr) {
      head = temp->prev;
    }
    std::cout << "\nDoubly linked list reversed successfully.\n";
  }

  // Destructor to ensure all dynamically allocated memory is freed
  ~__Doubly_Linked_List__() { __Delete_List__(); }
};

// Main function to demonstrate the Doubly Linked List operations
int main() {
  __Doubly_Linked_List__ list1, list2;

  // Insert values into list1
  list1.__Insert_Beginning__(10);
  list1.__Insert_End__(20);
  list1.__Insert_End__(30);
  list1.__Insert_End__(50);
  list1.__Insert_End__(60);

  // Insert values into list2
  list2.__Insert_Beginning__(40);
  list2.__Insert_End__(50);
  list2.__Insert_End__(40);
  list2.__Insert_End__(30);
  list2.__Insert_End__(10);

  // Display both lists
  std::cout << "List 1:\n";
  list1.__Display__();

  std::cout << "List 2:\n";
  list2.__Display__();

  // Merge list2 into list1
  list1.__Merge__(list2);

  // Display the merged list
  std::cout << "\nAfter merging List 2 into List 1:\n";
  list1.__Display__();

  // Remove duplicates
  list1.__Remove_Duplicates__();
  list1.__Display__();

  // Reverse and display list after merging
  list1.__Reverse_List__();
  list1.__Display__();

  // Pairwise swap nodes
  list1.__Pairwise_Swap__();
  list1.__Display__();

  return 0;
}
