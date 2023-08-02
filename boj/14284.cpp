#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;

    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int s, t;
    cin >> s >> t;

    priority_queue<pair<int, int>> q;
    vector<int> cost(n + 1, 987654321);

    q.push({0, s});
    cost[s] = 0;

    while(!q.empty()){
        int weight = -q.top().first, to = q.top().second;
        q.pop();

        if(cost[to] < weight) continue;
        for(pair<int, int> tmp : adj[to]){
            int nextWeight = weight + tmp.second, nextTo = tmp.first;
            
            if(cost[nextTo] > nextWeight){
                cost[nextTo] = nextWeight;
                q.push({-nextWeight, nextTo});
            }
        }
    }

    cout << cost[t] << "\n";
    return 0;
}