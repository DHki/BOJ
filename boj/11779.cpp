#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    for(int i = 0; i < m; i++){
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back({to, weight});
    }

    int start, end;
    cin >> start >> end;


    vector<int> dist(n + 1, INT_MAX);
    vector<int> prev(n + 1, 0);
    dist[start] = 0; prev[start] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;
    for(pair<int, int> tmp : adj[start]){
        pq.push({-tmp.second, {start, tmp.first}});
    }

    while (!pq.empty())
    {
        int weight = -pq.top().first, from = pq.top().second.first, to = pq.top().second.second;
        pq.pop();

        if(dist[from] + weight < dist[to]){
            dist[to] = dist[from] + weight;
            prev[to] = from;

            for(pair<int, int> tmp : adj[to]){
                pq.push({-tmp.second, {to, tmp.first}});
            }
        }
    }
    
    cout << dist[end] << "\n";

    stack<int> ans;
    for(int curr = end; curr != 0; curr = prev[curr]){
        ans.push(curr);
    }

    cout << ans.size() << "\n";
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    cout << "\n";

    return 0;
}