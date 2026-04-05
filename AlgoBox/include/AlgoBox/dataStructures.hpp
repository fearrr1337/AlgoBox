#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>


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
        size_t size() const{
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


}

