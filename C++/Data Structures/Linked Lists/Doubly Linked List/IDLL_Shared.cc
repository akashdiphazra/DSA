#include <iostream>
#include <memory>

class __DNode__ {
 public:
  int data;
  std::shared_ptr<__DNode__> next;
  std::shared_ptr<__DNode__> prev;

  __DNode__(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class __Doubly_Linked_List__ {
 private:
  std::shared_ptr<__DNode__> head;
  std::shared_ptr<__DNode__> tail;

 public:
  // Constructor: Initialize an empty list
  __Doubly_Linked_List__() : head(nullptr), tail(nullptr) {}

  // Insert at the beginning of the list
  void __Insert_Beginning__(int value) {
    std::shared_ptr<__DNode__> new_node = std::make_shared<__DNode__>(value);
    if (!head) {
      head = tail = new_node;  // If the list is empty
    } else {
      new_node->next = head;  // Point new node's next to head
      head->prev = new_node;  // Point current head's prev to new node
      head = new_node;        // Update head to new node
    }
  }

  // Insert at the end of the list
  void __Insert_End__(int value) {
    std::shared_ptr<__DNode__> new_node = std::make_shared<__DNode__>(value);
    if (!tail) {
      head = tail = new_node;  // If the list is empty
    } else {
      tail->next = new_node;  // Point current tail's next to new node
      new_node->prev = tail;  // Point new node's prev to current tail
      tail = new_node;        // Update tail to new node
    }
  }

  // Delete from the beginning of the list
  void __Delete_Beginning__() {
    if (head) {
      if (head == tail) {
        head = tail = nullptr;  // Only one element in the list
      } else {
        head = head->next;     // Move head to the next node
        head->prev = nullptr;  // Reset the previous pointer of the new head
      }
    }
  }

  // Delete from the end of the list
  void __Delete_End__() {
    if (tail) {
      if (head == tail) {
        head = tail = nullptr;  // Only one element in the list
      } else {
        tail = tail->prev;     // Move tail to the previous node
        tail->next = nullptr;  // Disconnect the new tail's next pointer
      }
    }
  }

  // Search for an element and return its index
  int __Search_List__(int target) const {
    std::shared_ptr<__DNode__> current = head;
    int index = 0;

    // Traverse the list and check for the target
    while (current) {
      if (current->data == target) {
        return index;  // Return the index of the found element
      }
      current = current->next;
      index++;
    }

    return -1;  // Return -1 if the target is not found
  }

  // Reverse the linked list
  void __Reverse__() {
    std::shared_ptr<__DNode__> current = head;
    std::shared_ptr<__DNode__> temp = nullptr;

    // Traverse the list and reverse the pointers
    while (current) {
      // Swap the next and prev pointers
      temp = current->next;
      current->next = current->prev;  // Swap next with prev
      current->prev = temp;           // Swap prev with next

      current = temp;  // Move to the next node (which is the previous node
                       // before the swap)
    }

    // After the loop, the head and tail need to be swapped
    std::swap(head, tail);
  }

  void __Remove_Duplicates__() {
    std::shared_ptr<__DNode__> current = head;

    while (current) {
      std::shared_ptr<__DNode__> runner = current->next;
      while (runner) {
        if (runner->data == current->data) {
          // Skip the duplicate node by adjusting pointers
          if (runner == tail) {
            tail = runner->prev;
          }
          if (runner->prev) {
            runner->prev->next = runner->next;
          }
          if (runner->next) {
            runner->next->prev = runner->prev;
          }
          runner = runner->next;  // Move to the next node
        } else {
          runner = runner->next;
        }
      }
      current = current->next;  // Move to the next node
    }
  }

  // Merge two sorted doubly linked lists
  void __Merge__(__Doubly_Linked_List__& other) {
    std::shared_ptr<__DNode__> current1 = head, current2 = other.head;

    std::shared_ptr<__Doubly_Linked_List__> merged_list =
        std::make_shared<__Doubly_Linked_List__>();

    // If there are remaining nodes in list 1
    while (current1) {
      merged_list->__Insert_End__(current1->data);
      current1 = current1->next;
    }

    // If there are remaining nodes in list 2
    while (current2) {
      merged_list->__Insert_End__(current2->data);
      current2 = current2->next;
    }

    // Update this list's head and tail to the merged list
    head = merged_list->head;
    tail = merged_list->tail;
  }

  // Display the list (forward traversal)
  void __Display__() const {
    std::shared_ptr<__DNode__> current = head;
    while (current) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  // Pairwise swap adjacent nodes
  void __Pairwise_Swap__() {
    // Start from the head
    std::shared_ptr<__DNode__> current = head;

    // Traverse the list and swap nodes in pairs
    while (current && current->next) {
      // Get the next node
      std::shared_ptr<__DNode__> next_node = current->next;

      // Swap the data of current node and next node
      std::swap(current->data, next_node->data);

      // Move the current pointer two steps forward
      current = next_node->next;
    }
  }

  // Check if the list is empty
  bool is_empty() const { return head == nullptr; }
};

int main() {
  __Doubly_Linked_List__ list1;
  list1.__Insert_End__(10);
  list1.__Insert_End__(20);
  list1.__Insert_End__(30);
  list1.__Insert_End__(10);
  list1.__Insert_End__(25);
  list1.__Insert_End__(10);
  list1.__Insert_End__(20);

  __Doubly_Linked_List__ list2;
  list2.__Insert_End__(5);
  list2.__Insert_End__(15);
  list2.__Insert_End__(25);
  list2.__Insert_End__(25);
  list2.__Insert_End__(15);
  list2.__Insert_Beginning__(30);
  list2.__Insert_Beginning__(25);

  std::cout << "List 1 before merge: ";
  list1.__Display__();

  std::cout << "List 2 before merge: ";
  list2.__Display__();

  // Merge list1 and list2
  list1.__Merge__(list2);
  std::cout << "Merged list: ";
  list1.__Display__();

  list1.__Remove_Duplicates__();
  std::cout << "List After Removing Duplicates: ";
  list1.__Display__();

  std::cout << "Reverse list: ";
  list1.__Reverse__();
  list1.__Display__();

  int index = list1.__Search_List__(30);
  if (index != -1) {
    std::cout << "Element " << 30 << " found at index " << index << std::endl;
  } else {
    std::cout << "Element " << 30 << " not found." << std::endl;
  }

  list1.__Pairwise_Swap__();
  std::cout << "List After Pairwise Swap: ";
  list1.__Display__();
  return 0;
}
