/*
546B. Soldier and Badges

대령은 n 개의 배지가 있다. 그는 n 명의 병사들에게 배지를 하나씩 주고 싶다. 각각의 배지는 그것의 주인이 도달한 수준을 보여주는 coolness factor 를 가진다.(?) coolness factor 는 동전 하나의 비용으로 증가될 수 있다.

모든 병사 쌍 중에 한 명은 반드시 다른 병사보다 높은 factor 를 가져야 한다. factor 의 정확한 값은 중요하지 않고 다른 factor 를 가지기만 하면 된다.

대령은 처음에 어떤 병사가 어떤 배지를 받을지 알고 있지만 문제가 있다. 배지 중 일부는 같은 factor 를 가질 수 있다. 모든 배지들이 다른 coolness factor 를 가지기 위해 얼마나 많은 돈이 필요한지 계산해 그를 도와라.
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  // sort
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) min = j;
    }

    if (min != i) {
      int t = arr[i];
      arr[i] = arr[min];
      arr[min] = t;
    }
  }

  int pre = arr[0], sum = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] <= pre) {
      sum += pre + 1 - arr[i];
      arr[i] = pre + 1;
    }

    pre = arr[i];
  }

  cout << sum << endl;
	return 0;
}
