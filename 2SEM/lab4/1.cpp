#include <iostream>
// #include <cstring>

class ch_stack {
private:
    char stack[100];
    int top;
public:
    ch_stack() {
        top = -1;
    }

    void push(int n, const char s1[]) {
        for (int i = 0; i < n; i++) {
            if (top < 99) {
                top++;
                stack[top] = s1[i];
            } else {
                std::cout << "Stack is full, unable  to add an element " << s1[i] << std::endl;
            }
        }
    }

// write a function to show the stack
    void display() {
        for (int i = 0; i <= top; i++) {
            std::cout << stack[i] << std::endl;
        }
        std::cout << std::endl;
    }
    
    void pop(int n, char sl[]) {
        if (top == -1) {
            std::cout << "error: stack is full" << std::endl;
            return;
        }

        if (n > top + 1) {
            std::cout << "Stack contains " << top + 1 << " elements, unable to pop more elements" << std::endl;
            n = top + 1;
        }

        for (int i = 0; i < n; i++) {
            sl[i] = stack[top - i];
        }
        top -= n;
        sl[n] = '\0';
    }
};


int main() {
    ch_stack stack;
    char str[100];
    char output[100];
    int n;

    std::cout << "Input string: ";
    std::cin.getline(str, sizeof(str));
    std::cout << "How many symbols to put in stack: ";
    std:: cin >> n;

    stack.push(n, str);
    stack.display();

    std::cout << "How many symbols to put in string from stack: ";
    std:: cin >> n;

    stack.pop(n, output);
    std::cout << "Output: " << output << std::endl;
    return 0;
}