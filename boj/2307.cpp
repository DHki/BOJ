#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges[n + 1];
    for(int i = 0; i < m; i++){ // 간선에 대한 정보를 저장한다.
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    priority_queue<pair<int, int>> q;
    vector<pair<int, int>> cost(n + 1, {987654321, -1});
    cost[1] = {0, 0};
    q.push({0, 1});

    while(!q.empty()){
        // 일반적인 다익스트라 알고리즘을 돌린다.
        // 알고리즘 실행 간에, 이전 위치를 저장한다.
        int weight = -q.top().first, to = q.top().second;
        q.pop();

        if(cost[to].first < weight) continue;

        for(pair<int, int> tmp : edges[to]){
            int nextWeight = weight + tmp.second, nextTo = tmp.first;
            if(cost[nextTo].first > nextWeight){
                cost[nextTo].first = nextWeight;
                cost[nextTo].second = to;

                q.push({-nextWeight, nextTo});
            }
        }
    }

    stack<pair<int, int>> s; // 이전 위치, 현재 위치 정보를 가지고 어디에서 어디로 이동했는지 확인한다.
    for(int cur = n, pre = cost[n].second; cur != 1; cur = pre, pre = cost[pre].second){s.push({pre, cur});}

    int ans = 0;
    while(!s.empty()){ // 다익스트라를 통해 이동한 간선들을 하나씩 막으면서 다시 다익스트라를 돌린다.
        pair<int, int> tmp = s.top();
        s.pop();
        vector<int> cost2(n + 1, 987654321);
        q.push({0, 1});
        cost2[1] = 0;

        while(!q.empty()){
            int weight = -q.top().first, to = q.top().second;
            q.pop();

            if(cost2[to] < weight) continue;

            for(pair<int, int> edge : edges[to]){
                int nextWeight = weight + edge.second, nextTo = edge.first;
                // 막은 간선은 가지 못하게 설정한다.
                if((to == tmp.first || to == tmp.second) && (nextTo == tmp.first || nextTo == tmp.second)) continue;

                if(cost2[nextTo] > nextWeight){
                    cost2[nextTo] = nextWeight;
                    q.push({-nextWeight, nextTo});
                }
            }
        }

        // 도착지점에 갈 수 없도록 막을 수 있다면 결과는 -1로 수렴
        if(cost2[n] == 987654321) {ans = -1; break;}
        // 막았을 때 조금이라도 시간을 더 늦출 수 있다면 ans에 저장한다.
        ans = max(ans, cost2[n] - cost[n].first);
    }

    cout << ans << "\n";

    return 0;
}