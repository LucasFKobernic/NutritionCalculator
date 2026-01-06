#include <string>
#include "Recipe.h"

#include <iostream>
#include <ostream>
#include <utility>
#include <vector>


Recipe::Recipe(std::string name, double total_amount): name(std::move(name)), total_amount_in_g(total_amount) {}

void Recipe::CalculateRecipeNutrition() {
    if (this->total_amount_in_g <= 0) {
        std::cout << "Error: Total amount can't be less or equal to zero." << std::endl;
        this->recipe_nutrition = {0,0,0,0};
    }
    double total_calories {0};
    double total_protein {0};
    double total_fat {0};
    double total_carb {0};

    double scale = 100 / this->total_amount_in_g;
    for (auto const &ingridient :this->ingridients) {
        total_calories += (ingridient.amount_in_g)/100*(ingridient.nutrition.cal_per_100);
        total_protein += (ingridient.amount_in_g)/100*(ingridient.nutrition.protein_per_100);
        total_fat += (ingridient.amount_in_g)/100*(ingridient.nutrition.fat_per_100);
        total_carb += (ingridient.amount_in_g)/100*(ingridient.nutrition.carbs_per_100);

    }

    this->recipe_nutrition.cal_per_100= total_calories * scale;
    this->recipe_nutrition.protein_per_100= total_protein *scale;
    this->recipe_nutrition.fat_per_100= total_fat *scale;
    this->recipe_nutrition.carbs_per_100= total_carb *scale;


}

void Recipe::AddIngridient(Ingridient ing) {
    this->ingridients.push_back(ing);
}

std::ostream& operator<<(std::ostream& os, const Recipe& recipe) {
    os << "Recipe Name: "<< recipe.name << std::endl
    << "##### Nutrition Values #####" << std::endl
    << "Calories per 100 g: " << recipe.recipe_nutrition.cal_per_100 << " kcal, " << std::endl
    << "Carbs per 100 g: " << recipe.recipe_nutrition.carbs_per_100 << " g, "<< std::endl
    << "Protein per 100 g: " << recipe.recipe_nutrition.protein_per_100 << " g, "<< std::endl
    << "Fat per 100 g: " << recipe.recipe_nutrition.fat_per_100 << " g, "<< std::endl;
    return os;
}


