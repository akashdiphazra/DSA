#include <iostream>

namespace data_structures {
class Dynamic_Queue {
 private:
    int *queue;
    int queue_size;
    int64_t front{-1};
    int64_t rear{-1};

 public:
    Dynamic_Queue(int size) {
        queue_size = size;
        queue = new int[size];
    }
    void enqueue(const int64_t &);
    int dequeue();
    void display();
};

void Dynamic_Queue::enqueue(const int64_t &data) {
    if (rear == queue_size - 1) {
        std::cout << "\nQueue is Full" << std::endl;
    } else if (front == -1 && rear == -1) {
        rear = 0, front = 0;
        queue[rear] = data;
    } else if (rear < queue_size) {
        ++rear;
        queue[rear] = data;
    }
}

int Dynamic_Queue::dequeue() {
    int64_t d{0};
    if (front == -1) {
        std::cout << "Queue is empty" << std::endl;
        return 0;
    } else if (front == rear) {
        d = queue[front];
        front = rear = -1;
    } else {
        d = queue[front++];
    }
    return d;
}

void Dynamic_Queue::display() {
    if (front == -1) {
        std::cout << "\nQueue is Empty" << std::endl;
    } else {
        for (int64_t i{front}; i <= rear; ++i) {
            std::cout << queue[i] << " ";
        }
    }
}
};  // namespace data_structures

int main() {
    int op{0}, data{0}, size;
    std::cout << "Enter the size of the queue " << std::endl;
    std::cin >> size;
    data_structures::Dynamic_Queue dq(size);
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
            dq.enqueue(data);
        } else if (op == 2) {
            data = dq.dequeue();
            if (data != 0) {
                std::cout << "\ndequeue element is: " << data;
            }
        } else if (op == 3) {
            dq.display();
        } else if (op == 4) {
            exit(0);
        } else {
            std::cout << "\nWrong choice ";
        }
    } while (op != 4);
    return 0;
}
