#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        int n, m;
        cin >> n >> m;

        if(n == 0 && m == 0) break;

        vector<pair<int, int>> edges[n]; int price = 0;
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            price += c;

            edges[a].push_back({b, c});
            edges[b].push_back({a, c});
        }

        priority_queue<pair<int, int>> q;
        for(pair<int, int> edge : edges[0]) q.push({-edge.second, edge.first});


        vector<bool> visit(n + 1, false); int sum = 0;
        visit[0] = true;
        while(!q.empty()){
            pair<int, int> tmp = q.top();
            q.pop();

            int weight = -tmp.first, to = tmp.second;

            if(visit[to]) continue;

            visit[to] = true; sum += weight;
            for(pair<int, int> next : edges[to]){
                if(visit[next.first]) continue;

                q.push({-next.second, next.first});
            }
        }

        cout << price - sum << "\n";
    }

    return 0;
}