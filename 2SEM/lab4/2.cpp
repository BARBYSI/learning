#include <iostream>
#include <cstring>

//write a deque class

class deque {
private:
    char stack[100];
    int top;
public:
    deque() {
        top = -1;
    }
//write a function to push
    void push_t(int n, const char s1[]) {
        for (int i = 0; i < n; i++) {
            if (top < 99) {
                top++;
                stack[top] = s1[i];
            } else {
                std::cout << "Stack is full, unable  to add an element " << s1[i] << std::endl;
            }
        }
    }

//write a function to pop
    void pop_t(int n, char sl[]) {
        if (top == -1) {
            std::cout << "error: stack is full" << std::endl;
            return;
        }
    }

//write a fuction to push_buttom

    void push_b(int n, const char s1[]) {
        if(top == 99) {
            std::cout << "Stack is full, unable  to add an element " << s1[i] << std::endl;
            return;
        }
    }

//write a function to pop_buttom

    void pop_b(int n, char sl[]) {
        
    }
};



