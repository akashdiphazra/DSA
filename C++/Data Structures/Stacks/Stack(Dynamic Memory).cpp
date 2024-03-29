#include <iostream>

int *stack;
int top = -1, stack_size;

void push(int x) {
    if (top == stack_size - 1) {
        std::cout << "\nOverflow" << std::endl;
    } else {
        stack[++top] = x;
    }
}

void pop() {
    if (top == -1) {
        std::cout << "\nUnderflow" << std::endl;
    } else {
        std::cout << "\n" << stack[top--] << " deleted." << std::endl;
    }
}

void show() {
    if (top == -1) {
        std::cout << "Stack is Empty" << std::endl;
    } else {
        for (int i = top; i >= 0; i--) {
            std::cout << stack[i] << "\n";
        }
    }
}

void topmost() {
    std::cout << "\nTopmost Element: " << stack[top] << std::endl;
}
void bottom() { std::cout << "\nBottom Element: " << stack[0] << std::endl; }

int main() {
    int ch, x;
    std::cout << "Enter the size of stack" << std::endl;
    std::cin >> stack_size;
    stack = new int[stack_size];
    do {
        std::cout << "\n0.Exit.\n1.Push.\n2.Pop.\n3.Print Stack."
                     "\n4.Print Topmost Element.\n5.Print bottom element."
                  << std::endl;
        std::cin >> ch;
        if (ch == 1) {
            std::cout << "Insert : " << std::endl;
            std::cin >> x;
            push(x);
        } else if (ch == 2) {
            pop();
        } else if (ch == 3) {
            std::cout << "STACK" << std::endl;
            show();
        } else if (ch == 4) {
            topmost();
        } else if (ch == 5) {
            bottom();
        }
    } while (ch != 0);
}