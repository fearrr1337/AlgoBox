#pragma once
#include <algorithm>
#include <iterator>

namespace ab {

    // BUBBLE SORT | O(n^2)
    template <typename Container, typename Compare = std::less<>>
    void bubble_sort(Container& arr, Compare comp = Compare())
    {
        auto first = std::begin(arr);
        auto last = std::end(arr);

        for (auto end = last; end != first; --end)
        {
            for (auto it = first; std::next(it) != end; ++it)
            {
                if (comp(*std::next(it), *it))
                    std::iter_swap(it, std::next(it));
            }
        }
    }


    // ============================================================


    // MERGE SORT | O(n log n)
    template <typename Container, typename Compare = std::less<>>
    void merge_sort(Container& arr, Compare comp = Compare()) {
        auto first = std::begin(arr);
        auto last = std::end(arr);

        auto distance = std::distance(first, last);
        if (distance <= 1)
            return;

        // Create a vector to store the left and right halves
        auto mid_it = std::next(first, distance / 2);
        Container left(first, mid_it);
        Container right(mid_it, last);

        // Recursive sorting
        merge_sort(left, comp);
        merge_sort(right, comp);

        // Merge the sorted halves back into the original container
        auto it = first;
        auto left_it = std::begin(left);
        auto right_it = std::begin(right);

        while (left_it != std::end(left) && right_it != std::end(right)) {
            if (comp(*left_it, *right_it)) {
                *it = *left_it;
                ++left_it;
            }
            else {
                *it = *right_it;
                ++right_it;
            }
            ++it;
        }

        // Copy the remaining elements, if any
        while (left_it != std::end(left)) { 
            *it++ = *left_it++; 
        }
        while (right_it != std::end(right)) { 
            *it++ = *right_it++; 
        }

    }


    // ============================================================

    // EXCHANGE SELECTION SORT | O(n^2)
    template<typename Container, typename Compare = std::less<>>
    void exchange_selection_sort(Container& arr, Compare comp = Compare()) {
        auto n = std::size(arr);
        if (n < 2) return;


        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                if (comp(arr[j], arr[i]) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    // STANDART SELECTION SORT | O(n^2)
    template<typename Container, typename Compare = std::less<>>
    void selection_sort(Container& arr, Compare comp = Compare()) {
        auto n = std::size(arr);
        if (n < 2) return;


        for (size_t i = 0; i < n - 1; i++) {
            size_t min_index = i;
            for (size_t j = i + 1; j < n; j++) {
                if (comp(arr[j], arr[min_index]) {
                    min_index = j;
                }
            }

            if (min_index != i) {
                std::swap(arr[i], arr[min_index]);
            }
        }
    }

    // ============================================================

    // INSERTION SORT | O(n + k), k - numbers of exchanges
    template<typename Container, typename Compare = std::less<>>
    void insertion_sort(Container& arr, Compare comp = Compare()) {
        auto n = std::size(arr);
        if (n < 2) return;

        for (size_t i = 1; i < n; i++) {
            long long j = i - 1;
            while (j >= 0 && comp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
                --j;
            }
        }
    }


    // ============================================================
    
    // SHELL SORT | O( n^1.25 ) - O( n^1.5 )
    template<typename Container, typename Compare = std::less<>>
    void shell_sort(Container& arr, Compare comp = Compare()) {
        auto n = std::size(arr);
        if (n < 2) return;
        for (size_t gap = n / 2; gap > 0; gap /= 2) {
            for (size_t i = gap; i < n; i += gap) {
                auto temp = arr[i];
                auto j = i;
                while (j >= gap && comp(arr[j - gap], temp)) {
                    arr[j] = std::move(arr[j - gap]);
                    j -= gap;
                }
                arr[j] = std::move(temp);
            }
        }
    }

    // ============================================================

}
