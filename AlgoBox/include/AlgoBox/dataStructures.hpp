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


	// Queue
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


}