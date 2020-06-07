
#include<vector>

/***********************顺序查找*******************************/
int Sequential_search(std::vector<int> &v, int key) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == key)
			return i;
	}
	return -1;
}

/***********************有序查找*******************************/
//二分查找
int Binary_search(std::vector<int> &v, int key) {
	int low, high, mid;
	low = 0;
	high = v.size() - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (v[mid] < key)
			low = mid + 1;
		else if (v[mid] > key)
			high = mid - 1;
		else
			return mid;			
	}
	return -1;
}

//插值查找
int Interpolation_search(std::vector<int> &v, int key) {
	int low, high, mid;
	low = 0;
	high = v.size() - 1;
	while (low <= high) {
		mid = low + (key - v[low]) / (v[high] - v[low])*(high - low);//与二分查找的区别是mid取法不同
		if (v[mid] < key)
			low = mid + 1;
		else if (v[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

//斐波那契查找
void Fibonacci(std::vector<int> &F) {	//构造斐波那契数组
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < F.size(); ++i) {
		F[i] = F[i - 1] + F[i - 2];
	}
}
int Fibonacci_search(std::vector<int> &v, int key) {
	const int max_size = 20;		//用于构造斐波那契(Fibonacci)数组长度
	std::vector<int> F(max_size);	//斐波那契(Fibonacci)数组
	Fibonacci(F);
	int low, high, mid, k;
	low = 0;
	high = v.size() - 1;
	k = 0;
	int n = v.size();
	while (n > (F[k] - 1)) {
		++k;
	}	
	std::vector<int> temp(F[k] - 1);
	for (int i = 0; i < v.size(); ++i) {
		temp[i] = v[i];
	}
	for (int i = v.size(); i < F[k] - 1; ++i) {
		temp[i] = v[v.size() - 1];
	}
	while (low <= high) {
		mid = low + F[k - 1] - 1;
		if (temp[mid] < key) {
			low = mid + 1;
			k -= 2;
		}
		else if (temp[mid] > key) {
			high = mid - 1;
			k -= 1;
		}
		else {
			if (mid < v.size())
				return mid;
			else
				return v.size() - 1;
		}			
	}

	return -1;
}