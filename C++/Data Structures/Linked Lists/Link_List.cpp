#include <iostream>
#include <new>

namespace Data_Structures {
class Node {
 public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Link_List {
    Node *head;

 public:
    Link_List() { head = NULL; }
    void insert_at_the_begining(int val);
    void insert_at_the_end(int val);
    void insert_after(int val, int key);
    void insert_before(int val, int key);
    void display();
    void delete_begining();
    void delete_end();
    void delete_after(int val);
    void delete_all();
    void reverse_link_list();
    void sort_list();
    void remove_duplicates();
};

void Link_List::insert_at_the_begining(int val) {
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void Link_List::insert_at_the_end(int val) {
    Node *new_node = new Node(val);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
}

void Link_List::display() {
    Node *ptr = head;
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    } else {
        std::cout << "[HEAD] ➡ ";
        while (ptr != NULL) {
            std::cout << ptr->data << " ➡ ";
            ptr = ptr->next;
        }
        std::cout << "NULL" << std::endl;
    }
}

void Link_List::insert_after(int val, int key) {
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    }
    Node *new_node = new Node(val);
    Node *ptr, *preptr;
    ptr = head;
    if (ptr->data == key) {
        preptr = ptr;
        ptr = ptr->next;
        preptr->next = new_node;
        new_node->next = ptr;
    } else if (ptr->data != key) {
        preptr = ptr;
        while (preptr->data != key && ptr != NULL) {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (preptr->data != key && ptr == NULL) {
            std::cout << "ELEMENT NOT FOUND IN THE LINK LIST" << std::endl;
        } else {
            preptr->next = new_node;
            new_node->next = ptr;
        }
    }
}

void Link_List::insert_before(int val, int key) {
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    }
    Node *new_node = new Node(val);
    Node *ptr, *preptr;
    ptr = head;
    if (ptr->data == key) {
        insert_at_the_begining(val);
    } else if (ptr->data != key) {
        while (ptr->data != key && ptr->next != NULL) {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr->data != key && ptr->next == NULL) {
            std::cout << "ELEMENT NOT FOUND IN THE LINK LIST" << std::endl;
        } else {
            preptr->next = new_node;
            new_node->next = ptr;
        }
    }
}

void Link_List::delete_begining() {
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    } else {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void Link_List::delete_end() {
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    } else if (head->next == NULL && head->data) {
        delete head;
        head = NULL;
        return;
    } else if (head->next != NULL) {
        Node *ptr, *preptr;
        ptr = head;
        while (ptr->next != NULL) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        delete ptr;
    }
}

void Link_List::delete_after(int val) {
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    } else if (head->data == val && head->next == NULL) {
        std::cout << "NOT POSSIBLE ONLY ONE ELEMENT IN THE LINK LIST"
                  << std::endl;
        return;
    }
    Node *ptr, *preptr;
    ptr = head;
    preptr = ptr;
    if (preptr->data == val && preptr->next->data && head->data) {
        ptr = ptr->next;
        preptr->next = ptr->next;
        delete ptr;
        return;
    } else {
        while (preptr->data != val && preptr->next != NULL) {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (preptr->data != val && preptr->next == NULL) {
            std::cout << "ELEMENT NOT FOUND IN THE LINK LIST" << std::endl;
            return;
        } else if (preptr->data == val && preptr->next == NULL) {
            std::cout << "CANNOT BE DONE" << std::endl;
            return;
        } else {
            preptr->next = ptr->next;
            delete ptr;
        }
    }
}

void Link_List::reverse_link_list() {
    Node *prevptr, *nextptr, *currentptr;
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    } else {
        currentptr = head;
        prevptr = NULL;
        nextptr = NULL;
        while (currentptr != NULL) {
            nextptr = currentptr->next;
            currentptr->next = prevptr;
            prevptr = currentptr;
            currentptr = nextptr;
        }
        head = prevptr;
    }
}

void Link_List::sort_list() {
    Node *current, *index;
    int temp;
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    } else {
        current = head;
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void Link_List::delete_all() {
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    } else {
        Node *temp;
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
}

void Link_List::remove_duplicates() {
    Node *ptr1, *ptr2, *dup;
    if (head == NULL) {
        std::cout << "LINK LIST EMPTY" << std::endl;
        return;
    } else {
        ptr1 = head;
        while (ptr1 != NULL && ptr1->next != NULL) {
            ptr2 = ptr1;
            while (ptr2->next != NULL) {
                if (ptr1->data == ptr2->next->data) {
                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete dup;
                } else {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }
}

};  // namespace Data_Structures

int main() {
    Data_Structures::Link_List list;
    int choice;
    int num, val;
    do {
        std::cout << "\n****************** Main Menu ****************** "
                  << std::endl;
        std::cout << "1. Insert at the beginning."
                     "\n2. Insert at the end."
                     "\n3. Display the link list."
                     "\n4. Insert after any element in the link list."
                     "\n5. Insert before any element in the link list."
                     "\n6. Delete a element from the beginning."
                     "\n7. Delete a element at the end."
                     "\n8. Delete after any element in the link list."
                     "\n9. Reverse link list."
                     "\n10. Sort the link list."
                     "\n11. Delete the entire link list."
                     "\n12. Remove duplicates from the linked list."
                  << std::endl;
        std::cout << "Enter your option" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the data: " << std::endl;
                std::cin >> num;
                list.insert_at_the_begining(num);
                break;

            case 2:
                std::cout << "Enter the data: " << std::endl;
                std::cin >> num;
                list.insert_at_the_end(num);
                break;

            case 3:
                std::cout << "Link List ➡ ";
                list.display();
                break;

            case 4:
                std::cout << "Enter the data: " << std::endl;
                std::cin >> num;
                std::cout << "Enter any value from the link list after which "
                             "you want to enter the data: "
                          << std::endl;
                std::cin >> val;
                list.insert_after(num, val);
                break;

            case 5:
                std::cout << "Enter the data: " << std::endl;
                std::cin >> num;
                std::cout << "Enter any value from the link list before which "
                             "you want to enter the data: "
                          << std::endl;
                std::cin >> val;
                list.insert_before(num, val);
                break;

            case 6:
                list.delete_begining();
                std::cout << "Element deleted from the beginning" << std::endl;
                break;

            case 7:
                list.delete_end();
                std::cout << "Element deleted at the end" << std::endl;
                break;

            case 8:
                std::cout << "Enter any value from the link list after which "
                             "you want to delete the data: "
                          << std::endl;
                std::cin >> val;
                list.delete_after(val);
                std::cout << "Element deleted after " << val << std::endl;
                break;

            case 9:
                list.reverse_link_list();
                std::cout << "Link List Reversed" << std::endl;
                break;

            case 10:
                list.sort_list();
                std::cout << "Link List Sorted" << std::endl;
                break;

            case 11:
                list.delete_all();
                std::cout << "Entire link list Deleted" << std::endl;
                break;

            case 12:
                list.remove_duplicates();
                std::cout << "All Duplicates Removed" << std::endl;
                break;
        }
    } while (choice != 13);
    return 0;
}
