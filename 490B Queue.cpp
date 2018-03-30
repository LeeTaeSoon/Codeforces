/*
B. Queue

점심 시간 동안 Berland State 대학의 모든 n 명의 학생들이 식당에 줄서있었다.
그러나 식당도 점심 시간을 가져 잠시 영업을 중단했다.

서빙되지 않는 줄에 서 있는 것은 매우 지루하다! 그래서 각 학생들은 바로 앞에 서있는 학생과 바로 뒤에 서있는 학생 ID 번호를 썼다.
만약 앞이나 뒤에 아무도 없다면 (맨 앞이나 맨 뒤에 서있는 경우) 0 번을 쓴다. (Berland State 대학의 학생 ID 는 1 번부터 시작한다.)

그 후, 모든 학생들이 자신의 볼일을 보러 갔다. 그들이 돌아왔을 때, 그들이 다시 줄을 서는 것은 쉬운 일이 아님을 알았다.

학생들이 줄에서 이웃한 학생 ID 를 적은 것을 이용해 줄을 다시 서는 것을 도와라.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  int* aarr = new int[n];
  int* barr = new int[n];
  int arr[1000000] = { 0, };
  int* result = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> aarr[i] >> barr[i];
    arr[aarr[i]] = barr[i];

    if (aarr[i] == 0) result[1] = barr[i];
  }

  sort(aarr, aarr + n);
  sort(barr, barr + n);
  int index1 = 0, index2 = 0;
  while (index1 < n && index2 < n) {
    if (aarr[index1] == barr[index2]) {
      index1++; index2++;
    } else index2++;
  }
  result[0] = aarr[index1];

  index1 = result[0]; index2 = result[1];
  for (int i = 2; i < n; i += 2) {
    result[i] = arr[index1];
    index1 = result[i];
    if (i + 1 < n) {
      result[i + 1] = arr[index2];
      index2 = result[i + 1];
    }
  }

  for (int i = 0; i < n; i++) cout << result[i] << " ";
  return 0;
}
