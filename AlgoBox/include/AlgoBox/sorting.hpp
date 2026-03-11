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

    // MERGE SORT | O(n log (n) )
    template <typename Container, typename Compare = std::less<>>
    void merge_sort(Container& arr, Compare comp = Compare()) {
        auto first = std::begin(arr);
        auto last = std::end(arr);

        auto distance = std::distance(first, last);
        if (distance <= 1)
            return;

        // —оздаем вектор дл€ хранени€ левой и правой половин
        auto mid_it = std::next(first, distance / 2);
        Container left(first, mid_it);
        Container right(mid_it, last);

        // –екурсивна€ сортировка
        merge_sort(left, comp);
        merge_sort(right, comp);

        // —ли€ние отсортированных половин обратно в исходный контейнер
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

        //  опируем оставшиес€ элементы, если они есть
        while (left_it != std::end(left)) { *it++ = *left_it++; }
        while (right_it != std::end(right)) { *it++ = *right_it++; }

    }



}