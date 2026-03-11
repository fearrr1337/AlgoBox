#include <vector>
#include <iostream>
#include "include/AlgoBox/sorting.hpp"

int main() {
    std::vector<int> vec = { 5, 2, 9, 1, 5, 6,123,123,123,123,123,123,12,31,23,3645784,8543,8,458,5,69,56969,569,4 };
    ab::merge_sort(vec); // по умолчанию std::less<> — сортировка по возрастанию

    std::cout << "Sorted vector: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
}