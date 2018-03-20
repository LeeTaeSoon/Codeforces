/*
B. Fly, freebies, fly!

누구나 freebie 를 좋아한다. 특히 학생들은.

시험을 앞둔 학생이 밤에 창문을 열고 자신의 record-book을 펼치고 크게 세번 "Fly, freebie, fly!" 라고 외치면
날아온 freebie 가 다가올 시험을 통과하게 도와준다는건 잘 알려져 있다.

수리 분석 시험 전날 밤 기숙사에 사는 n 명의 학생은 주문을 외쳤다.
i 번째 학생은 ti 시간에 소원을 빌었다. ti 는 밤이 시작된 후 지난 초(sec) 이다.

freebie 는 개구쟁이에 고집스러운 숙녀로 알려져있다. 그 날 밤 freebie 는 기숙사에 오직 T 초만 다녀갔다.
그러므로 만약 두 학생의 소원의 시간이 T 보다 크면 그 중 한명은 freebie 가 찾아오지 않았다.

모든 학생들은 낙관론자들이기 때문에 그들은 freebie 가 찾아올 수 있는 학생의 최대 숫자를 알고싶다.
*/
#include <iostream>
using namespace std;

int main() {
	int n, T;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> T;

	// sort
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min]) min = j;

		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	int max = 1, sum = 1;
	for (int i = 0; i < n - 1; i++) {
		int a = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (arr[j] - a > T) break;
			else sum++;
		}
		if (max < sum) max = sum;
		sum = 1;
	}

	cout << max << endl;
	return 0;
}
