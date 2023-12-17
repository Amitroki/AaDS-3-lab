#include <gtest/gtest.h>
#include <sorting.cc>

using namespace algorithm;
using namespace std;

TEST(Sorting, Bubble1) {
	vector<int> a{31, 2, 30, 18, 34, 17, 30, 9, 30, 11, 4, 14, 29, 5, 21, 15, 17, 35, 37, 26, 38, 30, 40, 17, 29, 21, 7, 19, 38, 16};
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Bubble2) {
	vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Bubble3) {
	vector<double> a{31.1, 15.3, 2, 30, 18, 34, 17, 30, 9, 30, 11.1, 4, 14, 29, 5, 21.4, 15, 17, 35, 37, 26.1, 38, 30, 40, 17, 29.2, 21, 7, 19, 38, 16};
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Quick1) {
	vector<int> a{31, 2, 30, 18, 34, 17, 30, 9, 30, 11, 4, 14, 29, 5, 21, 15, 17, 35, 37, 26, 38, 30, 40, 17, 29, 21, 7, 19, 38, 16};
	stats b = quick_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Quick2) {
	vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	stats b = quick_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Quick3) {
	vector<double> a{31.1, 2, 30, 18, 34, 17, 30, 9, 30, 11.1, 4, 14, 29, 5, 21.4, 15, 17, 35, 37, 26.1, 38, 30, 40, 17, 29.2, 21, 7, 19, 38, 16};
	stats b = quick_sort(a, 0, a.size() - 1);
	cout << a;
	cout << b;
}
TEST(Sorting, Pyramid1) {
	vector<int> a{31, 2, 30, 18, 34, 17, 30, 9, 30, 11, 4, 14, 29, 5, 21, 15, 17, 35, 37, 26, 38, 30, 40, 17, 29, 21, 7, 19, 38, 16};
	stats b = pyramid_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, Pyramid2) {
	vector<double> a{31.1, 2, 30, 18, 34, 17, 30, 9, 30, 11.1, 4, 14, 29, 5, 21.4, 15, 17, 35, 37, 26.1, 38, 30, 40, 17, 29.2, 21, 7, 19, 38, 16};
	stats b = pyramid_sort(a);
	cout << a;
	cout << b;
}
TEST(Sorting, StringBubble) {
	vector<string> a{"CBA", "CAB", "A"};
	stats b = bubble_sort(a);
	cout << a;
	cout << b;
}
TEST(Vector, CreateRandomVector) {
	for (int i = 0; i < 10; i++) {
		vector<int> a = random_seed(-100, 100, 100, i);
		stats b = bubble_sort(a);
		cout << a;
		cout << b;
	}
}
TEST(Vector, Ordered) {
	vector<int> a = ordered_vector(100);
	cout << a;
}
TEST(Vector, ReversedOrdered) {
	vector<int> a = reversed_ordered_vector(100);
	cout << a;
}
TEST(Sorting, MyClass1) {
	Dorm a(100.1, 3.4);
	Dorm b(200.5, 7.8);
	vector<Dorm> c;
	c.push_back(a);
	c.push_back(b);
	cout << c;
}
TEST(Sorting, MyClass2) {
	Dorm a(100.1, 20);
	Dorm b(100.5, 7.8);
	vector<Dorm> c;
	c.push_back(a);
	c.push_back(b);
	stats d = pyramid_sort(c);
	cout << c;
}