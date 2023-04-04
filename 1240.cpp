#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int findAnswer(const vector<pair<int, int>> adj[], int start, int end, int n){
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(pair<int, int> tmp : adj[curr]){
            int next = tmp.first;
            int weight = tmp.second;

            if(dist[next] > dist[curr] + weight){
                dist[next] = dist[curr] + weight;
                q.push(next);
            }

            if(next == end) break;
        }
    }

    return dist[end];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    for(int i = 1; i < n; i++){
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;

        cout << findAnswer(adj, start, end, n) << "\n";
    }

    return 0;
}