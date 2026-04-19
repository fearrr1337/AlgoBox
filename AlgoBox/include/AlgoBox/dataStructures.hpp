#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>
#include <new>


namespace ab {

    // Stack
    template<typename T>
    class stack {
    private:
        std::vector<T> data;

    public:
        // Add element
        void push(const T& value) {
            data.push_back(value);
        }

        // Del element
        void pop() {
            if (empty()) {
                throw std::out_of_range("Stack is empty");
            }
            data.pop_back();
        }

        // Get top element
        T& top() {
            if (empty()) {
                throw std::out_of_range("Stack is empty");
            }
            return data.back();
        }

        const T& top() const {
            if (empty()) {
                throw std::out_of_range("Stack is empty");
            }
        }

        // Empty test
        bool empty() {
            return data.empty();
        }

        // arr size
        size_t size() const {
            return data.size();
        }
    };

    // =======================================================================================


    // BASE QUEUE/DEQUE CLASS

    template<typename T>
    class RingBufferBase {
    protected:
        T* data; // arr
        size_t capacity; // size memory (max elements)
        size_t head; // first element (index)
        size_t tail; // last element (index)
        size_t count; // count elements in queue

        // Resize array
        void resize() {
            size_t new_capacity = capacity * 2;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < count; ++i) {
                new_data[i] = data[(head + i) % capacity];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
            head = 0;
            tail = count;
        }

    public:
        // Constructor (initial capacity can be specified)
        explicit RingBufferBase(size_t cap = 8)
            : capacity(cap), head(0), tail(0), count(0) {
            data = new T[capacity];
        }

        // Destructor
        ~RingBufferBase() {
            delete[] data;
        }


        bool empty() const {
            return count == 0;
        }

        size_t size() const {
            return count;
        }
    };

    // =======================================================================================

    // Queue (FIFO) ( ring buffer )

    template<typename T>
    class queue : public RingBufferBase<T> {
    public:
        using RingBufferBase<T>::RingBufferBase;   // inherit constructor

        // Add element
        void push(const T& value) {
            if (this->count == this->capacity) {
                this->resize();
            }
            this->data[this->tail] = value;
            this->tail = (this->tail + 1) % this->capacity;
            ++this->count;
        }

        // Del element
        void pop() {
            if (this->empty()) {
                throw std::out_of_range("queue is empty");
            }
            this->head = (this->head + 1) % this->capacity;
            --this->count;
        }

        // First element
        T& front() {
            if (this->empty()) {
                throw std::out_of_range("queue is empty");
            }
            return this->data[this->head];
        }

        const T& front() const {
            if (this->empty()) {
                throw std::out_of_range("queue is empty");
            }
            return this->data[this->head];
        }

        // Last element
        T& back() {
            if (this->empty()) {
                throw std::out_of_range("queue is empty");
            }
            return this->data[(this->tail + this->capacity - 1) % this->capacity];
        }

        const T& back() const {
            if (this->empty()) {
                throw std::out_of_range("queue is empty");
            }
            return this->data[(this->tail + this->capacity - 1) % this->capacity];
        }
    };

    // =======================================================================================

    // Deque

    template<typename T>
    class deque : public RingBufferBase<T> {
    public:
        using RingBufferBase<T>::RingBufferBase;   // inherit constructor

        // Element push back
        void push_back(const T& value) {
            if (this->count == this->capacity) {
                this->resize();
            }
            this->data[this->tail] = value;
            this->tail = (this->tail + 1) % this->capacity;
            ++this->count;
        }

        // Element push front
        void push_front(const T& value) {
            if (this->count == this->capacity) {
                this->resize();
            }
            this->head = (this->head + this->capacity - 1) % this->capacity;
            this->data[this->head] = value;
            ++this->count;
        }

        // Delete front element
        void pop_front() {
            if (this->empty()) {
                throw std::out_of_range("deque is empty");
            }
            this->head = (this->head + 1) % this->capacity;
            --this->count;
        }

        // Delete back element
        void pop_back() {
            if (this->empty()) {
                throw std::out_of_range("deque is empty");
            }
            this->tail = (this->tail + this->capacity - 1) % this->capacity;
            --this->count;
        }

        // Get the first element
        T& front() {
            if (this->empty()) {
                throw std::out_of_range("deque is empty");
            }
            return this->data[this->head];
        }

        const T& front() const {
            if (this->empty()) {
                throw std::out_of_range("deque is empty");
            }
            return this->data[this->head];
        }

        // Get the last element
        T& back() {
            if (this->empty()) {
                throw std::out_of_range("deque is empty");
            }
            return this->data[(this->tail + this->capacity - 1) % this->capacity];
        }

        const T& back() const {
            if (this->empty()) {
                throw std::out_of_range("deque is empty");
            }
            return this->data[(this->tail + this->capacity - 1) % this->capacity];
        }
    };


    // =======================================================================================

    // Heap base class
    template<typename T, typename Compare> // Compare - std::less<> or std::greater<>
    class heap_base {
    protected:
        std::vector<T> data; // heap storage
        Compare comp; // comparator

        // bubble up || O(log n) 
        void heapify_up(size_t i) {
            while (i > 0) {
                size_t parent = (i - 1) / 2;

                if (!comp(data[parent], data[i])) {
                    break;
                }

                std::swap(data[parent], data[i]);
                i = parent;
            }
        }

        // bubble down || O(log n) 
        void heapify_down(size_t i) {
            size_t n = data.size();

            while (true) {
                size_t left = 2 * i + 1;
                size_t right = 2 * i + 2;
                size_t best = i;

                if (left < n && comp(data[best], data[left])) {
                    best = left;
                }
                if (right < n && comp(data[best], data[right])) {
                    best = right;
                }
                if (best == i) {
                    break;
                }

                std::swap(data[i], data[best]);
                i = best;
            }
        }
    public:

        // Add element || O(log n) 
        void push(const T& value) {
            data.push_back(value);
            heapify_up(data.size() - 1);
        }

        // Del element || O(log n) 
        void pop() {
            if (empty()) {
                throw std::out_of_range("heap is empty");
            }

            std::swap(data[0], data.back());
            data.pop_back();
            heapify_down(0);
        }

        // Get first element || O(1)
        const T& top() const {
            if (empty()) {
                throw std::out_of_range("heap is empty");
            }
            return data[0];
        }

        // O(1)
        bool empty() const {
            return data.empty();
        }

        // O(1)
        size_t size() const {
            return data.size();
        }
    };


    // MAX Heap
    template <typename T>
    class max_heap : public heap_base<T, std::less<>> {};

    // MIN Heap
    template <typename T>
    class min_heap : public heap_base<T, std::greater<>> {};




    // =======================================================================================


    // BST (Binary Search Tree)
    template<typename T>
    class bst {
    private:
        struct Node {
            T value;
            Node* left;
            Node* right;

            Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
        };

        Node* root = nullptr;

        // insert
        Node* insert(Node* node, const T& value) {
            if (!node) {
                return new Node(value);
            }

            if (value < node->value) {
                node->left = insert(node->left, value);
            }
            else if (value > node->value) {
                node->right = insert(node->right, value);
            }

            return node;
        }

        // Search
        bool contains(Node* node, const T& value) const {
            if (!node) {
                return false;
            }

            if (value == node->value) {
                return true;
            }

            if (value < node->value) {
                return contains(node->left, value);
            }

            return contains(node->right, value);
        }

        // Find min
        Node* find_min(Node* node) {
            while (node && node->left) {
                node = node->left;
            }
            return node;
        }

        // Del 
        Node* remove(Node* node, const T& value) {
            if (!node) {
                return nullptr;
            }

            if (value < node->value) {
                node->left = remove(node->left, value);
            }
            else if (value > node->value) {
                node->right = remove(node->right, value);
            }
            else {
                if (!node->left) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                else if (!node->right) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                Node* temp = find_min(node->right);
                node->value = temp->value;
                node->right = remove(node->right, temp->value);
            }

            return node;
        }

        void inorder(Node* node) const {
            if (!node) {
                return;
            }

            inorder(node->left);
            std::cout << node->value << " ";
            inorder(node->right);
        }

        void clear(Node* node) {
            if (!node) {
                return;
            }

            clear(node->left);
            clear(node->right);
            delete node;
        }
    public:
        ~bst() {
            clear(root);
        }

        void insert(const T& value) {
            root = insert(root, value);
        }

        void remove(const T& value) {
            root = remove(root, value);
        }

        bool contains(const T& value) const {
            return contains(root, value);
        }

        void print_inorder() const {
            inorder(root);
            std::cout << "\n";
        }

    };


    // =======================================================================================

    // TREAP 
    template<typename T>
    class treap {
    private:
        struct Node {
            T key;
            int priority;
            Node* left;
            Node* right;

            Node(const T& k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
        };

        Node* root = nullptr;

        // split
        void split(Node* node, const T& key, Node*& left, Node*& right) {
            if (!node) {
                left = right = nullptr;
            }
            else if (key < node->key) {
                split(node->left, key, left, node->left);
                right = node;
            }
            else {
                split(node->right, key, node->right, right);
                left = node;
            }
        }

        // merge trees
        Node* merge(Node* left, Node* right) {
            if (!left || !right) {
                return left ? left : right;
            }
            else if (left->priority > right->priority) {
                left->right = merge(left->right, right);
                return left;
            }
            else {
                right->left = merge(left, right->left);
                return right;
            }
        }

        // insert
        Node* insert(Node* node, Node* item) {
            if (!node) {
                return item;
            }

            if (item->priority > node->priority) {
                split(node, item->key, item->left, item->right);
                return item;
            }

            if (item->key < node->key) {
                node->left = insert(node->left, item);
            }
            else {
                node->right = insert(node->right, item);
            }

            return node;
        }


        // remove
        Node* remove(Node* node, const T& key) {
            if (!node) {
                return nullptr;
            }

            if (node->key == key) {
                Node* res = merge(node->left, node->right);
                delete node;
                reutrn res;
            }

            if (key < node->key) {
                node->left = remove(node->left, key);
            }
            else {
                node->right = remove(node->right, key);
            }

            return node;
        }


        // search
        bool contains(Node* node, const T& key) const {
            if (!node) {
                return false;
            }

            if (node->key == key) {
                return true;
            }

            if (key < node->key) {
                return contains(node->left, key);
            }
            else {
                return contains(node->right, key);
            }
        }

    public:
        void insert(const T& key) {
            root = insert(root, new Node(key));
        }

        void remove(const T& key) {
            root = remove(root, key);
        }

        bool contains(const T& key) const {
            return contains(root, key);
        }
  };


    // =======================================================================================

    // LINKED LIST


    // Node
    template<typename T>
    class Node {
    private:
        T data;
        Node* next;

    public:
        // Constructor
        Node(T val) : data(val), next(nullptr) {}

        // Get data
        T getData() const { 
            return data; 
        }

        // Set data
        void setData(const T& val) {
            data = val;
        }

        // Get next node
        Node* getNext() const {
            return next;
        }

        // Set next node
        void setNext(Node* node) {
            next = node;
        }
    };

    // LinkedList
    template<typename T>
    class linked_list {
    private:
        Node<T>* head;
        Node<T>* tail;
        size_t count;

        // Clear all nodes
        void clear() {
            while (head) {
                Node<T>* temp = head;
                head = head->getNext();
                delete temp;
            }
            tail = nullptr;
            count = 0;
        }

    public:
        // Constructor
        linked_list() : head(nullptr), tail(nullptr), count(0) {}

        // Destructor
        ~linked_list() {
            clear();
        }

        // Is empty test
        bool empty() {
            return count == 0;
        }

        // Size
        size_t size() {
            return count;
        }

        // Push back
        void push_back(const T& value) {
            Node<T>* new_node = new Node<T>(value);
            if (!head) {
                head = tail = new_node;
            }
            else {
                tail->setNext(new_node);
                tail = new_node;
            }
            ++count;
        }

        // Push front
        void push_front(const T& value) {
            Node<T>* new_node = new Node<T>(value);
            new_node->setNext(head);
            if (!tail) {
                tail = new_node;
            }
            ++count;
        }

        // Remove front 
        void pop_front() {
            if (empty()) {
                throw std::out_of_range("LinkedList is empty");
            }

            Node<T>* temp = head;
            head = head->getNext();
            if (!head) {
                tail = nullptr;
            }
            delete temp;
            --count;
        }

        // Remove back
        void pop_back() {
            if (empty()) {
                throw std::out_of_range("LinkedList is empty");
            }

            if (head == tail) {
                delete head;
                head = tail = nullptr;
            }
            else {
                Node<T>* curr = head;
                while (curr->getNext() != tail) {
                    curr = curr->getNext();
                }
                delete tail;
                tail = curr;
                tail->setNext(nullptr);
            }
            --count;
        }

        // Get front element
        T& front() {
            if (empty()) {
                throw std::out_of_range("LinkedList empty");
            }
            
            return head->getData();
        }

        // Get front element (const)
        const T& front() const{
            if (empty()) {
                throw std::out_of_range("LinkedList empty");
            }

            return head->getData();
        }

        // Get back element
        T& back() {
            if (empty()) {
                throw std::out_of_range("LinkedList empty");
            }

            return tail->getData();
        }

        // Get back element (const)
        const T& back() const {
            if (empty()) {
                throw std::out_of_range("LinkedList empty");
            }

            return tail->getData();
        }
        
        // Print list
        void print() const {
            Node<T>* curr = head;
            while (head) {
                std::cout << curr->getData() << " ";
                curr = curr->getNext();
            }
            std::cout << std::endl;
        }

    };

    // =======================================================================================

    // DOUBLY LINKED LIST

    // DOUBLY NODE
    template<typename T>
    class doubly_node {
    private:
        T data;
        doubly_node* next;
        doubly_node* prev;

    public:
        // Constructor
        doubly_node(T val = T()) : data(val), next(nullptr), prev(nullptr) {}

        // Get data
        T getData() const {
            return data;
        }

        // Set data
        void setData(const T& val) {
            data = val;
        }
        
        // Get next node
        doubly_node* getNext() const {
            return next;
        }

        // Set next node
        void setNext(doubly_node* node) {
            next = node;
        }

        // Get prev node
        doubly_node* getPrev() const {
            return prev;
        }

        // Set prev node
        void setPrev(doubly_node* node) {
            prev = node;
        }

    };

    // DOUBLE LINKED LIST
    template<typename T>
    class doubly_linked_list {
    private:
        doubly_node<T>* head;
        doubly_node<T>* tail;
        size_t count;

        // Cleat all nodes
        void clear() {
            while (head) {
                doubly_node<T>* temp = head;
                head = head->getNext();
                delete temp;
            }
            tail = nullptr;
            count = 0;
        }

    public:
        // Constructor 
        doubly_linked_list() : head(nullptr), tail(nullptr), count(0) {}

        // Destructor
        ~doubly_linked_list() {
            clear();
        }

        // Empty test
        bool empty() const {
            return count == 0;
        }

        // Size
        size_t size() const {
            return count;
        }

        // Push back
        void push_back(const T& value) {
            doubly_node<T>* new_node = new doubly_node<T>(value);
            if (!head) {
                head = tail = new_node;
            }
            else {
                tail->setNext(new_node);
                new_node->setPrev(tail);
                tail = new_node;
            }
            ++count;
        }

        // Push front
        void push_front(const T& value) {
            doubly_node<T>* new_node = new doubly_node<T>(value);
            if (!head) {
                head = tail = new_node();
            }
            else {
                new_node->setNext(head);
                head->setPrev(new_node);
                head = new_node;
            }
            ++count;
        }

        // Remove front 
        void pop_front() {
            if (empty()) {
                throw std::out_of_range("Doubly LinkedList is empty");
            }

            doubly_node<T>* temp = head;
            head = head->getNext();
            if (head) {
                head->setPrev(nullptr);
            }
            else {
                tail = nullptr;
            }

            delete temp;
            --count;
        }

        // Remove back
        void pop_back() {
            if (empty()) {
                throw std::out_of_range("Doubly LinkedList is empty");
            }

            doubly_node<T>* temp = tail;
            tail = tail->getPrev();
            if (tail) {
                tail->setNext(nullptr);
            }
            else {
                head = nullptr;
            }

            delete temp;
            --count;
        }

        // Front Element
        T& front() {
            if (empty()) {
                throw std::out_of_range("Doubly LinkedList is empty");
            }

            return head->getData();
        }


        // Front Element (const)
        const T& front() const {
            if (empty()) {
                throw std::out_of_range("Doubly LinkedList is empty");
            }

            return head->getData();
        }

        // Back Element
        T& back() {
            if (empty()) {
                throw std::out_of_range("Doubly LinkedList is empty");
            }

            return tail->getData();
        }

        // Back Element (consst)
        const T& back() const {
            if (empty()) {
                throw std::out_of_range("Doubly LinkedList is empty");
            }

            return tail->getData();
        }


        // Print forward
        void print_forward() const {
            doubly_node<T>* curr = head;
            while (curr) {
                std::cout << curr->getData() << " ";
                curr = curr->getNext();
            }
            std::cout << std::endl;
        }

        // Print reverse
        void print_reverse() const {
            doubly_node<T> curr = tail;
            while (curr) {
                std::count << curr->getData() << " ";
                curr = curr->getPrev();
            }
            std::cout << std::endl;
        }

    };

    // =======================================================================================
    

    // ARENA ALLOCATOR (BUMP ALLOCATOR)

    class arena {
    private:
        char* data; // beginning of memory
        size_t capacity; // overall size 
        size_t offset; // current position

    public:
        arena(size_t size) : capacity(size), offset(0) {
            data = static_cast<char*>(::operator new(size));
        }

        ~arena() {
            ::operator delete(data);
        }

        // memory allocation
        void* allocate(size_t size, size_t aligment = alignof(std::max_align_t)) {
            size_t current = reinterpret_cast<size_t>(data + offset);

            size_t aligned = (current + aligment - 1) & ~(aligment - 1);

            size_t new_offset = aligned - reinterpret_cast<size_t>(data) + size;

            if (new_offset > capacity) {
                throw std::bad_alloc();
            }

            offset = new_offset;
            return reinterpret_cast<void*>(aligned);
        }

        // create object
        template<typename T, typename... Args>
        T* create(Args&&... args) {
            void mem = allocate(sizeof(T), alignof(T));
            return new (mem) T(std::forward<Args>(args)...);
        }

        // reset all memory
        void reset() {
            offset = 0;
        }

    };
}
