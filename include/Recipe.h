//
// Created by Lucas Fonseca on 06.01.26.
//

#ifndef NUTRITION_CALCULATOR_RECIPE_H
#define NUTRITION_CALCULATOR_RECIPE_H

#include <ostream>
#include <string>
#include <vector>
struct Nutrition {
    double cal_per_100 {0};
    double protein_per_100 {0};
    double fat_per_100 {0};
    double carbs_per_100 {0};
};

struct Ingridient {
    std::string name {};
    float amount_in_g {0};
    Nutrition nutrition {};
};

class Recipe {
private:
    std::string name;
    Nutrition recipe_nutrition;
    std::vector<Ingridient> ingridients;
public:
    Recipe(std::string name, double total_amount);
    double total_amount_in_g = 0;
    void CalculateRecipeNutrition();
    void AddIngridient(Ingridient ing);
    friend std::ostream& operator<<(std::ostream& os, const Recipe& recipe);
};
#endif //NUTRITION_CALCULATOR_RECIPE_H