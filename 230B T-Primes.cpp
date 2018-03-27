/*
B. T-primes

우리는 소수가 정확히 두개의 다른 양수 약수를 가진다는 것을 알고 있다. 비슷하게 우리는 정확하게 3 개의 다른 양수 약수를 가지는 양수 t 를 T-prime 이라고 부른다.

당신은 n 개의 양수 정수를 가진 배열을 받았다. 그것들이 각각 T-prime 인지 아닌지 구하라.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	double* query = new double[n];
	for (int i = 0; i < n; i++) cin >> query[i];

	bool arr[1000001];
	for (int i = 0; i < 1000001; i++) arr[i] = true;
	arr[0] = arr[1] = false;

	for (int i = 2; i < 1000001; i++) {
		if (arr[i])
			for (int j = 2 * i; j < 1000001; j += i) arr[j] = false;
	}

	for (int i = 0; i < n; i++) {
		double a = query[i];

		long long sq = (long long) sqrt(a);
		if (sq * sq == a && arr[sq]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
