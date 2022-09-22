#include <iostream>

class Circular_Queue {
 private:
    int64_t *circular_queue;
    int64_t circular_queue_size;
    int64_t front{-1}, rear{-1};

 public:
    Circular_Queue(int64_t size) {
        circular_queue_size = size;
        circular_queue = new int64_t[size];
    }

    void enqueue(const int64_t &data) {
        if (front == 0 && rear == circular_queue_size - 1) {
            std::cout << "OVERFLOW" << std::endl;
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
            circular_queue[rear] = data;
        } else if (front != 0 && rear == circular_queue_size - 1) {
            rear = 0;
            circular_queue[rear] = data;
        } else {
            rear++;
            circular_queue[rear] = data;
        }
    }

    int dequeue() {
        int d;
        if (front == -1 && rear == -1) {
            std::cout << "UNDERFLOW" << std::endl;
            return 0;
        } else if (front == rear) {
            d = circular_queue[front];
            front = rear = -1;
        } else if (front == circular_queue_size - 1) {
            d = circular_queue[front];
            front = 0;
        } else {
            d = circular_queue[front++];
        }
        return d;
    }

    void display() {
        if (front == -1 && rear == -1) {
            std::cout << "\nCircular Queue is Empty" << std::endl;
        } else {
            if (front <= rear) {
                for (int64_t i{front}; i <= rear; ++i) {
                    std::cout << circular_queue[i] << " ";
                }
            } else {
                for (int i = front; i < circular_queue_size; i++) {
                    std::cout << circular_queue[i] << " ";
                }
                for (int j = 0; j <= rear; j++) {
                    std::cout << circular_queue[j] << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    void peek();
};

int main() {
    int64_t op{0}, data{0}, size;
    std::cout << "Enter the size of the queue " << std::endl;
    std::cin >> size;
    Circular_Queue cq(size);
    do {
        std::cout << "\n1. Enqueue(Insertion) "
                     "\n2. Dequeue(Deletion)"
                     "\n3. Display"
                     "\n4. Exit"
                     "\nEnter your choice "
                  << std::endl;
        std::cin >> op;
        if (op == 1) {
            std::cout << "Enter data  ";
            std::cin >> data;
            cq.enqueue(data);
        } else if (op == 2) {
            data = cq.dequeue();
            if (data != 0) {
                std::cout << "\ndequeue element is: " << data;
            }
        } else if (op == 3) {
            cq.display();
        } else if (op == 4) {
            exit(0);
        } else {
            std::cout << "\nWrong choice ";
        }
    } while (op != 4);
    return 0;
}
