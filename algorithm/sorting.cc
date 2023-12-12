#include <iostream>
#include <random>

using namespace std;

namespace algorithm {
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;

	};
	template <typename T>	
	stats bubble_sort(std::vector<T> & arr) {
		stats sorting_results;
		int n = arr.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				sorting_results.comparison_count += 1;
				if (arr[j] > arr[j + 1]) {
					sorting_results.copy_count += 3;
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		return sorting_results;
	}
	template<typename T>
	std::ostream& operator << (std::ostream& os, const std::vector<T> vec)
	{
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
	std::ostream& operator <<(std::ostream& os, const stats description) {
		os << "Compasion count: " << description.comparison_count << "; " << "Copy count: " << description.copy_count << endl;
		return os;
	}
}