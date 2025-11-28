#include <iostream>
#include <memory>

// Node structure for integer linked list
class __Node__ {
public:
  int data;
  std::shared_ptr<__Node__> next;

  __Node__(int value) : data(value), next(nullptr) {}
};

// Circular LinkedList class
class CircularLinkedList {
private:
  std::shared_ptr<__Node__> head;

public:
  CircularLinkedList() : head(nullptr) {}

  // Insert node at the beginning (returns new head)
  void __Insert_Beginning__(int value) {
    auto new_node = std::make_shared<__Node__>(value);
    if (!head) {
      head = new_node;
      new_node->next = head; // Make it circular
    } else {
      new_node->next = head;
      auto temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = new_node;
      head = new_node; // New node becomes the head
    }
  }

  // Insert node at the end
  void __Insert_End__(int value) {
    auto new_node = std::make_shared<__Node__>(value);
    if (!head) {
      head = new_node;
      new_node->next = head; // Make it circular
    } else {
      auto temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = new_node;
      new_node->next = head; // Make it circular
    }
  }

  // Display list (one complete loop)
  void __Display__() const {
    if (!head) {
      std::cout << "\nList is empty.\n";
      return;
    }

    auto temp = head;
    int size = 0;
    std::cout << "\nCircular Linked List: [head]: ";
    do {
      std::cout << "-->{ " << temp->data << " } ";
      temp = temp->next;
      size++;
    } while (temp != head);
    std::cout << " --> [head]";
    std::cout << "  Size: " << size << "\n";
  }

  // Merge two circular linked lists
  void __Merge__(CircularLinkedList &other) {
    if (!head) {
      head =
          other.head; // If the first list is empty, just take the second list
      return;
    }

    // Traverse to the end of the current list (this list)
    auto temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }

    // Append the second list to the end of the first list
    temp->next = other.head;

    // Make it circular again by connecting the last node of the second list to
    // the head
    auto other_temp = other.head;
    while (other_temp->next != other.head) {
      other_temp = other_temp->next;
    }
    other_temp->next = head;

    std::cout << "\nMerged two circular lists.\n";
  }

  // Delete the entire list
  void __Delete_List__() {
    head = nullptr;
    std::cout << "\nCircular linked list deleted successfully.\n";
  }

  // Delete node from the beginning
  void __Delete_Beginning__() {
    if (!head) {
      std::cout << "\nList is empty. Nothing to delete.\n";
      return;
    }

    if (head->next == head) {
      head = nullptr; // If there's only one node, set head to nullptr
    } else {
      auto temp = head;
      while (temp->next != head) {
        temp = temp->next;
      }
      temp->next = head->next; // Link the last node to the second node
      head = head->next;       // Move the head to the second node
    }
    std::cout << "\nDeleted from beginning.\n";
  }

  // Delete node from the end
  void __Delete_End__() {
    if (!head) {
      std::cout << "\nList is empty. Nothing to delete.\n";
      return;
    }

    if (head->next == head) {
      head = nullptr; // If there's only one node, set head to nullptr
    } else {
      auto temp = head;
      while (temp->next->next != head) {
        temp = temp->next;
      }
      temp->next = head; // Link the second last node to the head
    }
    std::cout << "\nDeleted from end.\n";
  }

  // Search for an element (returns index or -1)
  int __Search_Element__(int target) const {
    int index = 0;
    auto temp = head;
    if (!temp)
      return -1;
    do {
      if (temp->data == target) {
        return index;
      }
      temp = temp->next;
      index++;
    } while (temp != head);
    return -1;
  }

  // Reverse the circular linked list
  void __Reverse_List__() {
    if (!head || head->next == head) {
      std::cout << "\nNothing to reverse.\n";
      return;
    }

    std::shared_ptr<__Node__> prev = nullptr, curr = head, next = nullptr;
    do {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    } while (curr != head);

    head->next = prev; // The last node should point to the new head
    head = prev;       // New head is the last node

    std::cout << "\nCircular linked list reversed successfully.\n";
  }

  // Pairwise swap of adjacent nodes
  void __Pairwise_Swap__() {
    if (!head || head->next == head) {
      std::cout << "\nList has fewer than two elements. No swap needed.\n";
      return;
    }

    auto temp = head;
    do {
      if (temp->next != head) {
        std::swap(temp->data, temp->next->data);
      }
      temp = temp->next->next; // Skip two nodes to swap next pair
    } while (temp != head && temp->next != head);
    std::cout << "\nPairwise swap completed.\n";
  }

  // Remove duplicates in the circular list
  void __Remove_Duplicates__() {
    if (!head) {
      std::cout << "\nList is empty. No duplicates to remove.\n";
      return;
    }

    auto outer = head;
    do {
      auto inner = outer;
      while (inner->next != head) {
        if (inner->next->data == outer->data) {
          inner->next = inner->next->next;
        } else {
          inner = inner->next;
        }
      }
      outer = outer->next;
    } while (outer != head);
    std::cout << "\nDuplicates removed.\n";
  }

  // Insert node after a node with the specified value
  void __Insert_After__(int targetval, int newval) {
    if (!head) {
      std::cout << "\nList is empty. Nothing to insert after.\n";
      return;
    }

    auto temp = head;
    do {
      if (temp->data == targetval) {
        // Found the node with target value, now insert after it
        auto new_node = std::make_shared<__Node__>(newval);
        new_node->next =
            temp->next; // Point the new node to the next node of the target
        temp->next = new_node; // Link the target node to the new node
        std::cout << "\nInserted " << newval << " after node with value "
                  << targetval << ".\n";
        return;
      }
      temp = temp->next;
    } while (temp !=
             head); // Loop back to the head to complete the circular list

    std::cout << "\nValue " << targetval << " not found in the list.\n";
  }
};

// Main function to demonstrate the CircularLinkedList operations
int main() {
  CircularLinkedList list1, list2;

  // Populate the first circular linked list
  list1.__Insert_End__(10);
  list1.__Insert_End__(20);
  list1.__Insert_End__(30);
  list1.__Insert_End__(15);
  list1.__Insert_End__(5);

  // Populate the second circular linked list
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
