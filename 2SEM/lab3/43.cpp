#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;


void swap(char s1[], char s2[]) {
    deque deque1(s1, s1 + strlen(s1));
    deque deque2(s2, s2 + strlen(s2));
    swap_ranges(deque1.begin(), deque1.end(), deque2.begin());
    copy(deque1.begin(), deque1.end(), s2);
    copy(deque2.begin(), deque2.end(), s1);
}

int main() {
    char s1[] = "Hello";
    char s2[] = "World";
    cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    swap(s1, s2);
    cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    return 0;
}
