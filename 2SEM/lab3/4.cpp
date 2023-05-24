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

bool is_empty(ch_stack &s) {
    return s.top == -1;
}

void pushm(int n,const char s1[],ch_stack &stk) {
    for (int i = 0; i < n; i++) {
        push(stk, s1[i]);
    }
}

void popn(int n,char s1[], ch_stack &stk) {
    for (int i = 0; i < n; i++) {
        s1[i] = pop(stk);
    }
    s1[n] = '\0';
}

int main() {
    int n, m;
    string user_input;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    char s1[n];
    char s2[m];
    cout << "Enter string: ";
    cin.ignore();
    getline(cin, user_input);
    strcpy(s1, user_input.c_str());
    ch_stack stk;
    stk.top = -1;
    pushm(n, s1, stk);
    popn(m, s2, stk);
    cout << "Reversed string: " << s2 << endl;
    return 0;
}
