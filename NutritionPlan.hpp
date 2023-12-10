#include <iostream>
#include <string>
#include <vector>

struct Meal {
    std::string name;
    int calories;
    int carbs;
    int fats;
    int proteins;

    Meal(const std::string& n, int cal, int c, int f, int p)
        : name(n), calories(cal), carbs(c), fats(f), proteins(p) {}
};

class NutritionPlan {
private:
    std::vector<Meal> mealPlan;

public:
    void addMeal(const Meal& meal);
    int getTotalCalories() const;
    int getTotalCarbs() const;
    int getTotalFats() const;
    int getTotalProteins() const;
};
