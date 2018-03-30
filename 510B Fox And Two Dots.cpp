/*
B. Fox And Tow Dots

여우 Ciel 은 "Tow Dots" 라고 불리는 모바일 퍼즐 게임을 하고있다.
기본 레벨들은 n x m 크기의 판에서 진행된다.

각 셀은 같은 색의 점을 포함한다. 우리는 다른 색을 표현하기 위해 다른 라틴 대문자를 사용할 것이다.

이 게임의 열쇠는 같은 색의 점들을 포함하는 원을 찾는 것이다.
예를 들어 그림에서 원을 만드는 4 개의 파란 점을 볼 수 있다.
공식적으로 우리는 d1, d2, ..., dk 의 아래 조건을 만족하는 연속되는 점을 원이라 부른다.

1. k 개의 점들은 모두 다르다. : 만약 i != j 라면 di != dj 이다.
2. k 는 최소 4 이다.
3. 모든 점들은 같은 색이다.
4. 1 <= i <= k - 1 인 모든 di 와 d(i + 1) 은 인접한다. 또한 dk 와 d1 또한 인접한다.
x, y 셀들은 모서리를 공유하면 인접한다.

원이 존재하는지 검사해라.
*/
#include <iostream>
using namespace std;

int n, m;

bool dfs(char** arr, int x, int y, char color, int pre) {
  char c = arr[x][y];
  if (abs(c) != color) return false;
  if (-c == color) return true;

  arr[x][y] = -color;

  if (pre != 2 && 0 < x && dfs(arr, x - 1, y, color, 1)) return true;
  if (pre != 1 && x < n - 1 && dfs(arr, x + 1, y, color, 2)) return true;
  if (pre != 4 && 0 < y && dfs(arr, x, y - 1, color, 3)) return true;
  if (pre != 3 && y < m - 1 && dfs(arr, x, y + 1, color, 4)) return true;

  arr[x][y] = 0;
  return false;
}

int main() {
  cin >> n >> m;

  char** arr = new char*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new char[m];
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] > 0 && dfs(arr, i, j, arr[i][j], 0)) {
        cout << "Yes";
        return 0;
      }
    }
  }

  cout << "No";
  return 0;
}
