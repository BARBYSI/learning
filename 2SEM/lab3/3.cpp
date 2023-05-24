#include <iostream>
#include <cstring>

using namespace std;

const int arr_size = 100;

struct ch_stack {
    int top;
    char data[arr_size];
};

void push(ch_stack &s, char c) {
    if (s.top < arr_size - 1) {
        s.data[++s.top] = c;
    }
}

char pop(ch_stack &s) {
    if (s.top > -1) {
        return s.data[s.top--];
    }
    return '\0';
}

void reverse(char s1[], char s2[]) {
    int len = strlen(s1);
    ch_stack stack;
    stack.top = -1;
    for (int i = 0; i < len; i++) {
        push(stack, s1[i]);
    }
    for (int i = 0; i < len; i++) {
        s2[i] = pop(stack);
    }
}

int main() {
    string user_input;
    cout << "Enter a string to reverse:\n";
    getline(cin, user_input);
    char s1[user_input.length() + 1];
    strcpy(s1, user_input.c_str());
    char s2[strlen(s1)];
    reverse(s1, s2);
    cout << s2 << endl;
    return 0;
}
