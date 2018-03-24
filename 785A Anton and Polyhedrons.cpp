/*
A. Anton and Polyhedrons

Anton 이 가장 좋아하는 그림들은 정다면체들이다. 아래는 정다면체들의 5 가지 특징이다.
- 4면체. 4면체는 4개의 삼각형 면이 있다.
- 6면체. 6면체는 6 개의 정사각형 면이 있다.
- 8면체. 8면체는 8 개의 삼각형 면이 있다.
- 12면체. 12면체는 12 개의 5각형 면이 있다.
- 20면체. 20면체는 20 개의 삼각형 면이 있다.

모든 정다면체의 5가지 종류는 아래 그림과 같다.

Anton 은 n 개의 정다면체 수집품이 있다. 어느 날 그는 자신의 정다면체들이 얼마나 많은 면들을 가지고 있는지 알아보기로 했다.
Anton 이 숫자를 찾는 것을 도와라.
*/
#include <iostream>
using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s.compare("Tetrahedron") == 0) sum += 4;
    else if (s.compare("Cube") == 0) sum += 6;
    else if (s.compare("Octahedron") == 0) sum += 8;
    else if (s.compare("Dodecahedron") == 0) sum += 12;
    else sum += 20;
  }

  cout << sum << endl;
  return 0;
}
