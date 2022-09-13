#include <array>
#include <iostream>
#define max_size 10

namespace data_structures {
class Array_Queue {
 private:
    int64_t front{-1};
    int64_t rear{-1};
    std::array<int64_t, max_size> queue;

 public:
    void enqueue(const int64_t &);
    int dequeue();
    void display();
};

void Array_Queue::enqueue(const int64_t &data) {
    if (rear == queue.size() - 1) {
        std::cout << "\nStack is Full" << std::endl;
    } else if (front == -1 && rear == -1) {
        rear = 0, front = 0;
        queue[rear] = data;
    } else if (rear < queue.size()) {
        ++rear;
        queue[rear] = data;
    }
}

int Array_Queue::dequeue() {
    int64_t d{0};
    if (front == -1) {
        std::cout << "Queue is empty" << std::endl;
        return 0;
    } else if (front == rear) {
        d = queue.at(front);
        front = rear = -1;
    } else {
        d = queue.at(front++);
    }
    return d;
}

void Array_Queue::display() {
    if (front == -1) {
        std::cout << "\nQueue is Empty" << std::endl;
    } else {
        for (int64_t i{front}; i <= rear; ++i) {
            std::cout << queue.at(i) << " ";
        }
    }
}
};  // namespace data_structures

int main() {
    int op{0}, data{0};
    data_structures::Array_Queue ob;
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
            ob.enqueue(data);
        } else if (op == 2) {
            data = ob.dequeue();
            if (data != 0) {
                std::cout << "\ndequeue element is: " << data;
            }
        } else if (op == 3) {
            ob.display();
        } else if (op == 4) {
            exit(0);
        } else {
            std::cout << "\nWrong choice ";
        }
    } while (op != 4);
    return 0;
}
