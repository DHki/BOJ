//2606 - 바이러스
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adlist;
vector<bool> visit;

void DFS(int curr);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; // 컴퓨터의 수
    cin >> n;

    adlist = vector<vector<int>>(n + 1, vector<int>());
    visit = vector<bool>(n + 1, false);

    int t; // 연결된 컴퓨터의 수
    cin >> t;
    for(int i = 0; i < t; i ++){
        int from, to;
        cin >> from >> to;

        // 양방향 간선이기 때문에, 양 쪽에 push해줍니다.
        adlist[from].push_back(to);
        adlist[to].push_back(from);
    }

    // 1번 컴퓨터에서 바이러스가 걸렸을 때
    // DFS를 통해 바이러스에 걸리는 컴퓨터를 확인합니다.
    DFS(1);

    // visit 중에서 true인 개수가 바이러스에 걸린 컴퓨터의 개수입니다.
    // "1번 컴퓨터를 통해" 바이러스에 걸린 컴퓨터의 개수이기에, 1을 빼줍니다.
    int ans = count(visit.begin(), visit.end(), true) - 1;
    cout << ans << "\n";

    return 0;
}

void DFS(int curr){
    visit[curr] = true;

    // 자신과 연결된 컴퓨터 중에서 visit[next] = false라면
    // DFS를 재귀적으로 호출합니다.
    for(int next : adlist[curr]){
        if(!visit[next]) DFS(next);
    }
}