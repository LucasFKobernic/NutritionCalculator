#include <iostream>
#include <vector>
#include "Recipe.h"
/**
 * @brief Main execution entry point for the Nutrition Programm.
 *
 *
 * @param argc The number of command-line arguments. Expects 1, 2, 3, or 4 arguments (program name included).
 * @param argv An array of C-style strings containing the command-line arguments:
 * - argv[1]: (Optional) ...
 * - argv[2]: (Optional) ...
 * - argv[3]: (Optional) ...
 * Defaults to 'TEST'.
 * @return int Returns 0 on successful execution. Returns 1 if a critical error occurs 
 * (e.g., file saving failure, invalid directory path, or an error from underlying utilities).
 */
int main(){
    std::cout << "Starting Programm ..." << std::endl;
    Recipe Cheesecake ("Cheesecake", 100);
    Ingridient Mehl;
    Mehl.name = "Mehl";
    Mehl.amount_in_g=100;
    Mehl.nutrition.cal_per_100=100;
    Mehl.nutrition.protein_per_100=100;
    Mehl.nutrition.fat_per_100=100;
    Mehl.nutrition.carbs_per_100=100;

    Cheesecake.CalculateRecipeNutrition();
    std::cout << Cheesecake<< std::endl;
    return 0;
}