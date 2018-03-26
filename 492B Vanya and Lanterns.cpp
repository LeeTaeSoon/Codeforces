/*
B. Vanya and Lanterns

Vanya 는 n 개의 랜턴들이 서있는 길이 l 의 일직선 도로를 따라 늦은 밤 걷고 있다. 길의 시작이 포인트 0, 끝이 포인트 l 에 해당하는 좌표축 시스템을 생각해보자. i 번째 랜턴은 포인트 ai 에 있다. 랜턴은 최대 d 만큼의 거리를 비출 수 있고 d 는 어떤 양수이다.

Vanya 는 궁금하다 : 랜턴이 전체 길을 밝힐 수 있도록 하는 최소 빛의 반지름 d 는 얼마인가?
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	long long _max = 2 * max(arr[0] - 0, l - arr[n - 1]);
	for (int i = 1; i < n; i++) {
		long long a = arr[i] - arr[i - 1];
		if (a > _max) _max = a;
	}

	printf("%lf", _max / (double) 2);
	return 0;
}
