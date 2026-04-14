#pragma once
#include <algorithm>
#include <iterator>

namespace ab {

	// Binary Search | return true or false | O(log n)
	template<typename Container, typename T, typename Compare = std::less< >>
	bool binary_search_bool(Container& arr, const T& value, Compare comp = Compare()) {
		auto n = std::size(arr);
		if (n == 0) return false;

		size_t left = 0;
		size_t right = n - 1;

		while (left <= right) {
			size_t mid = left + (right - left) / 2;
			const auto& el = arr[mid];

			if (comp(el, value)) {
				left = mid + 1;
			}
			else if (comp(value, el)) {
				right = mid - 1;
			}
			else {
				return true;
			}
		}

		return false;

	}


	// Binary Search | Search Index target element | O(log n)
	template<typename Container, typename T, typename Compare = std::less<>>
	size_t binary_search_index(Container& arr, const T& value, Compare comp = Compare()) {
		auto n = std::size(arr);
		if (n == 0) return -1;

		size_t left = 0;
		size_t right = n - 1;

		while (left <= right) {
			size_t mid = left + (right - left) / 2;
			const auto& el = arr[mid];

			if (comp(el, value)) {
				left = mid + 1;
			}
			else if (comp(value, el)) {
				if (mid == 0) {
					return n;
				}
				right = mid - 1;
			}
			else {
				return mid;
			}
		}

		return -1;
	}

	// ===================================================================================

	// Linear Search | Search Index | O(n)
	template<typename Container, typename T>
	size_t linear_search_index(Container& arr, const T& target) {
		auto n = std::size(arr);
		if (n == 0) return -1;

		for (size_t i = 0; i < n; i++) {
			if (target == arr[i]) {
				return i;
			}
		}

		return -1;

	}

	// Linear Search | return true or false | O(n)
	template<typename Container, typename T>
	bool linear_search_bool(Container& arr, const T& target) {
		auto n = std::size(arr);
		if (n == 0) return false;

		for (size_t i = 0; i < n; i++) {
			if (target == arr[i]) {
				return true;
			}
		}

		return false;
	}

	// ===================================================================================


}
