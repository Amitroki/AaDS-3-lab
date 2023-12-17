#include <iostream>
#include <sorting.cc>

using namespace std;
using namespace algorithm;

int main() {
	//vector<stats> a = create_hundred_random_vectors(1);
	//vector<stats> a = create_hundred_random_vectors(2);
	vector<stats> a = create_hundred_random_vectors(3);
	//vector<stats> a = create_hundred_ordered_vectors(1);
	//vector<stats> a = create_hundred_ordered_vectors(2);
	//vector<stats> a = create_hundred_ordered_vectors(3);
	//vector<stats> a = create_hundred_reversed_ordered_vectors(1);
	//vector<stats> a = create_hundred_reversed_ordered_vectors(2);
	//vector<stats> a = create_hundred_reversed_ordered_vectors(3);
	string name = "random_pyramid.txt";
	write_to_file(a, name);
}