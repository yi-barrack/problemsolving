#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m; cin >> m;
	int arr[4] = {0,1,2,3};  //인덱스는 컵의 번호, 배열의 원소는 컵의 위치
	
	for (int i = 0; i < m; i++) {
		int first, second;
		cin >> first >> second;
		swap(arr[first], arr[second]); //인덱스(컵의 번호)의 값(위치)를 바꿔준다
		
	}

	int i = 1;
	while (true) {
		if (arr[i] == 1) { //컵의 위치가 1인 컵이 공이 들어있는 컵이다.
			cout << i << '\n';
			break;
		}
		i++;
	}
	
	return 0;
}