#include <iostream>

const int max_len = 10;

class deque {
    private:
    char c[max_len];
    int bottom, top;
    public:
        void reset() {
        top = bottom = max_len / 2;
        top--;
    };
        void push_t(char val) {
        if (full(1)) {
            std::cout << "Deque is full, relocating...\n";
            relocate();
            return;
        }
        c[++top] = val;
    };
        void push_b(char val) {
        if (full(0)) {
            std::cout << "Deque is full, relocating...\n";
            relocate();
            return;
        }
        c[--bottom] = val;
    };
        char pop_t() {
        if (empty()) {
            std::cout << "Deque is empty\n";
            return '\0';
        }
        return c[top--];
    };
        char pop_b() {
        if (empty()) {
            std::cout << "Deque is empty\n";
            return '\0';
        }
        return c[bottom++];
    };
        void out_stack() {
        for (int i = bottom; i <= top; i++) {
            std::cout << c[i] << " ";
        }
        std::cout << "\n";
    };
        char top_of() {
        if (!empty()) {
            std::cout << "Deque is empty\n";
            return '\0';
        }
        return c[top];
    };
        char bottom_of() {
        if (empty()) {
            std::cout << "Deque is empty\n";
            return '\0';
        }
        return c[bottom];
    };
        bool empty() {
        return (bottom > top);
    };
        bool full(bool position) {
            if (position) {
                return (top == max_len - 1);
            }
            else {
                return (bottom == 0);
            }
    };

    int size() {
        return (top - bottom + 1);
    };

     bool relocate() {
            if (size() < max_len) {
                return false;
            }

            int new_bottom = max_len / 2 - size() / 2;
            char new_c[max_len];

            for (int i = 0; i < size(); i++) {
                new_c[i + new_bottom] = c[i + bottom];
            }

            bottom = new_bottom;
            top = bottom + size() - 1;
            std::copy(std::begin(new_c), std::end(new_c), std::begin(c));
            return true;
        }
};

void menu(deque dq) {
    while (true) {
        std::cout << "Choose an option:\n";
        std::cout << "1. Add character to top of deque\n";
        std::cout << "2. Add character to bottom of deque\n";
        std::cout << "3. Remove character from top of deque\n";
        std::cout << "4. Remove character from bottom of deque\n";
        std::cout << "5. Print contents of deque\n";
        std::cout << "6. Reset\n";
        std::cout << "7. Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter character to add to top of deque: ";
            char top_char;
            std::cin >> top_char;
            dq.push_t(top_char);
            break;
        case 2:
            std::cout << "Enter character to add to bottom of deque: ";
            char bottom_char;
            std::cin >> bottom_char;
            dq.push_b(bottom_char);
            break;
        case 3:
            std::cout << "Removing character from top of deque: ";
            std::cout << dq.pop_t() << "\n";
            break;
        case 4:
            std::cout << "Removing character from bottom of deque: ";
            std::cout << dq.pop_b() << "\n";
            break;
        case 5:
            std::cout << "Contents of deque: ";
            dq.out_stack();
            break;
        case 6:
            std::cout << "Reseting deque\n";
            dq.reset();
            break;
        case 7:
            std::cout << "Exiting programm\n";
            return;
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    }
}


int main() {
    deque dq;
    dq.reset();

    menu(dq);

    return 0;
}
