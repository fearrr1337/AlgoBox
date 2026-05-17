#include "../headers/sorting_examples.hpp"
#include <iostream>
#include <vector>
#include <cassert>

void print_vector(const std::vector<int>& v) {
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void test_bubble_sort() {
    std::vector<int> v = { 5, 2, 4, 1 };

    std::cout << "Bubble sort\n";
    std::cout << "Before: ";
    print_vector(v);

    ab::bubble_sort(v);

    std::cout << "After:  ";
    print_vector(v);
    std::cout << std::endl;

    assert((v == std::vector<int>{1, 2, 4, 5}));
}

void test_merge_sort() {
    std::vector<int> v = { 9, 3, 7, 1 };

    std::cout << "Merge sort\n";
    std::cout << "Before: ";
    print_vector(v);

    ab::merge_sort(v);

    std::cout << "After:  ";
    print_vector(v);
    std::cout << std::endl;

    assert((v == std::vector<int>{1, 3, 7, 9}));
}

void test_exchange_selection_sort() {
    std::vector<int> v = { 4, 2, 1, 3 };

    std::cout << "Exchange selection sort\n";
    std::cout << "Before: ";
    print_vector(v);

    ab::exchange_selection_sort(v);

    std::cout << "After:  ";
    print_vector(v);
    std::cout << std::endl;

    assert((v == std::vector<int>{1, 2, 3, 4}));
}

void test_selection_sort() {
    std::vector<int> v = { 8, 5, 2, 6 };

    std::cout << "Selection sort\n";
    std::cout << "Before: ";
    print_vector(v);

    ab::selection_sort(v);

    std::cout << "After:  ";
    print_vector(v);
    std::cout << std::endl;

    assert((v == std::vector<int>{2, 5, 6, 8}));
}

void test_insertion_sort() {
    std::vector<int> v = { 7, 4, 1, 9 };

    std::cout << "Insertion sort\n";
    std::cout << "Before: ";
    print_vector(v);

    ab::insertion_sort(v);

    std::cout << "After:  ";
    print_vector(v);
    std::cout << std::endl;

    assert((v == std::vector<int>{1, 4, 7, 9}));
}

void test_shell_sort() {
    std::vector<int> v = { 12, 34, 54, 2, 3 };

    std::cout << "Shell sort\n";
    std::cout << "Before: ";
    print_vector(v);

    ab::shell_sort(v);

    std::cout << "After:  ";
    print_vector(v);
    std::cout << std::endl;

    assert((v == std::vector<int>{2, 3, 12, 34, 54}));
}