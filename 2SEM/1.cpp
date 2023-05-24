#include <iostream>
#include <string>
using namespace std;

struct dairy {
    string name;
    int weight;
    int calories;
    int protein;
    int fat;
    int carbs;
};

int calcCalories(dairy d, int portionWeight) {
    float ratio = (float)portionWeight / 25; // считаем отношение размера порции к 25 граммам
    int calories = d.calories * ratio; // умножаем энергетическую ценность на это отношение
    return calories;
}

int main() {
    dairy cheese;
    cheese.name = "Cheese";
    cheese.weight = 25; // размер порции в граммах
    cheese.calories = 375;
    cheese.protein = 5;
    cheese.fat = 8;
    cheese.carbs = 0;

    int portionWeight = 50; // размер порции, которую мы хотим посчитать в калориях
    int calories = calcCalories(cheese, portionWeight);
    cout << "Calories in " << portionWeight << "g of " << cheese.name << ": " << calories << endl;

    return 0;
} 
