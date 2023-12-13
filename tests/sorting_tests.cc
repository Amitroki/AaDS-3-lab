#include <gtest/gtest.h>
#include <sorting.cc>

using namespace algorithm;
using namespace std;

TEST(Sorting, Bubble1) {
	std::vector<int> a{ 31, 2, 30, 18, 34, 17, 30, 9, 30, 11, 4, 14, 29, 5, 21, 15, 17, 35, 37, 26, 38, 30, 40, 17, 29, 21, 7, 19, 38, 16 };
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Bubble2) {
	std::vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Bubble3) {
	std::vector<double> a{ 31.1, 15.3, 2, 30, 18, 34, 17, 30, 9, 30, 11.1, 4, 14, 29, 5, 21.4, 15, 17, 35, 37, 26.1, 38, 30, 40, 17, 29.2, 21, 7, 19, 38, 16 };
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Quick1) {
	std::vector<int> a{ 31, 2, 30, 18, 34, 17, 30, 9, 30, 11, 4, 14, 29, 5, 21, 15, 17, 35, 37, 26, 38, 30, 40, 17, 29, 21, 7, 19, 38, 16 };
	stats b = quick_sort(a, 0, a.size() - 1);
	cout << a;
	cout << b;
}
TEST(Sorting, Quick2) {
	std::vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	stats b = quick_sort(a, 0, a.size() - 1);
	cout << a;
	cout << b;
}
TEST(Sorting, Quick3) {
	std::vector<double> a{ 31.1, 2, 30, 18, 34, 17, 30, 9, 30, 11.1, 4, 14, 29, 5, 21.4, 15, 17, 35, 37, 26.1, 38, 30, 40, 17, 29.2, 21, 7, 19, 38, 16 };
	stats b = quick_sort(a, 0, a.size() - 1);
	cout << a;
	cout << b;
}
TEST(Sorting, Pyramid1) {
	std::vector<int> a{ 31, 2, 30, 18, 34, 17, 30, 9, 30, 11, 4, 14, 29, 5, 21, 15, 17, 35, 37, 26, 38, 30, 40, 17, 29, 21, 7, 19, 38, 16 };
	stats b = pyramid_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Pyramid2) {
	std::vector<double> a{ 31.1, 2, 30, 18, 34, 17, 30, 9, 30, 11.1, 4, 14, 29, 5, 21.4, 15, 17, 35, 37, 26.1, 38, 30, 40, 17, 29.2, 21, 7, 19, 38, 16 };
	stats b = pyramid_sort(a);
	cout << a;
	cout << b;
}