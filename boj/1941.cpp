#include <iostream>
#include <queue>
using namespace std;

char map[6][6];
bool visit[6][6];
long ans = 0;

bool isMoreThan4(){ // 고른 7명 중에 S가 4명보다 같거나 큰 경우를 가려내기 위한 함수
    int s = 0, y = 0;
    for(int i = 0; i< 5; i++){
        for(int j = 0; j < 5; j++){
            if(visit[i][j]){
                if(map[i][j] == 'S')s++;
                else y++;
            }
        }
    }

    if(s >= 4) return true;
    return false;
}

bool isAdjacency(){ // 고른 7명이 모두 인접하게 위치하는지 확인하는 함수
    // cnt가 인접한 인원의 수를 나타낸다
    int cnt = 0;

    queue<pair<int, int>> q;
    bool visit_tmp[5][5] = {{false, }, }; // queue에 넣기 전에 확인한 학생인지 구분하기 위해서 
    for(int i = 0; i < 5; i++){
        bool tmp = false;
        for(int j = 0; j < 5; j++){
            if(visit[i][j]){
                q.push({i, j});
                tmp = true; visit_tmp[i][j] = true;
                cnt++;
                break;
            }
        }
        if(tmp) break;
    }

    int ii[4] = {-1, 1, 0, 0};
    int jj[4] = {0, 0, 1, -1};
    while(!q.empty()){
        if(cnt == 7) break;

        pair<int, int> curr = q.front();
        q.pop();

        for(int i = 0; i< 4; i++){
            int ni = curr.first + ii[i], nj = curr.second + jj[i];
            if(ni < 0 || ni >= 5 || nj < 0 || nj >= 5) continue;

            if(visit[ni][nj] && !visit_tmp[ni][nj]){
                // 인접함과 동시에 아직 확인하지 않은 학생이라면
                cnt++; visit_tmp[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    if(cnt == 7) return true;
    return false;
}

void dfs(int idx, int cnt){
    if(cnt == 7){
        if(isMoreThan4()){
            if(isAdjacency()){
                ans++;
            }
        }
        return;
    }

    for(int k = idx; k < 25; k++){ // 7명의 조합을 만들기 위해 25명을 순서대로 돌면서 선택
        int i = k / 5, j = k % 5;

        if(visit[i][j]) continue;
        visit[i][j] = true;
        dfs(k, cnt + 1);
        visit[i][j] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> map[i][j];
        }
    }

    dfs(0, 0);
    cout << ans << "\n";

    return 0;
}