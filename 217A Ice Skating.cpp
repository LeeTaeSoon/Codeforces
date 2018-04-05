/*
A. Ice Skating

Bajtek 은 아이스 스케이팅을 배우고 있다. 그는 초보자라 눈더미부터 오직 동서남북으로 다른 눈더미를 만날때까지 미끄러질 수 있다.
그는 이 과정에서 어떤 눈더미에서 다른 어떤 눈더미로 어떻게 움직여도 갈 수 없다는 것을 알았다.
그는 이제 어떤 눈더미에서 다른 어떤 눈더미로도 갈 수 있도록 추가로 몇 개의 눈더미를 쌓고 싶다.
그는 그가 만들어야하는 눈더미의 최소 갯수를 찾는 것을 당신에게 요청했다.

우리는 Bajtek 이 정수 좌표에만 눈더미를 쌓을 수 있다고 가정한다.
*/
#include <iostream>
using namespace std;

int arr[1001][1001];

void dfs(int component, int x, int y, bool direction) {
  // true : vertical, false : horizontal
  if (direction) {
    for (int i = 0; i < 1001; i++) {
      if (arr[i][y] == 0) {
        arr[i][y] = component;
        dfs(component, i, y, false);
      }
    }
  } else {
    for (int i = 0; i < 1001; i++) {
      if (arr[x][i] == 0) {
        arr[x][i] = component;
        dfs(component, x, i, true);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < 1001; i++)
    for (int j = 0; j < 1001; j++) arr[i][j] = -1;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    arr[x][y] = 0;
  }

  int component = 1;
  for (int i = 1; i < 1001; i++) {
    for (int j = 1; j < 1001; j++) {
      if (arr[i][j] == 0) {
        arr[i][j] = component;
        dfs(component, i, j, true);
        dfs(component, i, j, false);
        component++;
      }
    }
  }

  cout << component - 2;
  return 0;
}
