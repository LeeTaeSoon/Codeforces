/*
A. Ring road

오늘날 교통체증을 줄이고 안전 운전을 향상시키기 위해 전세계에서 일방교통이 소개되었다.
Berland 정부는 새로운 트렌드를 따르기로 결정했다.
공식적으로 Berland 의 모든 n 개의 도시들은 원 안의 n 개의 2방향 도로들로 연결되어 있다.
즉 각 도시는 정확히 다른 두 도시와 직접 연결되어있고 각 도시에서 다른 도시로 이동할 수 있었다.
Berland 정부는 모든 n 개의 도로들에 일방교통을 소개했으나 어떤 도시에서 다른 어떤 도시로는 갈 수 없다는 것을 알았다.
이제 모든 도로들은 교통이 어느 방향으로 향하는지, 교통 방향을 바꾸는 비용을 알 수 있다.
모든 도시에서 어느 도시로든 이동할 수 있도록 도로들의 방향을 바꾸는데 정부가 필요한 최소금액이 얼마인가?
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[101][101];
  for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) arr[i][j] = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a][b] = c;
  }

  int left = 0, right = 0, leftNode = -1, rightNode = -1, pre = 1;
  for (int i = 2; i <= n; i++) {
    if (arr[1][i] > 0 || arr[i][1] > 0) {
      if (leftNode > 0) {
        if (arr[i][1] > 0) right += arr[i][1];
        rightNode = i;
        break;
      } else {
        if (arr[i][1] > 0) left += arr[i][1];
        leftNode = i;
      }
    }
  }

  while (leftNode != 1) {
    for (int i = 1; i <= n; i++) {
      if (i != pre && (arr[leftNode][i] > 0 || arr[i][leftNode] > 0)) {
        if (arr[i][leftNode] > 0) left += arr[i][leftNode];
        pre = leftNode;
        leftNode = i;
        break;
      }
    }
  }

  pre = 1;
  while (rightNode != 1) {
    for (int i = 1; i <= n; i++) {
      if (i != pre && (arr[rightNode][i] > 0 || arr[i][rightNode] > 0)) {
        if (arr[i][rightNode] > 0) right += arr[i][rightNode];
        pre = rightNode;
        rightNode = i;
        break;
      }
    }
  }

  cout << (left > right? right : left);
  return 0;
}
