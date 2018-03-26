/*
B. A and B and Compilation Errors

A 와 B 는 혼자서 프로그래밍 대회를 준비하고 있다.

B 는 자기 코드를 디버깅하는 것을 좋아한다. 그러나 그가 답을 실행하고 디버깅을 할 때 먼저 코드를 컴파일해야 한다.

처음에 컴파일러는 n 개의 컴파일 에러를 보여주고 각각의 에러는 양수로 표현된다. 약간의 노력 끝에 B 는 몇가지 실수를 수정하고 또 다른 실수 하나를 고친다.

그러나 B 는 그가 2 개의 에러를 고쳤다고 확신했음에도 불구하고 그는 어떤 컴파일 에러가 사라졌는지 정확히 이해하지 못한다. B 가 사용하는 언어의 컴파일러는 매번 새로운 순서로 에러를 보여주기 때문이다. B 는 많은 다른 프로그래밍 언어들과 달리 그의 프로그래밍 언어의 컴파일러 에러들은 다른 것에 의존하지 않는다고 확신한다.(?) 즉 만약 하나의 에러를 고치면 다른 에러의 집합은 변하지 않는다.

B 가 그가 고친 두개의 에러가 정확히 뭔지 찾을 수 있도록 도와주겠는가?
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < 2; i++) {
		int len = n - 1;
		int* arr2 = new int[len];
		for (int j = 0; j < len; j++) cin >> arr2[j];
		sort(arr2, arr2 + len);

		for (int j = 0; j < len; j++) {
			if (arr[j] != arr2[j] || j == len - 1) {
				if (arr[j] == arr2[j]) j++;
				cout << arr[j] << endl;
				arr = arr2;
				n = len;
				break;
			}
		}
	}
	return 0;
}
