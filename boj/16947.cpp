// 서울 지하철 2호선
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector<bool> visit;
vector<bool> cycleStation;

// 사이클이 존재하는지 확인하는 함수. DFS로 구현했습니다.
void checkCycle(int curr, int bef){
    visit[curr] = true;

    for(int next : v[curr]){
        if(visit[next] == false) checkCycle(next, curr);

        if(visit[next] == true && next != bef) cycleStation[next] = true;
    }

    visit[curr] = false;
}

// 사이클에 존재하지 않는다면, 사이클에 있는 지하철역까지 얼마나 먼지를 반환하는 함수
// BFS로 구현하면서, cycleStation[curr] == true 일 때 그 길이를 리턴합니다.
int getLength(int start, int cnt){
    queue<pair<int, int>> q;
    q.push({start, cnt});
    visit[start] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int ans = q.front().second;
        q.pop();

        if(cycleStation[curr]) return ans;

        for(int next : v[curr]){
            if(!visit[next]){
                visit[next] = true;
                q.push({next, ans + 1});
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    v = vector<vector<int>>(n + 1, vector<int>());
    visit = vector<bool>(n + 1, false);
    cycleStation = vector<bool>(n + 1, false);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) checkCycle(i, 0);

    for(int i = 1; i <= n; i++){
        if(cycleStation[i]) cout << "0 ";
        else {
            for(int i = 1; i <= n; i++) visit[i] = false;
            cout << getLength(i, 0) <<" ";
        }
    }

    return 0;
}