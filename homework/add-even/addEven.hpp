#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int total{};
    for (const auto& number : numbers) {
        if (number % 2 == 0) {
            total += number;
        }
    }
    return total;
}
