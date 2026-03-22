#pragma once
#include <vector>
#include <stdexcept>

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


	// Queue ( ring buffer ) 
	template<typename T>
	class queue {
	private:
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
				new_data[i] = data[(head + 1) % capacity];
			}
			delete[] data;
			data = new_data;
			capacity = new_capacity;
			head = 0;
			tail = count;
		}

	public:
		queue(size_t cap = 8) : capacity(cap), head(0), tail(0), count(0) { data = new T[capacity]; }

		~queue() { delete[] data; }

		// Add element
		void push(const T& value) {
			if (count == capacity) {
				resize();
			}

			data[tail] = value;
			tail = (tail + 1) % capacity;
			++count;
		}

		// Del element
		void pop() {
			if (empty()) {
				throw std::out_of_range("queue is empty");
			}
			head = (head + 1) % capacity;
			--count;
		}

		// First element
		T& front() {
			if (empty()) {
				throw std::out_of_range("queue is empty");
			}
			return data[head];
		}

		const T& front() const {
            if (empty())
                throw std::out_of_range("queue is empty");

            return data[head];
        }

		// Last element
		T& back() {
			if (empty()) {
				throw std::out_of_range("queue is empty");
			}

			return data[(tail + capacity - 1) % capacity];
		}

		bool empty() const {
			return count == 0;
		}

		size_t size() const {
			return count;
		}
	};

	// =======================================================================================

	// Deque

	template<typename T>
	class deque {
	private:
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
		deque(size_t cap = 8) : capacity(cap), head(0), tail(0), count(0) {
			data = new T[capacity];
		}

		~deque() {
			delete[] data;
		}

		// Element push back
		void push_back(const T& value) {
			if (count == capacity) {
				resize();
			}

			data[tail] = value;
			tail = (tail + 1) % capacity;
			++count;
		}

		// Element push front
		void push_front(const T& value) {
			if (count == capacity) {
				resize();
			}

			head = (head + capacity - 1) % capacity;
			data[head] = value;
			++count;
		}

		// Delete front element
		void pop_front() {
			if (empty()) {
				throw std::out_of_range("deque is empty");
			}

			head = (head + 1) % capacity;
			--count;
		}

		// Delete back element
		void pop_back() {
			if (empty()) {
				throw std::out_of_range("deque is empty");
			}

			tail = (tail + capacity - 1) % capacity;
			--count;
		}

		// Get the first element
		T& front() {
			if (empty()) {
				throw std::out_of_range("deque is empty");
			}

			return data[head];
		}

		// Get the last element
		T& back() {
			if (empty()) {
				throw std::out_of_range("deque is empty");
			}

			return data[(tail + capacity - 1) % capacity];
		}

		bool empty() {
			return count == 0;
		}

		size_t size() {
			return count;
		}



	};


}