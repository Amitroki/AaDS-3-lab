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
			return *this;
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
	stats quick_sort(std::vector<T>& arr) {
		vector<std::pair<int, int>> stack;
		stack.push_back(std::make_pair(0, arr.size() - 1));
		stats stats;
		stats.comparison_count = 0;
		stats.copy_count = 0;
		while (!stack.empty()) {
			pair<int, int> curr = stack.back();
			stack.pop_back();
			int low = curr.first;
			int high = curr.second;
			while (low < high) {
				int pivot = arr[(low + high) / 2];
				int i = low;
				int j = high;
				while (i <= j) {
					while (arr[i] < pivot) {
						i++;
						stats.comparison_count++;
					}
					while (arr[j] > pivot) {
						j--;
						stats.comparison_count++;
					}
					if (i <= j) {
						swap(arr[i], arr[j], stats);
						i++;
						j--;
					}
				}
				if (j - low < high - i) {
					if (low < j)
						stack.push_back(make_pair(low, j));
					low = i;
				}
				else {
					if (i < high)
						stack.push_back(make_pair(i, high));
					high = j;
				}
			}
		}
		return stats;
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
			std::vector<int> test = random_seed(-1000, 1000, length_vector, i + 1);
			cout << "iteration: " << i << endl;
			switch (sort) {
			case 1:
				stat += bubble_sort(test);
				break;
			case 2:
				stat += quick_sort(test);
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
			cout << "len: " << i * 1000 << endl;
			stat.push_back(create_random_vector(i * 1000, 100, sort_choice));
		}
		cout << "len: " << 25000 << endl;
		stat.push_back(create_random_vector(25000, 100, sort_choice));
		cout << "len: " << 50000 << endl;
		stat.push_back(create_random_vector(50000, 100, sort_choice));
		cout << "len: " << 100000 << endl;
		stat.push_back(create_random_vector(100000, 100, sort_choice));
		return stat;
	}
	vector<stats> create_hundred_ordered_vectors(int sort_choice) {
		vector<stats> stat;
		for (int i = 1; i < 11; i++) {
			cout << "len: " << i * 1000 << endl;
			vector<int> a = ordered_vector(i * 1000);
			switch (sort_choice) {
			case 1:
				stat.push_back(bubble_sort(a));
				break;
			case 2:
				stat.push_back(quick_sort(a));
				break;
			case 3:
				stat.push_back(pyramid_sort(a));
				break;
			}
		}
		cout << "len: " << 25000 << endl;
		vector<int> a = ordered_vector(25000);
		switch (sort_choice) {
		case 1:
			stat.push_back(bubble_sort(a));
			break;
		case 2:
			stat.push_back(quick_sort(a));
			break;
		case 3:
			stat.push_back(pyramid_sort(a));
			break;
		}
		cout << "len: " << 50000 << endl;
		vector<int> b = ordered_vector(50000);
		switch (sort_choice) {
		case 1:
			stat.push_back(bubble_sort(b));
			break;
		case 2:
			stat.push_back(quick_sort(b));
			break;
		case 3:
			stat.push_back(pyramid_sort(b));
			break;
		}
		cout << "len: " << 100000 << endl;
		vector<int> c = ordered_vector(100000);
		switch (sort_choice) {
		case 1:
			stat.push_back(bubble_sort(c));
			break;
		case 2:
			stat.push_back(quick_sort(c));
			break;
		case 3:
			stat.push_back(pyramid_sort(c));
			break;
		}
		return stat;
	}
	vector<stats> create_hundred_reversed_ordered_vectors(int sort_choice) {
		vector<stats> stat;
		for (int i = 1; i < 11; i++) {
			cout << "len: " << i * 1000 << endl;
			vector<int> a = reversed_ordered_vector(i * 1000);
			switch (sort_choice) {
			case 1:
				stat.push_back(bubble_sort(a));
				break;
			case 2:
				stat.push_back(quick_sort(a));
				break;
			case 3:
				stat.push_back(pyramid_sort(a));
				break;
			}
		}
		cout << "len: " << 25000 << endl;
		vector<int> a = reversed_ordered_vector(25000);
		switch (sort_choice) {
		case 1:
			stat.push_back(bubble_sort(a));
			break;
		case 2:
			stat.push_back(quick_sort(a));
			break;
		case 3:
			stat.push_back(pyramid_sort(a));
			break;
		}
		cout << "len: " << 50000 << endl;
		vector<int> b = reversed_ordered_vector(50000);
		switch (sort_choice) {
		case 1:
			stat.push_back(bubble_sort(b));
			break;
		case 2:
			stat.push_back(quick_sort(b));
			break;
		case 3:
			stat.push_back(pyramid_sort(b));
			break;
		}
		cout << "len: " << 100000 << endl;
		vector<int> c = reversed_ordered_vector(100000);
		switch (sort_choice) {
		case 1:
			stat.push_back(bubble_sort(c));
			break;
		case 2:
			stat.push_back(quick_sort(c));
			break;
		case 3:
			stat.push_back(pyramid_sort(c));
			break;
		}
		return stat;
	}
	void write_to_file(vector<stats> stat, string name) {
		ofstream out;
		string path = "C:/Users/Alex/Desktop/AaDS/lab_3/";
		out.open(path.append(name));
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