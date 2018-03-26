/*
B. Anton and Digits

Anton 은 최근 그의 방에서 숫자가 있는 박스를 찾았다. 거긴엔 2 k2 개, 3 k3 개, 5 k5 개, 6 k6 개 가 있다.

Anton 이 가장 좋아하는 숫자는 32 와 256 이다. 그는 그가 가진 숫자들로 이 숫자들을 조합하기로 결심했다. 그는 이 숫자들의 합을 최대가 되게 만들고 싶다. 이 작업을 도와라.

각각의 숫자는 한번이상 쓰일 수 없다. 조합된 숫자는 2 k2개, 3 k3개보다 더 많이 사용될 수 없고 사용되지 않은 숫자는 합에 포함되지 않는다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;

	int c256 = min(k2, min(k5, k6));
	k2 -= c256;
	int c32 = min(k2, k3);

	cout << 256 * c256 + 32 * c32 << endl;
	return 0;
}
