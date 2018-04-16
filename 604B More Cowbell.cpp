/*
B. More Cowbell

Kevin Sun 은 그의 소중한 n 개의 카우벨 컬렉션을 Naperthrill 에서 옥수수 대신 잔디가 있는 Exeter 로 옮기고 싶어한다.
옮기기 전에 그는 그의 카우벨들을 고정된 크기의 k 박스들로 짐을 싸야한다.
운송 중에 그의 컬렉션이 안전하게 유지되기 위해서 그는 한 박스에 2 개 보다 많은 카우벨을 넣지 않는다.
비용을 최소화하고 싶은 Kevin 의 소망때문에 그는 그가 모든 컬렉션을 싸는데 필요한 가장 작은 크기의 박스에 대해 궁금증을 가졌다.

Kevin 은 꼼꼼한 카우벨 수집가이고 그의 i 번째 카우벨의 크기인 정수 Si 를 알고있다.
사실 그는 그의 카우벨들을 크기에 따라 정렬했다. 따라서 i 가 1 보다 클 때 s(i-1) <= si 이다.
또한 포장 전문가로서 Kevin 은 1 개나 2 개의 카우벨을 s 크기의 박스에 초과하지 않고 정확하게 맞춘다.
이 정보들이 주어졌을 때, Kevin 이 s 크기의 박스 k 개에 그의 모든 카우벨을 넣을 수 있는 가장 작은 크기 s 를 구하는 것을 도와라.
*/
#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  long long* arr = new long long[n];
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[i] = a;
  }

  int twoCount = n - k;
  long long size = arr[n - 1];

  for (int i = twoCount - 1; i >= 0; i--) {
    if (arr[i] + arr[twoCount + (twoCount - i - 1)] > size) size = arr[i] + arr[twoCount + (twoCount - i - 1)];
  }

  cout << size;
  return 0;
}
