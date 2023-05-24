#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct card {
    int value;
    char suit;
};

void printHand(card hand[]) {
    for (int i = 0; i < 5; i++) {
        cout << hand[i].value << hand[i].suit << " ";
    }
    cout << endl;
}

void sortHand(card hand[]) {
    // Сортировка пузырьком
    bool swapped = true;
    int j = 0;
    card temp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < 5 - j; i++) {
            if (hand[i].value > hand[i + 1].value) {
                temp = hand[i];
                hand[i] = hand[i + 1];
                hand[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

void generateRandomHand(card hand[]) {
    char suits[] = {'H', 'D', 'C', 'S'};
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        hand[i].value = rand() % 13 + 1;
        hand[i].suit = suits[rand() % 4];
    }
}

int main() {
    card hand[5];
    generateRandomHand(hand);
    cout << "Initial Hand: ";
    printHand(hand);
    sortHand(hand);
    cout << "Sorted Hand: ";
    printHand(hand);
    return 0;
}
