#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[101][101]; // -1 : 뱀의 몸, 0 : 아무것도 없음, 1 : 사과
queue<pair<int, char>> chages;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
	}

	int l;
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t;
		char c;
		cin >> t >> c;

		chages.push({ t, c });
	}

	//뱀을 map 안에서 움직이게 하기 위한 과정 (필요한 변수들을 선언합니다.)
	queue<pair<int, int>> q; // 뱀의 머리가 지나간 자리
	pair<int, int> move[4] = { {0, 1} , {1, 0}, {0, -1}, {-1, 0} };
	int idx = 0;

	pair<int, int> head = { 1, 1 }, tail = { 1, 1 }; // 뱀의 머리, 꼬리의 좌표
	long long sec = 0;
	map[1][1] = -1;

	while (true) {
		sec++;
		head.first += move[idx].first; head.second += move[idx].second;
		q.push(head);

		//시뮬레이션이 끝나는 상황
		if (map[head.first][head.second] == -1) {
			cout << sec << "\n";
			break;
		}
		else if (head.first > n || head.first < 1 || head.second > n || head.second < 1) {
			cout << sec << '\n';
			break;
		}

		//끝나지 않는다면, 이어서 map과 head, tail을 확인합니다.
		else if (map[head.first][head.second] == 0) {
			map[tail.first][tail.second] = 0;
			tail = q.front();
			q.pop();

			map[head.first][head.second] = -1;
		}
		else if (map[head.first][head.second] == 1) {
			map[head.first][head.second] = -1;
		}

		//방향을 바꾸는지 확인하는 과정
		if (chages.empty())
			continue;
		if (sec == chages.front().first) {
			switch (chages.front().second)
			{
			case 'L':
				idx--;
				break;
			case 'D':
				idx++;
				break;
			}

			if (idx == -1)
				idx = 3;
			else if (idx == 4)
				idx = 0;

			chages.pop();
		}
	}
	return 0;
}