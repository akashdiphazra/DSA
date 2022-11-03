#include <assert.h>

#include <array>
#include <iostream>
#include <vector>

namespace Dynamic_Programming {
class Knapsack {
 public:
    /* Knapsack Iterative */
    template <size_t n>
    int max_knapsack_value_iterative(const int capacity,
                                     const std::array<int, n> &weights,
                                     const std::array<int, n> &values) {
        std::vector<std::vector<int>> max_value(
            n + 1, std::vector<int>(capacity + 1, 0));

        int items = sizeof(weights) / sizeof(weights[0]);
        for (int_fast64_t i{}; i < items + 1; ++i) {
            for (int_fast64_t j{}; j < capacity + 1; ++j) {
                if (i == 0 || j == 0) {
                    max_value[i][j] = 0;
                } else if (weights[i - 1] <= j) {
                    int profit1 =
                        values[i - 1] + max_value[i - 1][j - weights[i - 1]];

                    int profit2 = max_value[i - 1][j];

                    max_value[i][j] = std::max(profit1, profit2);

                } else {
                    max_value[i][j] = max_value[i - 1][j];
                }
            }
        }
        return max_value[items][capacity];
    }

    /* Knapsack Recursive */
    template <size_t n>
    int max_knapsack_value_recursive(const int capacity,
                                     const std::array<int, n> &weights,
                                     const std::array<int, n> &values,
                                     int items) {
        if (items == 0 || capacity == 0) {
            return 0;
        }
        if (weights[items - 1] > capacity) {
            return max_knapsack_value_recursive(capacity, weights, values,
                                                items - 1);
        } else
            return std::max(
                values[items - 1] +
                    max_knapsack_value_recursive(capacity - weights[items - 1],
                                                 weights, values, items - 1),
                max_knapsack_value_recursive(capacity, weights, values,
                                             items - 1));
    }
};
};  // namespace Dynamic_Programming

void test1() {
    const int n1 = 3;
    const int capacity1 = 50;
    std::array<int, n1> weight1 = {10, 20, 30};   // weight of each item
    std::array<int, n1> value1 = {60, 100, 120};  // value of each item
    Dynamic_Programming::Knapsack k1;
    assert(k1.max_knapsack_value_iterative(capacity1, weight1, value1) == 220);
    std::cout << "TEST CASE 1 : PASSED" << std::endl;

    const int n2 = 4;
    const int capacity2 = 25;
    std::array<int, n2> weight2 = {24, 10, 10, 7};  // weight of each item
    std::array<int, n2> value2 = {24, 18, 18, 10};  // value of each item
    Dynamic_Programming::Knapsack k2;
    assert(k2.max_knapsack_value_iterative(capacity2, weight2, value2) == 36);
    std::cout << "TEST CASE 2 : PASSED" << std::endl;
}

void test2() {
    const int n1 = 3;
    const int capacity1 = 50;
    std::array<int, n1> weight1 = {10, 20, 30};   // weight of each item
    std::array<int, n1> value1 = {60, 100, 120};  // value of each item
    Dynamic_Programming::Knapsack k1;
    int items1 = sizeof(weight1) / sizeof(weight1[0]);
    assert(k1.max_knapsack_value_recursive(capacity1, weight1, value1,
                                           items1) == 220);
    std::cout << "TEST CASE 1 : PASSED" << std::endl;

    const int n2 = 4;
    const int capacity2 = 25;
    std::array<int, n2> weight2 = {24, 10, 10, 7};  // weight of each item
    std::array<int, n2> value2 = {24, 18, 18, 10};  // value of each item
    Dynamic_Programming::Knapsack k2;
    int items2 = sizeof(weight2) / sizeof(weight2[0]);
    assert(k2.max_knapsack_value_recursive(capacity2, weight2, value2,
                                           items2) == 36);
    std::cout << "TEST CASE 2 : PASSED" << std::endl;
}

int main() {
    std::cout << "Knapsack Iterative" << std::endl;
    test1();
    std::cout << "Knapsack Recursive" << std::endl;
    test2();
    return 0;
}