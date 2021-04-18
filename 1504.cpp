// 특정한 최단 경로
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int, int>> adlist[801]; //<목적지, 거리>
long dist[801]; // 특정 시점에서 목적지까지의 거리를 저장하는 배열

void dijkstra(int start){
    for(int i = 0; i <= 800; i++) dist[i] = INT_MAX; // dist를 먼저 초기화 해줍니다.
    dist[start] = 0;

    priority_queue<pair<int, int>> q; // <-거리, 목적지> : priority_queue 의 특징 이용
    for(auto e : adlist[start]) q.push({-e.second, e.first});

    while(!q.empty()){
        int distance = -q.top().first;
        int destination = q.top().second;
        q.pop();

        if(dist[destination] == INT_MAX){ // 목적지에 아직 간 적이 없다면
            dist[destination] = distance;

            for(auto e: adlist[destination]){ // 목적지의 위치에서 갈 수 있는 곳을 업데이트 해줍니다.
                int next = e.first;
                int length = -e.second - distance;

                q.push({length, next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adlist[a].push_back({b, c});
        adlist[b].push_back({a, c});
    }

    int a, b;
    cin >> a >> b;

    long ans1 = 0, ans2 = 0; // 변수 조심. int의 경우 overflow가 날 수 있음

    // ans1 : 시작지점 ~ a ~ b ~ 도착지점
    // ans2 : 시작지점 ~ b ~ a ~ 도착지점
    dijkstra(1);
    ans1 += dist[a]; ans2 += dist[b];

    dijkstra(a);
    ans1 += dist[b]; ans2 += dist[n];

    dijkstra(b);
    ans1 += dist[n]; ans2 += dist[a];

    long ans = min(ans1, ans2);
    if(ans >= INT_MAX) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}