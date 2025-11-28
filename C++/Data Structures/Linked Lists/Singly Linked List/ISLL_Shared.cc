#include <iostream>
#include <memory>

// Node structure for integer linked list
class __Node__ {
 public:
  int data;
  std::shared_ptr<__Node__> next;

  __Node__(int value) : data(value), next(nullptr) {}
};

// LinkedList class
class LinkedList {
 private:
  std::shared_ptr<__Node__> head;

 public:
  LinkedList() : head(nullptr) {}

  // Insert node at the beginning (returns new head)
  void __Insert_Beginning__(int value) {
    auto new_node = std::make_shared<__Node__>(value);
    new_node->next = head;
    head = new_node;
  }

  // Insert node at the end
  void __Insert_End__(int value) {
    auto new_node = std::make_shared<__Node__>(value);
    if (!head) {
      head = new_node;
    } else {
      auto temp = head;
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

    auto temp = head;
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
  void __Merge__(LinkedList &other) {
    if (!head) {
      head =
          other.head;  // If the first list is empty, just take the second list
      return;
    }

    // Traverse to the end of the current list (this list)
    auto temp = head;
    while (temp->next) {
      temp = temp->next;
    }

    // Append the second list to the end of the first list
    temp->next = other.head;

    std::cout << "\nMerged two lists .\n";
  }

  // Delete the entire list
  void __Delete_List__() {
    head = nullptr;
    std::cout << "\nLinked list deleted successfully.\n";
  }

  // Delete node from the beginning
  void __Delete_Beginning__() {
    if (!head) {
      std::cout << "\nList is empty. Nothing to delete.\n";
      return;
    }
    head = head->next;
    std::cout << "\nDeleted from beginning.\n";
  }

  // Delete node from the end
  void __Delete_End__() {
    if (!head) {
      std::cout << "\nList is empty. Nothing to delete.\n";
      return;
    }
    if (!head->next) {
      head = nullptr;
      std::cout << "\nDeleted from end.\n";
      return;
    }
    auto temp = head;
    while (temp->next && temp->next->next) {
      temp = temp->next;
    }
    temp->next = nullptr;
    std::cout << "\nDeleted from end.\n";
  }

  // Search for an element (returns index or -1)
  int __Search_Element__(int target) const {
    int index = 0;
    auto temp = head;
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
    std::shared_ptr<__Node__> prev = nullptr, curr = head, next = nullptr;
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
    auto temp = head;
    while (temp && temp->next) {
      // Swap the data of current node and the next node
      std::swap(temp->data, temp->next->data);

      // Move to the next pair
      temp = temp->next->next;
    }
    std::cout << "\nPairwise swap completed.\n";
  }

  void __Remove_Duplicates__() {
    if (!head) {
      std::cout << "\nList is empty. No duplicates to remove.\n";
      return;
    }
    // Outer loop to traverse the list
    auto outer = head;
    while (outer && outer->next) {
      auto inner = outer;
      // Inner loop to check for duplicates
      while (inner->next) {
        if (inner->next->data == outer->data) {
          inner->next = inner->next->next;  // Remove duplicate
        } else {
          inner = inner->next;  // Move inner pointer forward
        }
      }
      outer = outer->next;  // Move outer pointer forward
    }
    std::cout << "\nDuplicates removed.\n";
  }

  // Insert node after a given node
  void __Insert_After_Node__(int target, int value) {
    // Traverse the list to find the target node
    auto temp = head;
    while (temp) {
      if (temp->data == target) {
        // Create a new node with the given value
        auto new_node = std::make_shared<__Node__>(value);

        // Insert the new node after the target node
        // Point new node to the next node of the target
        new_node->next = temp->next;
        temp->next = new_node;  // Point the target node to the new node

        std::cout << "\nInserted " << value << " after " << target << ".\n";
        return;  // Done inserting, so we return
      }
      temp = temp->next;
    }
    // If we reached here, the target node was not found
    std::cout << "\nNode with value " << target << " not found in the list.\n";
  }
};

// Main function to demonstrate the LinkedList operations
int main() {
  LinkedList list1, list2;

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
