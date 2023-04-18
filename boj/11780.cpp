#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long answer_1[105][105] = { 0, }; // 경로의 최소시간을 저장하는 배열
int arr[105][105] = { 0, }; // 경로의 경유지를 저장하는 배열

vector<int> answer_2; // 경유지를 저장하는 벡터
int n, m; // n : 도시의 개수, m : 버스의 개수
void floyd()
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
                if (i == j) continue;
				if (answer_1[i][j] > answer_1[i][k] + answer_1[k][j]) {
					answer_1[i][j] = answer_1[i][k] + answer_1[k][j];
					arr[i][j] = k; // i ~ j 를 이동할 때 k를 통해 가면 더 빠릅니다.
				}
			}
		}
	}
}

void findStop(int start, int end)
{
	if (arr[start][end] == 0)
		return;
	else { // 재귀함수로 구현했습니다.
    // floyd에서 갱신한 경유지 k를 기준으로 앞의 경유지들을 저장하고, 뒤의 경유지들을 저장합니다.
		findStop(start, arr[start][end]);
		answer_2.push_back(arr[start][end]);
		findStop(arr[start][end], end);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			answer_1[i][j] = INT_MAX;
	}

	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		if (answer_1[from][to] > weight)
			answer_1[from][to] = weight;
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
            // INT_MAX일 때에는 0을 출력합니다.
            if(answer_1[i][j] == INT_MAX) cout << "0 ";
			else cout << answer_1[i][j] << " ";
        }
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
            // INT_MAX일 때에는 0을 출력합니다.
			if(answer_1[i][j] == INT_MAX) cout << "0\n";
            else{
                answer_2.clear();
                findStop(i, j);
                cout << 2 + answer_2.size() << " " << i << " ";
                for (int i = 0; i < answer_2.size(); i++) {
                    cout << answer_2[i] << " ";
                }

                cout << j << " \n";
            }
		}
	}

	return 0;
}