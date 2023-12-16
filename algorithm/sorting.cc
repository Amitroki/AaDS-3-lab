#include <iostream>
#include <random>
#include <vector>
#include <fstream>

using namespace std;

namespace algorithm {
	vector<int> random_seed(int a, int b, int n, int seed) {
		vector<int> res;
		mt19937 generator(seed);
		uniform_int_distribution<> distribution(a, b);
		for (int i = 0; i < n; i++) {
			int x = distribution(generator);
			res.push_back(x);
		}
		return res;
	}
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
		stats& operator+=(const stats& other) {
			comparison_count += other.comparison_count;
			copy_count += other.copy_count;
			return *this;
		}
		stats& operator/(const int other) {
			comparison_count /= other;
			copy_count /= other;
			return *this;
		}
	};
	vector<int> ordered_vector(int n) {
		vector<int> vector;
		for (int i = 1; i <= n; i++) {
			vector.push_back(i);
		}
		return vector;
	}
	vector<int> reversed_ordered_vector(int n) {
		vector<int> vector;
		for (int i = n; i > 0; i--) {
			vector.push_back(i);
		}
		return vector;
	}
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
	stats create_random_vector(int length_vector, int trial_count, int sort) {
		stats stat;
		for (int i = 0; i < trial_count; i++) {
			std::vector<int> test = random_seed(-1000, 1000, length_vector, i);
			cout << "iteration: " << i << endl;
			switch (sort) {
			case 1:
				stat += bubble_sort(test);
				break;
			case 2:
				stat += quick_sort(test, 0, test.size() - 1);
				break;
			case 3:
				stat += pyramid_sort(test);
				break;
			}
		}
		stat = stat / trial_count;
		return stat;
	}
	vector<stats> create_hundred_random_vectors(int sort_choice) {
		vector<stats> stat;
		for (int i = 1; i < 11; i++) {
			stat.push_back(create_random_vector(i * 1000, 100, sort_choice));
			cout << "len: " << i * 1000 << endl;
		}
		cout << "len: " << 25000 << endl;
		stat.push_back(create_random_vector(25000, 100, sort_choice));
		cout << "len: " << 50000 << endl;
		stat.push_back(create_random_vector(50000, 100, sort_choice));
		cout << "len: " << 100000 << endl;
		stat.push_back(create_random_vector(100000, 100, sort_choice));
		return stat;
	}
	void write_to_file(vector<stats> stat) {
		ofstream out;
		out.open("C:/Users/Alex/Desktop/AaDS/lab_3/random_bubble.txt");
		for (int i = 0; i < stat.size(); i++) {
			out << stat[i].comparison_count << " " << stat[i].copy_count << endl;
		}
		out.close();
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
	bool operator<(const string& lhs, const string& rhs) {
		return lhs.compare(rhs) < 0;
	}
	bool operator>(const string& lhs, const string& rhs) {
		return lhs.compare(rhs) > 0;
	}
	ostream& operator <<(ostream& os, const stats description) {
		os << "Compasion count: " << description.comparison_count << "; " << "Copy count: " << description.copy_count << endl;
		return os;
	}
}