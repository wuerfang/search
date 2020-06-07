#include<iostream>
#include "Sequential_Ordered_Search.h"

int main() {
	std::vector<int> v1 = { 2,4,3,8,1,5,9 };
	std::vector<int> v2 = { 1,2,3,4,5,8,9 };
	int result1, result2, result3, result4;
	result1 = Sequential_search(v1, 3);
	std::cout << result1 << std::endl;
	int key = 8;
	result2 = Binary_search(v2, key);
	result3 = Interpolation_search(v2, key);
	result4 = Fibonacci_search(v2, key);
	std::cout << result2 << " " << result3 << " " << result4 << std::endl;
	return 0;
}