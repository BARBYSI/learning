#include <iostream>
#include <cstring>

using namespace std;

char* strrev(char*& s1, const char* s2) {
    int len = strlen(s2);
    s1 = new char[len+1];

    for (int i = 0; i < len; i++) {
        s1[i] = s2[len-i-1];
    }
    s1[len] = '\0';

    return s1;
}

int main() {
    const char* s = "Hello, world!";
    char* s1;
    s1 = strrev(s1, s);

    cout << s1 << endl;

    delete[] s1;
    return 0;
}