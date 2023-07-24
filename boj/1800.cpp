#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p, k;
    cin >> n >> p >> k;

    vector<pair<int, int>> adj[n + 1]; // <목적지, 비용>
    for(int i = 0; i < p; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int start = 0, end = 10000000, ans = -1;
    while(start <= end){ // 이분 탐색으로 내야하는 금액의 기준을 정해본다.
        int mid = (start + end) / 2;

        vector<int> cost(n + 1, 987654321);
        cost[1] = 0;

        priority_queue<pair<int, int>> q;
        q.push({0, 1});

        while(!q.empty()){
            // 다익스트라 실행. 낼 수 있는 금액보다 간선의 금액이 더 크면 해당 간선의 비용을 1로 설정
            // 갯수를 확인해서, 해당 갯수만큼을 회사에서 내줄 수 있는지 확인할 예정이다.

            int weight = -q.top().first, node = q.top().second;
            q.pop();

            if(cost[node] < weight) continue;

            for(pair<int, int> tmp : adj[node]){
                int nextWeight = (tmp.second > mid) + weight;
                int nextNode = tmp.first;

                if(cost[nextNode] > nextWeight){
                    cost[nextNode] = nextWeight;
                    q.push({-nextWeight, nextNode});
                }
            }
        }

        if(cost[n] <= k){
            end = mid - 1;
            ans = mid;
        }
        else{
            start = mid + 1;
        }

    }

    cout << ans << "\n";
    return 0;
}