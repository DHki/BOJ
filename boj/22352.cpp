#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[30][30];
int newMap[30][30];

int ii[4] = {-1, 1, 0, 0};
int jj[4] = {0, 0, 1, -1};

bool visit[30][30];

bool bfs(int i, int j){

    queue<pair<int, int>> q;
    q.push({i, j});
    bool v[30][30] = {{false, }, };
    visit[i][j] = v[i][j] = true;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> tmp = {curr.first + ii[i], curr.second + jj[i]};
            if (tmp.first < 0 || tmp.first >= n || tmp.second < 0 || tmp.second >= m)
                continue;

            if ((map[curr.first][curr.second] == map[tmp.first][tmp.second]) && !visit[tmp.first][tmp.second]){
                q.push(tmp);
                visit[tmp.first][tmp.second] = v[tmp.first][tmp.second] = true;
            }
        }
    }

    int flag = newMap[i][j];
    for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            if(v[a][b] && (newMap[a][b] != flag)) return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> map[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> newMap[i][j];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((map[i][j] != newMap[i][j]) && !visit[i][j]){
                if(bfs(i, j)) cnt++;
                else cnt = 999;
            }
        }
    }

    if (cnt >= 2) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}