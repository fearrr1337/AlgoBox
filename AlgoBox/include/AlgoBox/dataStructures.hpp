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

}