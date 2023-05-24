#include <iostream>
#include <string>

struct Dairy {
    std::string name;
    int weight; // в граммах
    int calories;
    float protein;
    float fat;
    float carbohydrates;
};

int CalculateCalories(Dairy dairy, int servingSize) {
    float factor = static_cast<float>(servingSize) / dairy.weight;
    return static_cast<int>(dairy.calories * factor);
}

int main() {
    Dairy cheese;
    cheese.name = "Cheese";
    cheese.weight = 25;
    cheese.calories = 375;
    cheese.protein = 5.0;
    cheese.fat = 8.0;
    cheese.carbohydrates = 0.0;

    int servingSize = 50; // в граммах
    int calories = CalculateCalories(cheese, servingSize);
    std::cout << "This serving of " << cheese.name << " contains " << calories << " calories." << std::endl;

    return 0;
}
