#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool findAnswer(const vector<pair<int, int>> arr, int n){
    // index : 0 -> 시작점, n + 1 -> 목적지
    vector<int> adj[n + 1];

    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 2; j++){
            if(i == j) continue;
            
            int dist = abs(arr[j].first - arr[i].first) + abs(arr[j].second - arr[i].second);
            if( dist <= 1000){
                adj[i].push_back(j);
            }
        }
    }

    queue<int> q;
    vector<bool> visit(n + 1, false);

    q.push(0);
    visit[0] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int next : adj[curr]){
            if(next == n + 1) return true;

            if(!visit[next]){
                visit[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<pair<int, int>> arr(n + 2);
        for(int i = 0; i < n + 2; i++){
            cin >> arr[i].first >> arr[i].second;
        }

        if(findAnswer(arr, n)){
            cout << "happy\n";
        }
        else{
            cout << "sad\n";
        }
    }

    return 0;
}