// 주사위 굴리기
#include <iostream>
using namespace std;

int map[20][20];
pair<int, int> curr;
int n, m;

int dice[6] = { 0, }; // 각 면의 숫자들
int direction[5] = { 6, 3, 4, 2, 5 }; // 바닥면, 동, 서, 북, 남

int getNumber(int dir);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    cin >> curr.first >> curr.second;

    int k;
    cin >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;

        int ans = getNumber(tmp);
        if (ans == -1)
            continue;
        else
            cout << ans << "\n";
    }

    return 0;
}

int getNumber(int dir) {
    pair<int, int> move[] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
    pair<int, int> next;
    // 다음 위치를 확인한다
    switch (dir) {
    case 1:
        next.first = curr.first + move[0].first;
        next.second = curr.second + move[0].second;
        break;
    case 2:
        next.first = curr.first + move[1].first;
        next.second = curr.second + move[1].second;
        break;
    case 3:
        next.first = curr.first + move[2].first;
        next.second = curr.second + move[2].second;
        break;
    case 4:
        next.first = curr.first + move[3].first;
        next.second = curr.second + move[3].second;
        break;
    }

    if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m)
        return -1;


    curr = next;
    int upper = 7 - direction[0]; // 주사위를 굴리기 전의 윗면

    // parameter로 넘겨받은 dir에 따라 direction을 수정하는 과정
    if (dir == 1) {
        direction[2] = direction[0];
        direction[0] = direction[1];
        direction[1] = upper;
    }
    else if (dir == 2) {
        direction[1] = direction[0];
        direction[0] = direction[2];
        direction[2] = upper;
    }
    else if (dir == 3) {
        direction[4] = direction[0];
        direction[0] = direction[3];
        direction[3] = upper;
    }
    else if (dir == 4) {
        direction[3] = direction[0];
        direction[0] = direction[4];
        direction[4] = upper;
    }

    // 바닥면의 수에 따라, 수를 복사하는 과정
    if (map[curr.first][curr.second] != 0) {
        dice[direction[0] - 1] = map[curr.first][curr.second];
        map[curr.first][curr.second] = 0;
    }
    else {
        map[curr.first][curr.second] = dice[direction[0] - 1];
    }
    
    
    return dice[5 - (direction[0] - 1)];
}