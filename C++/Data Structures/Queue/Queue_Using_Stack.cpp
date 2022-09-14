#include <iostream>
#include <stack>

class Queue_Stack {
 private:
    std::stack<int> s1, s2;

 public:
    void enqueue(const int64_t &);
    int dequeue();
    void display();
};

void Queue_Stack::enqueue(const int64_t &data) {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(data);
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

int Queue_Stack::dequeue() {
    if (s1.empty()) {
        std::cout << "Queue is Empty";
        exit(0);
    }
    int d = s1.top();
    s1.pop();
    return d;
}

void Queue_Stack::display() {
    for (std::stack<int> dump = s1; !dump.empty(); dump.pop())
        std::cout << dump.top() << '\n';
}

int main() {
    int op{0}, data{0};
    Queue_Stack qs;
    do {
        std::cout << "\n\n1. Enqueue(Insertion) "
                     "\n2. Dequeue(Deletion)"
                     "\n3. Display"
                     "\n4. Exit"
                     "\nEnter your choice "
                  << std::endl;
        std::cin >> op;
        if (op == 1) {
            std::cout << "Enter data  ";
            std::cin >> data;
            qs.enqueue(data);
        } else if (op == 2) {
            data = qs.dequeue();
            if (data != 0) {
                std::cout << "\ndequeue element is: " << data;
            }
        } else if (op == 3) {
            qs.display();
        } else if (op == 4) {
            exit(0);
        } else {
            std::cout << "\nWrong choice ";
        }
    } while (op != 4);
    return 0;
}
