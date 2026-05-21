#include "../headers/dataStructures_examples.hpp"
#include "../../include/AlgoBox/dataStructures.hpp"
#include <iostream>
#include <cassert>

void test_stack() {
    ab::stack<int> st;

    std::cout << "СТЕК\n";

    st.push(10);
    st.push(20);
    st.push(30);

    std::cout << "Добавлены элементы: 10, 20, 30\n";
    std::cout << "Верхний элемент: " << st.top() << std::endl;
    std::cout << "Размер: " << st.size() << std::endl;

    assert(st.top() == 30);
    assert(st.size() == 3);

    st.pop();

    std::cout << "Удалён один элемент\n";
    std::cout << "Новый верхний элемент: " << st.top() << std::endl;

    assert(st.top() == 20);

    st.pop();
    st.pop();

    assert(st.empty() == true);

    std::cout << "Стек пуст: " << (st.empty() ? "true" : "false") << std::endl;

    std::cout << std::endl;
}

void test_queue() {
    ab::queue<int> q;

    std::cout << "ОЧЕРЕДЬ (FIFO)\n";

    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "Добавлены элементы: 1, 2, 3\n";

    std::cout << "Первый элемент (front): " << q.front() << std::endl;
    std::cout << "Последний элемент (back): " << q.back() << std::endl;
    std::cout << "Размер: " << q.size() << std::endl;

    assert(q.front() == 1);
    assert(q.back() == 3);
    assert(q.size() == 3);

    q.pop();

    std::cout << "Удалён один элемент\n";

    std::cout << "Новый первый элемент: " << q.front() << std::endl;

    assert(q.front() == 2);

    q.pop();
    q.pop();

    assert(q.empty() == true);

    std::cout << "Очередь пуста: " << (q.empty() ? "true" : "false") << std::endl;

    std::cout << std::endl;
}

void test_deque() {
    ab::deque<int> dq;

    std::cout << "ДЕК (двусторонняя очередь)\n";

    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(10);
    dq.push_front(5);

    std::cout << "push_back: 20, 30\n";
    std::cout << "push_front: 10, 5\n";

    std::cout << "Первый элемент (front): " << dq.front() << std::endl;
    std::cout << "Последний элемент (back): " << dq.back() << std::endl;
    std::cout << "Размер: " << dq.size() << std::endl;

    assert(dq.front() == 5);
    assert(dq.back() == 30);
    assert(dq.size() == 4);

    dq.pop_front();

    std::cout << "pop_front()\n";
    std::cout << "Новый первый элемент: " << dq.front() << std::endl;

    assert(dq.front() == 10);

    dq.pop_back();

    std::cout << "pop_back()\n";
    std::cout << "Новый последний элемент: " << dq.back() << std::endl;

    assert(dq.back() == 20);

    dq.pop_front();
    dq.pop_back();

    assert(dq.empty() == true);

    std::cout << "Дек пуст: " << (dq.empty() ? "true" : "false") << std::endl;

    std::cout << std::endl;
}

void test_max_heap() {
    ab::max_heap<int> heap;

    std::cout << "MAX HEAP\n";

    heap.push(10);
    heap.push(30);
    heap.push(20);
    heap.push(50);
    heap.push(40);

    std::cout << "Добавлены элементы: 10, 30, 20, 50, 40\n";

    std::cout << "Верхний элемент: "
        << heap.top()
        << std::endl;

    std::cout << "Размер кучи: "
        << heap.size()
        << std::endl;

    assert(heap.top() == 50);
    assert(heap.size() == 5);

    heap.pop();

    std::cout << "Удаление верхнего элемента\n";

    std::cout << "Новый верхний элемент: "
        << heap.top()
        << std::endl;

    assert(heap.top() == 40);

    while (!heap.empty()) {
        heap.pop();
    }

    std::cout << "Куча пуста: "
        << (heap.empty() ? "true" : "false")
        << std::endl;

    assert(heap.empty() == true);

    std::cout << std::endl;
}

void test_min_heap() {
    ab::min_heap<int> heap;

    std::cout << "MIN HEAP\n";

    heap.push(50);
    heap.push(20);
    heap.push(40);
    heap.push(10);
    heap.push(30);

    std::cout << "Добавлены элементы: 50, 20, 40, 10, 30\n";

    std::cout << "Верхний элемент: "
        << heap.top()
        << std::endl;

    std::cout << "Размер кучи: "
        << heap.size()
        << std::endl;

    assert(heap.top() == 10);
    assert(heap.size() == 5);

    heap.pop();

    std::cout << "Удаление верхнего элемента\n";

    std::cout << "Новый верхний элемент: "
        << heap.top()
        << std::endl;

    assert(heap.top() == 20);

    while (!heap.empty()) {
        heap.pop();
    }

    std::cout << "Куча пуста: "
        << (heap.empty() ? "true" : "false")
        << std::endl;

    assert(heap.empty() == true);

    std::cout << std::endl;
}

void test_bst() {
    ab::bst<int> tree;

    std::cout << "BINARY SEARCH TREE\n";

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Добавлены элементы: "
        << "50, 30, 70, 20, 40, 60, 80\n";

    std::cout << "Inorder обход дерева: ";
    tree.print_inorder();

    bool has40 = tree.contains(40);
    bool has100 = tree.contains(100);

    std::cout << "Поиск 40: "
        << (has40 ? "найден" : "не найден")
        << std::endl;

    std::cout << "Поиск 100: "
        << (has100 ? "найден" : "не найден")
        << std::endl;

    assert(has40 == true);
    assert(has100 == false);

    tree.remove(70);

    std::cout << "Удаление элемента 70\n";

    std::cout << "Дерево после удаления: ";
    tree.print_inorder();

    assert(tree.contains(70) == false);

    std::cout << std::endl;
}

void test_treap() {
    ab::treap<int> tree;

    std::cout << "TREAP\n";

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    std::cout << "Добавлены элементы: "
        << "50, 30, 70, 20, 40\n";

    bool has30 = tree.contains(30);
    bool has100 = tree.contains(100);

    std::cout << "Поиск 30: "
        << (has30 ? "найден" : "не найден")
        << std::endl;

    std::cout << "Поиск 100: "
        << (has100 ? "найден" : "не найден")
        << std::endl;

    assert(has30 == true);
    assert(has100 == false);

    tree.remove(30);

    std::cout << "Удаление элемента 30\n";

    bool has30_after = tree.contains(30);

    std::cout << "Поиск 30 после удаления: "
        << (has30_after ? "найден" : "не найден")
        << std::endl;

    assert(has30_after == false);

    std::cout << std::endl;
}

void test_linked_list() {
    ab::linked_list<int> list;

    std::cout << "LINKED LIST\n";

    std::cout << "Список пуст: "
        << (list.empty() ? "true" : "false")
        << std::endl;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    std::cout << "push_back: 10, 20, 30\n";

    std::cout << "Front: "
        << list.front()
        << std::endl;

    std::cout << "Back: "
        << list.back()
        << std::endl;

    std::cout << "Размер списка: "
        << list.size()
        << std::endl;

    assert(list.front() == 10);
    assert(list.back() == 30);
    assert(list.size() == 3);

    list.pop_front();

    std::cout << "pop_front()\n";

    std::cout << "Новый front: "
        << list.front()
        << std::endl;

    assert(list.front() == 20);

    list.pop_back();

    std::cout << "pop_back()\n";

    std::cout << "Новый back: "
        << list.back()
        << std::endl;

    assert(list.back() == 20);

    list.pop_back();

    std::cout << "Список пуст после удаления: "
        << (list.empty() ? "true" : "false")
        << std::endl;

    assert(list.empty() == true);

    std::cout << std::endl;
}

void test_doubly_linked_list() {
    ab::doubly_linked_list<int> list;

    std::cout << "DOUBLY LINKED LIST\n";

    std::cout << "Список пуст: "
        << (list.empty() ? "true" : "false")
        << std::endl;

    list.push_back(20);
    list.push_back(30);

    list.push_front(10);
    list.push_front(5);

    std::cout << "push_back: 20, 30\n";
    std::cout << "push_front: 10, 5\n";

    std::cout << "Список слева направо: ";
    list.print_forward();

    std::cout << "Список справа налево: ";
    list.print_reverse();

    std::cout << "Front: "
        << list.front()
        << std::endl;

    std::cout << "Back: "
        << list.back()
        << std::endl;

    std::cout << "Размер списка: "
        << list.size()
        << std::endl;

    assert(list.front() == 5);
    assert(list.back() == 30);
    assert(list.size() == 4);

    list.pop_front();

    std::cout << "pop_front()\n";

    std::cout << "Новый front: "
        << list.front()
        << std::endl;

    assert(list.front() == 10);

    list.pop_back();

    std::cout << "pop_back()\n";

    std::cout << "Новый back: "
        << list.back()
        << std::endl;

    assert(list.back() == 20);

    std::cout << std::endl;
}

struct TestObject {
    int x;
    double y;

    TestObject(int a, double b)
        : x(a), y(b) {
    }
};

void test_arena() {
    ab::arena memory(1024);

    std::cout << "ARENA ALLOCATOR\n";

    int* a = memory.create<int>(42);
    double* b = memory.create<double>(3.14);

    TestObject* obj = memory.create<TestObject>(10, 5.5);

    std::cout << "int: "
        << *a
        << std::endl;

    std::cout << "double: "
        << *b
        << std::endl;

    std::cout << "TestObject.x: "
        << obj->x
        << std::endl;

    std::cout << "TestObject.y: "
        << obj->y
        << std::endl;

    assert(*a == 42);
    assert(*b == 3.14);

    assert(obj->x == 10);
    assert(obj->y == 5.5);

    memory.reset();

    std::cout << "Память арены сброшена\n";

    std::cout << std::endl;
}

void test_avl_tree() {
    ab::avl_tree<int> tree;

    std::cout << "AVL TREE\n";

    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(50);

    std::cout << "Добавлены элементы: "
        << "30, 20, 40, 10, 25, 50\n";

    bool has25 = tree.contains(25);
    bool has100 = tree.contains(100);

    std::cout << "Поиск 25: "
        << (has25 ? "найден" : "не найден")
        << std::endl;

    std::cout << "Поиск 100: "
        << (has100 ? "найден" : "не найден")
        << std::endl;

    assert(has25 == true);
    assert(has100 == false);

    std::cout << std::endl;
}

void test_red_black_tree() {
    ab::red_black_tree<int> tree;

    std::cout << "RED BLACK TREE\n";

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Добавлены элементы: "
        << "50, 30, 70, 20, 40, 60, 80\n";

    std::cout << "Элементы успешно вставлены "
        << "с автоматической балансировкой\n";

    std::cout << std::endl;
}

void test_hash_table() {
    ab::hash_table<std::string, int> table;

    std::cout << "HASH TABLE\n";

    table.insert("apple", 10);
    table.insert("banana", 20);
    table.insert("orange", 30);

    std::cout << "Добавлены пары:\n";
    std::cout << "apple -> 10\n";
    std::cout << "banana -> 20\n";
    std::cout << "orange -> 30\n";

    std::cout << "Размер таблицы: "
        << table.size()
        << std::endl;

    assert(table.size() == 3);

    bool has_apple = table.contains("apple");
    bool has_grape = table.contains("grape");

    std::cout << "Ключ apple: "
        << (has_apple ? "найден" : "не найден")
        << std::endl;

    std::cout << "Ключ grape: "
        << (has_grape ? "найден" : "не найден")
        << std::endl;

    assert(has_apple == true);
    assert(has_grape == false);

    std::cout << "Значение apple: "
        << table.get("apple")
        << std::endl;

    assert(table.get("apple") == 10);

    table.remove("banana");

    std::cout << "Удаление ключа banana\n";

    assert(table.contains("banana") == false);
    assert(table.size() == 2);

    std::cout << "Новый размер таблицы: "
        << table.size()
        << std::endl;

    std::cout << std::endl;
}