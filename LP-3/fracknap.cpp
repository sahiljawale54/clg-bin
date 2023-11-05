#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Custom comparison function to sort items by value per unit weight
bool compareItems(const Item& a, const Item& b) {
    double valuePerWeightA = static_cast<double>(a.value) / a.weight;
    double valuePerWeightB = static_cast<double>(b.value) / b.weight;
    return valuePerWeightA > valuePerWeightB;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(vector<Item> items, int capacity) {
    // Sort items by value per unit weight in non-increasing order
    sort(items.begin(), items.end(), compareItems);

    double maxValue = 0.0; // Initialize the result

    for (const Item& item : items) {
        if (capacity == 0) {
            break; // The knapsack is full
        }

        if (item.weight <= capacity) {
            // Take the whole item
            maxValue += item.value;
            capacity -= item.weight;
        } else {
            // Take a fraction of the item
            double fraction = static_cast<double>(capacity) / item.weight;
            maxValue += fraction * item.value;
            break;
        }
    }

    return maxValue;
}

int main() {
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };
    int knapsackCapacity = 50;

    double maxTotalValue = fractionalKnapsack(items, knapsackCapacity);

    cout << "Maximum total value: " << maxTotalValue << endl;

    return 0;
}
