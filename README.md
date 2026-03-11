# AlgoBox
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)  
[![C++11](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.cppreference.com/w/cpp/11)  
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/fear-calais/AlgoBox/actions)

**AlgoBox** — учебная библиотека алгоритмов на C++. Реализация классических алгоритмов: сортировки, поиск, деревья, графы, динамическое программирование и многое другое.

---

## ✨ Что внутри

- 🔹 **Сортировки:** Bubble, Insertion, Selection, Merge, Quick  
- 🔹 **Поиск:** Binary, Interpolation, Linear  
- 🔹 **Деревья:** BST, AVL, Heap (скоро)  
- 🔹 **Строки:** KMP, Rabin-Karp (скоро)  
- 🔹 **Графы:** BFS, DFS, Dijkstra (скоро)  
- 🔹 **Динамическое программирование:** Knapsack, LCS, Fibonacci (скоро)  

---

## 🚀 Быстрый старт

### Подключение

```cpp
#include <AlgoBox/sorting.hpp>
```

### Использование

```
#include <AlgoBox/sorting.hpp>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    AlgoBox::bubble_sort(data);        // Простая O(n²)
    // AlgoBox::quick_sort(data);      // Быстрая O(n log n)
    
    for (int x : data)
        std::cout << x << " ";         // 11 12 22 25 34 64 90
}
```

### 📁 Структура проекта

AlgoBox/
├── include/
│   └── AlgoBox/          # Заголовки (.hpp)
│       ├── sorting.hpp
│       ├── search.hpp
│       └── graphs.hpp
├── src/                  # Реализации (.cpp)
├── example/
│   └── main.cpp
└── AlgoBox.lib           # Статическая библиотека


### 🛠 Сборка (Visual Studio)

1) File → Open → AlgoBox.sln
2) Build → Build Solution (Ctrl+Shift+B)
3) Найти AlgoBox.lib в папке Debug/Release

Подключение в другом проекте:
```
#pragma comment(lib, "AlgoBox.lib")
#include <AlgoBox/sorting.hpp>
```

### 🎯 Зачем использовать AlgoBox?

✅ Обучение — простые реализации алгоритмов
✅ Демонстрация — показывай, как работают сортировки
✅ Маленькие данные — < 100 элементов
✅ Стабильность — когда важен порядок равных элементов

### 📜 Лицензия

MIT — свободное использование в любых проектах.

##3 🐛 Баги и предложения

Создай Issue в репозитории.
