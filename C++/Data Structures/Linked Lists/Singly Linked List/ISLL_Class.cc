#include <iostream>

// Node structure for integer linked list
class __Node__ {
public:
  int data;
  __Node__ *next;

  __Node__(int value) : data(value), next(nullptr) {}
};

// LinkedList class
class __Linked_List__ {
private:
  __Node__ *head;

public:
  __Linked_List__() : head(nullptr) {}

  // Insert node at the beginning (returns new head)
  void __Insert_Beginning__(int value) {
    __Node__ *new_node = new __Node__(value);
    new_node->next = head;
    head = new_node;
  }

  // Insert node at the end
  void __Insert_End__(int value) {
    __Node__ *new_node = new __Node__(value);
    if (!head) {
      head = new_node;
    } else {
      __Node__ *temp = head;
      while (temp->next) {
        temp = temp->next;
      }
      temp->next = new_node;
    }
  }

  // Display list
  void __Display__() const {
    if (!head) {
      std::cout << "\nList is empty.\n";
      return;
    }
    __Node__ *temp = head;
    int size = 0;
    std::cout << "\nLinked List: [head]: ";
    while (temp) {
      std::cout << "-->{ " << temp->data << " } ";
      temp = temp->next;
      size++;
    }
    std::cout << " --> [NULL]";
    std::cout << "  Size: " << size << "\n";
  }

  // Merge two sorted linked lists
  void __Merge__(__Linked_List__ &other) {
    if (!head) {
      head =
          other.head; // If the first list is empty, just take the second list
      other.head = nullptr; // Clear the second list to prevent double-free
      return;
    }
    // Traverse to the end of the current list (this list)
    __Node__ *temp = head;
    while (temp->next) {
      temp = temp->next;
    }

    // Append the second list to the end of the first list
    temp->next = other.head;
    other.head =
        nullptr; // Avoid double-free by clearing the second list's head
    std::cout << "\nMerged two lists.\n";
  }

  // Delete the entire list
  void __Delete_List__() {
    __Node__ *temp;
    while (head) {
      temp = head;
      head = head->next;
      delete temp; // Free memory of the node
    }
    std::cout << "\nLinked list deleted successfully.\n";
  }

  // Delete node from the beginning
  void __Delete_Beginning__() {
    if (!head) {
      std::cout << "\nList is empty. Nothing to delete.\n";
      return;
    }
    __Node__ *temp = head;
    head = head->next;
    delete temp; // Free memory of the node
    std::cout << "\nDeleted from beginning.\n";
  }

  // Delete node from the end
  void __Delete_End__() {
    if (!head) {
      std::cout << "\nList is empty. Nothing to delete.\n";
      return;
    }
    if (!head->next) {
      delete head; // Free memory of the last node
      head = nullptr;
      std::cout << "\nDeleted from end.\n";
      return;
    }
    __Node__ *temp = head;
    while (temp->next && temp->next->next) {
      temp = temp->next;
    }
    delete temp->next; // Free memory of the last node
    temp->next = nullptr;
    std::cout << "\nDeleted from end.\n";
  }

  // Search for an element (returns index or -1)
  int __Search_Element__(int target) const {
    int index = 0;
    __Node__ *temp = head;
    while (temp) {
      if (temp->data == target) {
        return index;
      }
      temp = temp->next;
      index++;
    }
    return -1;
  }

  // Reverse the linked list
  void __Reverse_List__() {
    __Node__ *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
    std::cout << "\nLinked list reversed successfully.\n";
  }

  // Pairwise swap of adjacent nodes
  void __Pairwise_Swap__() {
    if (!head || !head->next) {
      std::cout << "\nList has fewer than two elements. No swap needed.\n";
      return;
    }
    __Node__ *temp = head;
    while (temp && temp->next) {
      // Swap the data of current node and the next node
      std::swap(temp->data, temp->next->data);

      // Move to the next pair
      temp = temp->next->next;
    }
    std::cout << "\nPairwise swap completed.\n";
  }

  // Remove duplicates from the list
  void __Remove_Duplicates__() {
    if (!head) {
      std::cout << "\nList is empty. No duplicates to remove.\n";
      return;
    }
    // Outer loop to traverse the list
    __Node__ *outer = head;
    while (outer && outer->next) {
      __Node__ *inner = outer;
      // Inner loop to check for duplicates
      while (inner->next) {
        if (inner->next->data == outer->data) {
          __Node__ *duplicate = inner->next;
          inner->next = inner->next->next; // Remove duplicate
          delete duplicate;                // Free memory of the removed node
        } else {
          inner = inner->next; // Move inner pointer forward
        }
      }
      outer = outer->next; // Move outer pointer forward
    }
    std::cout << "\nDuplicates removed.\n";
  }

  // Insert a node after a given node
  void __Insert_After_Node__(int target, int value) {
    __Node__ *temp = head;
    while (temp) {
      if (temp->data == target) {
        __Node__ *new_node = new __Node__(value);
        new_node->next = temp->next;
        temp->next = new_node;
        std::cout << "\nNode with value " << value << " inserted after "
                  << target << ".\n";
        return;
      }
      temp = temp->next;
    }
    std::cout << "\nNode with value " << target << " not found.\n";
  }

  // Destructor to ensure all dynamically allocated memory is freed
  ~__Linked_List__() { __Delete_List__(); }
};

// Main function to demonstrate the LinkedList operations
int main() {
  __Linked_List__ list1, list2;

  // Populate the first linked list
  list1.__Insert_End__(10);
  list1.__Insert_End__(20);
  list1.__Insert_End__(30);
  list1.__Insert_End__(15);
  list1.__Insert_End__(5);

  // Populate the second linked list
  list2.__Insert_End__(5);
  list2.__Insert_End__(15);
  list2.__Insert_End__(25);
  list2.__Insert_End__(25);
  list2.__Insert_End__(30);

  std::cout << "List 1 before merge: ";
  list1.__Display__();

  std::cout << "List 2 before merge: ";
  list2.__Display__();

  // Merge list1 and list2
  list1.__Merge__(list2);
  std::cout << "Merged list: ";
  list1.__Display__();

  list1.__Remove_Duplicates__();
  list1.__Display__();

  list1.__Reverse_List__();
  list1.__Display__();

  list1.__Pairwise_Swap__();
  list1.__Display__();

  return 0;
}
