#include <iostream>
#include <random>
#include <vector>

using namespace std;

namespace algorithm {
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
		stats() : comparison_count(0), copy_count(0) {}
		stats(const stats& other) {
			comparison_count = other.comparison_count;
			copy_count = other.copy_count;
		}
		stats& operator=(const stats& other) {
			comparison_count = other.comparison_count;
			copy_count = other.copy_count;
		}
	};
	template<typename T>
	void swap(T& a, T& b, stats& stats) {
		T temp = a;
		a = b;
		b = temp;
		stats.copy_count += 3;
	}
	template <typename T>	
	stats bubble_sort(vector<T> & arr) {
		stats sorting_results;
		int n = arr.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				sorting_results.comparison_count++;
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1], sorting_results);
				}
			}
		}
		return sorting_results;
	}
	template<typename T>
	int partition(vector<T>& arr, int low, int high, stats& stats) {
		T pivot = arr[high];
		int i = (low - 1);
		for (int j = low; j <= high - 1; j++) {
			if (arr[j] <= pivot) {
				i++;
				swap(arr[i], arr[j], stats);
			}
			stats.comparison_count++;
		}
		swap(arr[i + 1], arr[high], stats);
		return (i + 1);
	}
	template<typename T>
	stats quick_sort(vector<T>& arr, int low, int high) {
		stats stat;
		if (low < high) {
			int pi = partition(arr, low, high, stat);
			stats left_stats = quick_sort(arr, low, pi - 1);
			stats right_stats = quick_sort(arr, pi + 1, high);
			stat.comparison_count+= left_stats.comparison_count + right_stats.comparison_count;
			stat.copy_count += left_stats.copy_count + right_stats.copy_count;
		}
		return stat;
	}
	template<typename T>
	void pyramid(vector<T>& arr, int n, int i, stats& stats) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < n && ++stats.comparison_count && arr[left] > arr[largest])
			largest = left;
		if (right < n && ++stats.comparison_count && arr[right] > arr[largest])
			largest = right;
		if (largest != i) {
			swap(arr[i], arr[largest], stats);
			++stats.copy_count;
			pyramid(arr, n, largest, stats);
		}
	}
	template<typename T>
	stats pyramid_sort(vector<T>& arr) {
		stats stat;
		stat.comparison_count = 0;
		stat.copy_count = 0;
		int n = arr.size();
		for (int i = n / 2 - 1; i >= 0; --i)
			pyramid(arr, n, i, stat);
		for (int i = n - 1; i >= 0; --i) {
			swap(arr[0], arr[i], stat);
			++stat.copy_count;
			pyramid(arr, i, 0, stat);
		}
		return stat;
	}
	template<typename T>
	ostream& operator << (ostream& os, const vector<T> vec) {
		os << "{ ";
		for (int i = 0; i < vec.size(); i++) {
			if (i < vec.size() - 1)
				os << vec[i] << ", ";
			else {
				os << vec[i] << " }" << endl;
			}
		}
		return os;
	}
	ostream& operator <<(ostream& os, const stats description) {
		os << "Compasion count: " << description.comparison_count << "; " << "Copy count: " << description.copy_count << endl;
		return os;
	}
}