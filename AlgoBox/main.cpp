#include <vector>
#include <iostream>
#include "examples/headers/sorting_examples.hpp"
#include "examples/headers/search_examples.hpp"
#include "examples/headers/dataStructures_examples.hpp"




int main() {
    setlocale(LC_ALL, "RUS");

    //// sortings
    //test_bubble_sort();
    //test_merge_sort();
    //test_exchange_selection_sort();
    //test_selection_sort();
    //test_insertion_sort();
    //test_shell_sort();

    // search
    /*test_binary_search_bool();
    test_binary_search_index();
    test_linear_search_index();
    test_linear_search_bool();
    test_prefix_sum();
    test_range_sum();
    test_lower_bound_prefix();
    test_scanning_line();*/

    // DataStructures
    test_stack();
    test_queue();
    test_deque();
    test_max_heap();
    test_min_heap();
    test_bst();
    test_treap();
    test_linked_list();
    test_doubly_linked_list();
    test_arena();
    test_avl_tree();
    test_red_black_tree();
    test_hash_table();

    

}