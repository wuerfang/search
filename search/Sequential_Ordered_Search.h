
#include<vector>

/***********************˳�����*******************************/
int Sequential_search(std::vector<int> &v, int key) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == key)
			return i;
	}
	return -1;
}

/***********************�������*******************************/
//���ֲ���
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

//��ֵ����
int Interpolation_search(std::vector<int> &v, int key) {
	int low, high, mid;
	low = 0;
	high = v.size() - 1;
	while (low <= high) {
		mid = low + (key - v[low]) / (v[high] - v[low])*(high - low);//����ֲ��ҵ�������midȡ����ͬ
		if (v[mid] < key)
			low = mid + 1;
		else if (v[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

//쳲���������
void Fibonacci(std::vector<int> &F) {	//����쳲���������
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < F.size(); ++i) {
		F[i] = F[i - 1] + F[i - 2];
	}
}
int Fibonacci_search(std::vector<int> &v, int key) {
	const int max_size = 20;		//���ڹ���쳲�����(Fibonacci)���鳤��
	std::vector<int> F(max_size);	//쳲�����(Fibonacci)����
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