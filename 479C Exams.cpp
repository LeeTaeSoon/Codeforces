/*
C. Exams

학생 Valera 는 대학 학부생이다. 그의 장기 시험의 끝이 다가오고 그는 정확히 n 개의 시험을 통과해야 한다.
Valera 는 똑독하기 때문에 어떤 시험이든 한번에 통과할 수 있다. 게다가 그는 하루에 어떤 순서로든 여러 시험을 볼 수 있다.

일정에 따르면 학생은 i 번째 과목을 ai 날에 볼 수 있다.
그러나 Valera 는 각 선생님들과 협의했고 i 번쨰 과목의 선생님은 bi 스케줄 시간 전에 보도록 허락했다.
그러므로 Valera 는 i 번째 과목을 ai 날이나 bi 날에 볼 수 있다.
모든 선생님들은 실제 시험 날 학생기록부에 시험 성적을 기록하고 기록 날짜를 ai 로 적는다.

Valera 는 만약 기록부의 목록들이 날짜가 오름차순이 아니면 이상할 것이라고 믿는다.
그러므로 Valera 는 당신에게 도움을 요청한다.
만약 Valera 가 그의 기록부가 오름차순으로 정렬되도록 시험을 볼 때 마지막 시험을 보는 날짜가 될 수 있는 가장 작은 날을 찾아라.
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int** arr = new int*[n];
  for (int i = 0; i < n; i++) arr[i] = new int[2];
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr[i][0] = a;
    arr[i][1] = b;
  }

  // sort
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j][0] < arr[min][0] || (arr[j][0] == arr[min][0] && arr[j][1] < arr[min][1])) min = j;

		if (min != i) {
			int* temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

  int day = 0;
  for (int i = 0; i < n; i++) {
    if (day > arr[i][1]) day = arr[i][0];
    else day = arr[i][1];
  }

  cout << day << endl;
	return 0;
}
