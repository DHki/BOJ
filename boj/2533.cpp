#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001][2];
vector<int> adj[1000001];
vector<bool> visit(1000001, false);

void dfs(int curr){
    visit[curr] = true;

    dp[curr][0] = 0;
    dp[curr][1] = 1;

    for(int next : adj[curr]){
        if(visit[next]) continue;

        dfs(next);

        dp[curr][0] += dp[next][1];
        dp[curr][1] += min(dp[next][0], dp[next][1]);
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << "\n";
    
    return 0;
}