#pragma once
#include <iostream>
#include <memory>
#include <vector>

std::vector<std::shared_ptr<int>> generate(int count);

void print(const std::vector<std::shared_ptr<int>>& vector);
void add10(std::vector<std::shared_ptr<int>>& vector);
void sub10(int* element);
void sub10(std::vector<std::shared_ptr<int>>& vector);
