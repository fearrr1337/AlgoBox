#pragma once
#include <algorithm>
#include <iterator>

namespace ab {

	template<typename Container, typename T, typename Compare = std::less< >>
	bool bool_binary_search(Container& arr, const T& value, Compare comp = Compare()) {
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
}