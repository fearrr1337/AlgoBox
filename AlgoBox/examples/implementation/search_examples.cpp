#include "../headers/search_examples.hpp"
#include "../../include/AlgoBox/search.hpp"  
#include <iostream>
#include <vector>
#include <cassert>
#include <utility>   

static void print_vector(const std::vector<int>& v) {
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

static void print_intervals(const std::vector<std::pair<int, int>>& intervals) {
    for (const auto& p : intervals) {
        std::cout << "[" << p.first << ", " << p.second << "] ";
    }
    std::cout << std::endl;
}

void test_binary_search_bool() {
    std::vector<int> v = { 1, 3, 5, 7, 9, 11 };
    std::cout << "Бинарный поиск (наличие)\n";
    std::cout << "Массив: ";
    print_vector(v);

    bool found1 = ab::binary_search_bool(v, 5);
    bool found2 = ab::binary_search_bool(v, 6);

    std::cout << "Поиск 5: " << (found1 ? "найден" : "не найден") << std::endl;
    std::cout << "Поиск 6: " << (found2 ? "найден" : "не найден") << std::endl;

    assert(found1 == true);
    assert(found2 == false);
    std::cout << std::endl;
}

void test_binary_search_index() {
    std::vector<int> v = { 2, 4, 6, 8, 10 };
    std::cout << "Бинарный поиск (индекс)\n";
    std::cout << "Массив: ";
    print_vector(v);

    size_t idx1 = ab::binary_search_index(v, 6);
    size_t idx2 = ab::binary_search_index(v, 7);

    std::cout << "Индекс 6: " << idx1 << std::endl;
    std::cout << "Индекс 7: " << idx2 << " (не найдено)" << std::endl;

    assert(idx1 == 2);
    assert(idx2 == static_cast<size_t>(-1));
    std::cout << std::endl;
}

void test_linear_search_index() {
    std::vector<int> v = { 42, 17, 8, 99, 23 };
    std::cout << "Линейный поиск (индекс)\n";
    std::cout << "Массив: ";
    print_vector(v);

    size_t idx1 = ab::linear_search_index(v, 8);
    size_t idx2 = ab::linear_search_index(v, 100);

    std::cout << "Индекс 8: " << idx1 << std::endl;
    std::cout << "Индекс 100: " << idx2 << " (не найдено)" << std::endl;

    assert(idx1 == 2);
    assert(idx2 == static_cast<size_t>(-1));
    std::cout << std::endl;
}

void test_linear_search_bool() {
    std::vector<int> v = { 5, 10, 15, 20 };
    std::cout << "Линейный поиск (наличие)\n";
    std::cout << "Массив: ";
    print_vector(v);

    bool found1 = ab::linear_search_bool(v, 10);
    bool found2 = ab::linear_search_bool(v, 12);

    std::cout << "Поиск 10: " << (found1 ? "найден" : "не найден") << std::endl;
    std::cout << "Поиск 12: " << (found2 ? "найден" : "не найден") << std::endl;

    assert(found1 == true);
    assert(found2 == false);
    std::cout << std::endl;
}

void test_prefix_sum() {
    std::vector<int> v = { 3, 1, 4, 1, 5 };
    std::cout << "Префиксные суммы\n";
    std::cout << "Исходный: ";
    print_vector(v);

    std::vector<int> pref = ab::prefix_sum(v.begin(), v.end());
    std::cout << "Префиксные суммы: ";
    print_vector(pref);

    assert(pref.size() == v.size());
    assert(pref[0] == 3);
    assert(pref[1] == 4);
    assert(pref[2] == 8);
    assert(pref[3] == 9);
    assert(pref[4] == 14);

    std::cout << std::endl;
}

void test_range_sum() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    std::vector<int> pref = ab::prefix_sum(v.begin(), v.end());
    std::cout << "Сумма на отрезке\n";
    std::cout << "Массив: ";
    print_vector(v);
    std::cout << "Префиксные суммы: ";
    print_vector(pref);

    int sum_1_3 = ab::range_sum(pref, 1, 3);
    int sum_0_4 = ab::range_sum(pref, 0, 4);

    std::cout << "Сумма [1..3] = " << sum_1_3 << std::endl;
    std::cout << "Сумма [0..4] = " << sum_0_4 << std::endl;

    assert(sum_1_3 == 9);
    assert(sum_0_4 == 15);
    std::cout << std::endl;
}

void test_lower_bound_prefix() {
    std::vector<int> v = { 2, 3, 5, 7, 11 };
    std::vector<int> pref = ab::prefix_sum(v.begin(), v.end());

    int target1 = 6;
    int target2 = 50;

    int pos1 = ab::lower_bound_prefix(pref, target1);
    int pos2 = ab::lower_bound_prefix(pref, target2);

    assert(pos1 == 2);
    assert(pos2 == -1);
}

void test_scanning_line() {
    std::vector<std::pair<int, int>> intervals = { {1, 3}, {2, 5}, {4, 6} };
    std::cout << "Сканирующая прямая (максимум пересечений)\n";
    std::cout << "Интервалы: ";
    print_intervals(intervals);

    int max_overlap = ab::scaning_line(intervals.begin(), intervals.end());
    std::cout << "Максимальное количество перекрывающихся интервалов: " << max_overlap << std::endl;

    assert(max_overlap == 2);
    std::cout << std::endl;
}