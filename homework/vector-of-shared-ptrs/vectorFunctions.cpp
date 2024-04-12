#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vector{};
    for (int i{0}; i < count; ++i) {
        vector.push_back(std::make_shared<int>(i));
    }
    return vector;
}

void print(const std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& element : vector) {
        if (element) {
            std::cout << *element << std::endl;
        }
    }
}

void add10(std::vector<std::shared_ptr<int>>& vector) {
    for (auto element : vector) {
        if (element) {
            *element += 10;
        }
    }
}

void sub10(int* element) {
    if (element != nullptr) {
        *element -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vector) {
    for (auto element : vector) {
        sub10(element.get());
    }
}
