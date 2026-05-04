#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

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

	// Prefix sum

	template<typename It>
	auto prefix_sum(It first, It last) {
		using T = typename std::iterator_traits<It>::value_type;

		std::vector<T> pref;

		if (first == last) {
			return pref;
		}

		pref.reverse(std::distance(first, last));

		T sum = 0;
		for (auto it = first; it != last; ++it) {
			sum += *it;
			pref.push_back(sum);
		}

		return pref;
	}

	// Prefix sum in range [l, r]

	template<typename Container>
	auto range_sum(const Container& pref, size_t l, size_t r) {
		if (l == 0) {
			return pref[r];
		}
		return pref[r] - pref[l - 1];
	}

	// ===================================================================================

	// binary search + sum prefix

	template<typename Container, typename T>
	int lower_bound_prefix(const Container& pref, const T& target) {
		auto it = std::lower_bound(std::begin(pref), std::end(pref), target);

		if (it == std::end(pref)) {
			return -1;
		}

		return static_cast<int>(std::distance(std::begin(pref), it));
	}

	// ===================================================================================

	// Scaning Line

	template<typename It>
	int scaning_line(It first, It end) {
		using Pair = typename std::iterator<It>::value_type;

		struct Event {
			int x;
			int type;
		};

		std::vector<Event> events;

		for (auto it = first; it != last; ++it) {
			events.push_back({ it->first, +1 });
			events.push_back({ it->second, -1 });
		}

		std::sort(events.begin(), events.end(), [](auto& a, auto& b) {
			if (a.x == b.x) {
				return a.type > b.type;
			}
			return a.x < b.x;
		});

		int cur = 0, ans = 0;

		for (auto& e : events) {
			cur += e.type;
			ans = std::max(ans, cur);
		}

		return ans;
	}
		 
}
