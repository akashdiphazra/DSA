#include <iostream>

// Node structure for circular linked list
class __Node__ {
public:
    int data;
    __Node__* next;

    __Node__(int value) : data(value), next(nullptr) {}
};

// Circular LinkedList class
class __Circular_Linked_List__ {
private:
    __Node__* head;

public:
    __Circular_Linked_List__() : head(nullptr) {}

    // Insert node at the beginning (returns new head)
    void __Insert_Beginning__(int value) {
        __Node__* new_node = new __Node__(value);
        if (!head) {
            new_node->next = new_node;  // Circular link to itself
            head = new_node;
        } else {
            new_node->next = head;
            // Find the last node and update its next to the new node
            __Node__* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            head = new_node;  // Update head
        }
    }

    // Insert node at the end
    void __Insert_End__(int value) {
        __Node__* new_node = new __Node__(value);
        if (!head) {
            new_node->next = new_node;  // Circular link to itself
            head = new_node;
        } else {
            __Node__* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;  // Complete the circular link
        }
    }

    // Display list
    void __Display__() const {
        if (!head) {
            std::cout << "\nList is empty.\n";
            return;
        }
        __Node__* temp = head;
        int size = 0;
        std::cout << "\nCircular Linked List: [head]: ";
        do {
            std::cout << "-->{ " << temp->data << " } ";
            temp = temp->next;
            size++;
        } while (temp != head); // Stop when we circle back to head
        std::cout << " --> [head]";
        std::cout << "  Size: " << size << "\n";
    }

    // Merge two circular linked lists
    void __Merge__(__Circular_Linked_List__& other) {
        if (!head) {
            head = other.head;
            other.head = nullptr;
            return;
        }

        __Node__* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = other.head;
        __Node__* last_of_other = other.head;
        while (last_of_other->next != other.head) {
            last_of_other = last_of_other->next;
        }
        last_of_other->next = head; // Complete the circular link

        other.head = nullptr; // Avoid double free
        std::cout << "\nMerged two circular lists.\n";
    }

    // Delete the entire list
    void __Delete_List__() {
        if (!head) {
            std::cout << "\nList is already empty.\n";
            return;
        }
        __Node__* temp = head;
        while (temp->next != head) {
            __Node__* next_node = temp->next;
            delete temp;
            temp = next_node;
        }
        delete temp;  // Delete the last node
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
            delete head;  // Only one node in the list
            head = nullptr;
        } else {
            __Node__* temp = head;
            __Node__* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;  // Update last node's next pointer
            delete temp;
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
            delete head;
            head = nullptr;
        } else {
            __Node__* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            __Node__* last = temp->next;
            temp->next = head;  // Update last node's next pointer
            delete last;
        }
        std::cout << "\nDeleted from end.\n";
    }

    // Search for an element (returns index or -1)
    int __Search_Element__(int target) const {
        int index = 0;
        __Node__* temp = head;
        if (!temp) return -1;
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
            return; // No need to reverse a single-node or empty list
        }

        __Node__* prev = nullptr;
        __Node__* curr = head;
        __Node__* next = nullptr;
        __Node__* last = head;

        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        head->next = prev; // Close the circle
        head = prev; // Update head to new first node
        std::cout << "\nCircular linked list reversed successfully.\n";
    }

    // Pairwise swap of adjacent nodes
    void __Pairwise_Swap__() {
        if (!head || head->next == head) {
            std::cout << "\nList has fewer than two elements. No swap needed.\n";
            return;
        }

        __Node__* temp = head;
        do {
            if (temp->next != head) {
                std::swap(temp->data, temp->next->data);
                temp = temp->next->next;
            } else {
                break;
            }
        } while (temp != head);
        std::cout << "\nPairwise swap completed.\n";
    }

    // Remove duplicates from the circular list
    void __Remove_Duplicates__() {
        if (!head) {
            std::cout << "\nList is empty. No duplicates to remove.\n";
            return;
        }
        __Node__* outer = head;
        do {
            __Node__* inner = outer;
            while (inner->next != head) {
                if (inner->next->data == outer->data) {
                    __Node__* duplicate = inner->next;
                    inner->next = inner->next->next;
                    delete duplicate;
                } else {
                    inner = inner->next;
                }
            }
            outer = outer->next;
        } while (outer != head);
        std::cout << "\nDuplicates removed.\n";
    }

    // Destructor to ensure all dynamically allocated memory is freed
    ~__Circular_Linked_List__() { __Delete_List__(); }
};

// Main function to demonstrate the Circular LinkedList operations
int main() {
    __Circular_Linked_List__ list1, list2;

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
