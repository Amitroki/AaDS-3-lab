#include <gtest/gtest.h>
#include <sorting.cc>

using namespace algorithm;
using namespace std;

TEST(Sorting, Bubble1) {
	std::vector<int> a{ 1, 3, 2, 6, 7, 5, 4, 8, 10, 9 };
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Bubble2) {
	std::vector<int> a{ 31, 2, 30, 18, 34, 17, 30, 9, 30, 11, 4, 14, 29, 5, 21, 15, 17, 35, 37, 26, 38, 30, 40, 17, 29, 21, 7, 19, 38, 16 };
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}