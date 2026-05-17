#include <vector>
#include <iostream>
#include "examples/headers/sorting_examples.hpp"




int main() {
    setlocale(LC_ALL, "RUS");

    // sortings
    test_bubble_sort();
    test_merge_sort();
    test_exchange_selection_sort();
    test_selection_sort();
    test_insertion_sort();
    test_shell_sort();

    

}