// k번째 최단경로
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adlist[1'001];
priority_queue<int> h[1'001];

void dijkstra(int k){
    // 각 지점에서의 priority_queue를 만들어놓고, 그 지점까지 이동하는 이동거리를 추가합니다.
    // h에 k개의 이동경로가 들어갔을 때, 그 지점까지는 k번째 최단경로가 존재함을 의미합니다.
    priority_queue<pair<int, int>> pq;
    pq.push({-0, 1});
    h[1].push(0);

    while(!pq.empty()){
        int now = pq.top().second, dist = -pq.top().first;
        pq.pop();

        for(pair<int, int> i : adlist[now]){ // h에 어떻게 넣어야할지 판단하면서 반복문을 진행합니다.
        // 시간초과가 나지 않습니다.
            int next = i.first, nextDist = dist + i.second;

            if(h[next].size() < k){
                h[next].push(nextDist);

                pq.push({-nextDist, next});
            }
            else if(h[next].top() > nextDist){ // size가 k이고, top이 nextDist보다 크면 k번째 최단경로가 바뀝니다.
                h[next].pop();
                h[next].push(nextDist);

                pq.push({-nextDist, next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adlist[a].push_back({b, c});
    }

    dijkstra(k);

    for(int i = 1; i <= n; i++){
        if(h[i].size() < k) cout << "-1\n";
        else cout << h[i].top() << "\n";
    }

    return 0;
}

/* 아래 함수로 해도 똑같은 결과를 얻을 수 있지만, 일단 pq에 넣어놓고 그 뒤에 판단합니다.
그래서 시간초과가 났습니다.
void dijkstra(int k){
    priority_queue<pair<int, int>> pq;
    pq.push({-0, 1});

    while(!pq.empty()){
        int to = pq.top().second, dist = -pq.top().first;
        pq.pop();

        if(h[to].size() < k) h[to].push(dist);
        else if(h[to].size() >= k){
            h[to].push(dist);
            h[to].pop();
        }

        for(pair<int, int> i : adlist[to]){
            int next = i.first, nextDist = dist + i.second;
            if(h[next].size() < k) pq.push({-nextDist, next});
            else if(h[next].top() > nextDist) pq.push({-nextDist, next});
        }
    }
} */